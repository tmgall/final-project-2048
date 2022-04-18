#include "game_state.h"
#include <iostream>

namespace game {

using glm::vec2;

GameState::GameState() : GameState(kDefaultWindowWidth, kDefaultWindowHeight,
                                   kDefaultMargin, kDefaultBoardSize,kDefaultSquareWidth,
                                   kDefaultInfoHeight, kDefaultKeyOverlayW,
                                   kDefaultKeyOverlayH) {}

GameState::GameState(size_t window_width, size_t window_height, size_t margin, size_t board_size, size_t square_width,
                     size_t info_height, size_t key_overlay_w, size_t key_overlay_h) {
  window_width_ = window_width;
  window_height_ = window_height;
  margin_ = margin;
  board_size_ = board_size;
  square_width_ = square_width;
  info_height_ = info_height;
  key_overlay_w_ = key_overlay_w;
  key_overlay_h_ = key_overlay_h;
  tiles_ = vector<ci::Rectf>();
  for (size_t i = 0; i < board_size_; i++) {
    for (size_t j = 0; j < board_size_; j++) {
      vec2 top_left(margin_ + square_width_ * i, info_height_ + square_width_ * j);
      vec2 bottom_right(margin_ + square_width_ * (i + 1), info_height_ + square_width_ * (j + 1));
      tiles_.emplace_back(ci::Rectf(top_left, bottom_right));
    }
  }
  tile_values_ = vector<vector<size_t>>(board_size_, vector<size_t>(board_size_, 0));
  srand((unsigned int) time(NULL));
  size_t rand1 = 0;
  size_t rand2 = 0;
  while (rand1 == rand2) {
    rand1 = rand() % (board_size_ * board_size_);
    rand2 = rand() % (board_size_ * board_size_);
  }
  bool four1 = (rand() % kFourChanceRatio) == 0;
  bool four2 = (rand() % kFourChanceRatio) == 0;
  if (four1) {
    tile_values_[rand1 % board_size][rand1 / board_size_] = 4;
  } else {
    tile_values_[rand1 % board_size][rand1 / board_size_] = 2;
  }
  if (four2) {
    tile_values_[rand2 % board_size][rand2 / board_size_] = 4;
  } else {
    tile_values_[rand2 % board_size][rand2 / board_size_] = 2;
  }
  score = 0;
}

void GameState::Display() const {
  ci::gl::color(ci::Color("white"));
  for (const ci::Rectf& tile : tiles_) {
    ci::gl::drawStrokedRect(tile);
  }
  for (size_t i = 0; i < board_size_; i++) {
    for (size_t j = 0; j < board_size_; j++) {
      size_t x_pos = margin_ + j * square_width_ + square_width_ / 2;
      size_t y_pos = info_height_ + i * square_width_ + square_width_ / 3;
      std::string value;
      if (tile_values_[i][j] != 0) {
        value = std::to_string(tile_values_[i][j]);
      }
      DrawText(value, vec2(x_pos, y_pos));
    }
  }
  DrawText("Score: " + std::to_string(score), vec2(window_width_ / 2, 20));
}

void GameState::DrawText(const std::string& text, const vec2& pos) const {
  static ci::Font f("roboto regular", 160);
  ci::gl::drawStringCentered(text, pos, ci::Color("white"), f);
}

void GameState::SetBoardDimension(size_t board_size) {
  board_size_ = board_size;
  square_width_ = (window_width_ - 2 * margin_) / board_size;
  for (size_t i = 0; i < board_size_; i++) {
    for (size_t j = 0; j < board_size_; j++) {
      vec2 top_left(margin_ + square_width_ * i, info_height_ + square_width_ * j);
      vec2 bottom_right(margin_ + square_width_ * (i + 1), info_height_ + square_width_ * (j + 1));
      tiles_.emplace_back(ci::Rectf(top_left, bottom_right));
    }
  }
}

void GameState::UpdateState(GameState::Input input) {
  bool board_changed = true;
  if (input == right) {
    board_changed = MoveRight();
  } else if (input == left) {
    board_changed = MoveLeft();
  } else if (input == up) {
    board_changed = MoveUp();
  } else if (input == down) {
    board_changed = MoveDown();
  }
  if (board_changed) {
    AddRandomNumberToBoard();
  }
}

bool GameState::MoveRight() {
  bool board_changed = false;
  for (int row = 0; row < (int) board_size_; row++) {
    size_t next_col_spot = board_size_ - 1;
    size_t last_val = 0;
    for (int col = (int) (board_size_ - 1); col >= 0; col--) {
      size_t cur_val = tile_values_[row][col];
      if (cur_val != 0) {
        if (cur_val == last_val) {
          tile_values_[row][next_col_spot + 1] = last_val * 2;
          score += last_val * 2;
          tile_values_[row][col] = 0;
          last_val = 0;
          board_changed = true;
        } else {
          last_val = cur_val;
          tile_values_[row][next_col_spot] = cur_val;
          if (col != next_col_spot) {
            board_changed = true;
            tile_values_[row][col] = 0;
          }
          next_col_spot--;
        }
      }
    }
  }
  return board_changed;
}

bool GameState::MoveLeft() {
  bool board_changed = false;
  for (int row = 0; row < (int) board_size_; row++) {
    size_t next_col_spot = 0;
    size_t last_val = 0;
    for (int col = 0; col < (int) board_size_; col++) {
      size_t cur_val = tile_values_[row][col];
      if (cur_val != 0) {
        if (cur_val == last_val) {
          tile_values_[row][next_col_spot - 1] = last_val * 2;
          score += last_val * 2;
          tile_values_[row][col] = 0;
          last_val = 0;
          board_changed = true;
        } else {
          last_val = cur_val;
          tile_values_[row][next_col_spot] = cur_val;
          if (col != next_col_spot) {
            board_changed = true;
            tile_values_[row][col] = 0;
          }
          next_col_spot++;
        }
      }
    }
  }
  return board_changed;
}

bool GameState::MoveUp() {
  bool board_changed = false;
  for (int col = 0; col < (int) board_size_; col++) {
    size_t next_row_spot = 0;
    size_t last_val = 0;
    for (int row = 0; row < (int) board_size_; row++) {
      size_t cur_val = tile_values_[row][col];
      if (cur_val != 0) {
        if (cur_val == last_val) {
          tile_values_[next_row_spot - 1][col] = last_val * 2;
          score += last_val * 2;
          tile_values_[row][col] = 0;
          last_val = 0;
          board_changed = true;
        } else {
          last_val = cur_val;
          tile_values_[next_row_spot][col] = cur_val;
          if (row != next_row_spot) {
            board_changed = true;
            tile_values_[row][col] = 0;
          }
          next_row_spot++;
        }
      }
    }
  }
  return board_changed;
}

bool GameState::MoveDown() {
  bool board_changed = false;
  for (int col = 0; col < (int) board_size_; col++) {
    size_t next_row_spot = board_size_ - 1;
    size_t last_val = 0;
    for (int row = (int) (board_size_ - 1); row >= 0; row--) {
      size_t cur_val = tile_values_[row][col];
      if (cur_val != 0) {
        if (cur_val == last_val) {
          tile_values_[next_row_spot + 1][col] = last_val * 2;
          score += last_val * 2;
          tile_values_[row][col] = 0;
          last_val = 0;
          board_changed = true;
        } else {
          last_val = cur_val;
          tile_values_[next_row_spot][col] = cur_val;
          if (row != next_row_spot) {
            board_changed = true;
            tile_values_[row][col] = 0;
          }
          next_row_spot--;
        }
      }
    }
  }
  return board_changed;
}

void GameState::AddRandomNumberToBoard() {
  vector<std::pair<size_t, size_t>> available_spots;
  for (size_t i = 0; i < board_size_; i++) {
    for (size_t j = 0; j < board_size_; j++) {
      if (tile_values_[i][j] == 0) {
        available_spots.emplace_back(std::make_pair(i, j));
      }
    }
  }
  std::pair<size_t, size_t> pos = available_spots[rand() % available_spots.size()];
  bool four = (rand() % kFourChanceRatio) == 0;
  if (four) {
    tile_values_[pos.first][pos.second] = 4;
  } else {
    tile_values_[pos.first][pos.second] = 2;
  }
}

}  // namespace game
