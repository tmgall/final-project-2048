#include "game_state.h"

namespace game {

using glm::vec2;

GameState::GameState(size_t window_width, size_t margin, size_t info_height) :
    window_width_(window_width), margin_(margin), info_height_(info_height), board_size_(0), square_width_(0),
    score_(0), finished_(false), in_menu_(true), tiles_(vector<ci::Rectf>()) {
}

void GameState::Display() const {
  if (in_menu_) {
    DisplayMenu();
  } else {
    for (size_t i = 0; i < board_size_; i++) {
      for (size_t j = 0; j < board_size_; j++) {
        ci::gl::color(ci::Color(0.2f, 0.2f, 0.2f));
        ci::gl::drawStrokedRect(tiles_[j * board_size_ + i]);
        ci::gl::color(GetTileColor(tile_values_[i][j]));
        ci::gl::drawSolidRect(tiles_[j * board_size_ + i]);
      }
    }
    for (size_t i = 0; i < board_size_; i++) {
      for (size_t j = 0; j < board_size_; j++) {
        size_t x_pos = margin_ + j * square_width_ + square_width_ / 2;
        size_t y_pos = info_height_ + i * square_width_ + square_width_ / 3;
        std::string value;
        if (tile_values_[i][j] != 0) {
          value = std::to_string(tile_values_[i][j]);
        }
        int offset = board_size_ == 2 ? 50 : (board_size_ == 3 ? 20 : (board_size_ == 4 ? 0 : -15));
        DrawText(value, vec2(x_pos, offset + y_pos));
      }
    }
    DrawText("Score: " + std::to_string(score_), vec2(window_width_ / 2, 20));
    if (finished_) {
      DrawText("Game Over", vec2(window_width_ / 2, 200));
    }
  }
}

void GameState::ExecuteInput(GameState::Input input) {
  bool board_changed = UpdateState(input);
  if (board_changed) {
    AddRandomNumberToBoard();
  }
  if (GameFinished()) {
    finished_ = true;
  }
}

bool GameState::UpdateState(GameState::Input input) {
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
  return board_changed;
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
          score_ += last_val * 2;
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
          score_ += last_val * 2;
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
          score_ += last_val * 2;
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
          score_ += last_val * 2;
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

void GameState::DrawText(const std::string& text, const vec2& pos) {
  static ci::Font f("roboto regular", 160);
  ci::gl::drawStringCentered(text, pos, ci::Color(0.2f, 0.2f, 0.2f), f);
}

ci::Color GameState::GetTileColor(size_t val) {
  if (val == 0) {
    return {0.92f, 0.83f, 0.2f};
  } else if ((val & (val - 1)) != 0) {
    return {0.92f, 0.0f, 0.2f};
  } else {
    double power = log(val) / log(2);
    return {0.92f, (float) (0.83f - 0.05 * power), 0.2f};
  }
}

bool GameState::GameFinished() {
  for (int i = 0; i < (int) board_size_; i++) {
    for (int j = 0; j < (int) board_size_; j++) {
      size_t cur_val = tile_values_[i][j];
      if (cur_val == 0) {
        return false;
      } else if (i > 0 && tile_values_[i - 1][j] == cur_val) {
        return false;
      } else if (i < (int) (board_size_ - 1) && tile_values_[i + 1][j] == cur_val) {
        return false;
      } else if (j > 0 && tile_values_[i][j - 1] == cur_val) {
        return false;
      } else if (j < (int) (board_size_ - 1) && tile_values_[i][j + 1] == cur_val) {
        return false;
      }
    }
  }
  return true;
}

void GameState::DisplayMenu() const {
  DrawText("2048", vec2(window_width_ / 2, 20));
  DrawText("By Tyler Gall", vec2(window_width_ / 2, 200));
  ci::gl::color(ci::Color(0.92f, 0.83f, 0.2f));
  ci::gl::drawSolidRect(ci::Rectf(vec2(50, 400), vec2(750, 1100)));
  ci::gl::color(ci::Color(0.92f, 0.63f, 0.2f));
  ci::gl::drawSolidRect(ci::Rectf(vec2(750, 400), vec2(1450, 1100)));
  ci::gl::color(ci::Color(0.92f, 0.43f, 0.2f));
  ci::gl::drawSolidRect(ci::Rectf(vec2(50, 1100), vec2(750, 1800)));
  ci::gl::color(ci::Color(0.92f, 0.23f, 0.2f));
  ci::gl::drawSolidRect(ci::Rectf(vec2(750, 1100), vec2(1450, 1800)));
  DrawText("2x2", vec2(400, 650));
  DrawText("press left", vec2(400, 750));
  DrawText("3x3", vec2(1100, 650));
  DrawText("press right", vec2(1100, 750));
  DrawText("4x4", vec2(400, 1350));
  DrawText("press down", vec2(400, 1450));
  DrawText("5x5", vec2(1100, 1350));
  DrawText("press up", vec2(1100, 1450));
}

void GameState::SelectGame(size_t board_size) {
  board_size_ = board_size;
  square_width_ = (window_width_ - 2 * margin_) / board_size;
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
    tile_values_[rand1 % board_size_][rand1 / board_size_] = 4;
  } else {
    tile_values_[rand1 % board_size_][rand1 / board_size_] = 2;
  }
  if (four2) {
    tile_values_[rand2 % board_size_][rand2 / board_size_] = 4;
  } else {
    tile_values_[rand2 % board_size_][rand2 / board_size_] = 2;
  }
}

}  // namespace game
