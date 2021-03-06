#include <catch2/catch.hpp>

#include <game_state.h>
#include <game_app.h>

using game::GameState;
using game::GameApp;

bool BoardsEqual(const vector<vector<size_t>>& b1, const vector<vector<size_t>>& b2) {
  if (b1.size() != b2.size()) {
    return false;
  }
  if (b1.empty()) {
    return true;
  }
  if (b1[0].size() != b2[0].size()) {
    return false;
  }
  for (size_t i = 0; i < b1.size(); i++) {
    for (size_t j = 0; j < b1[0].size(); j++) {
      if (b1[i][j] != b2[i][j]) {
        return false;
      }
    }
  }
  return true;
}

TEST_CASE("GameState SelectGame initializes proper values") {
  size_t board_size = 2;
  GameState gs2(1500, 50, 400);
  gs2.SelectGame(board_size);
  SECTION("Correct initial values") {
    size_t first_val = 0;
    size_t second_val = 0;
    size_t nonzero_vals = 0;
    for (size_t i = 0; i < board_size; i++) {
      for (size_t j = 0; j < board_size; j++) {
        if (gs2.tile_values_[i][j] != 0) {
          nonzero_vals++;
          if (first_val == 0) {
            first_val = gs2.tile_values_[i][j];
          } else {
            second_val = gs2.tile_values_[i][j];
          }
        }
      }
    }
    REQUIRE((first_val == 2 || first_val == 4));
    REQUIRE((second_val == 2 || second_val == 4));
    REQUIRE(nonzero_vals == 2);
  }
  SECTION("Correct rectangle locations and square width for 2x2 display") {
    vector<size_t> correct_x1s = {50, 50, 750, 750};
    vector<size_t> correct_x2s = {750, 750, 1450, 1450};
    vector<size_t> correct_y1s = {400, 1100, 400, 1100};
    vector<size_t> correct_y2s = {1100, 1800, 1100, 1800};
    for (size_t i = 0; i < board_size * board_size; i++) {
      REQUIRE(gs2.tiles_[i].x1 == correct_x1s[i]);
      REQUIRE(gs2.tiles_[i].x2 == correct_x2s[i]);
      REQUIRE(gs2.tiles_[i].y1 == correct_y1s[i]);
      REQUIRE(gs2.tiles_[i].y2 == correct_y2s[i]);
    }
  }
  board_size = 3;
  GameState gs3(1500, 50, 400);
  gs3.SelectGame(board_size);
  SECTION("Correct rectangle locations and square width for 3x3 display") {
    vector<size_t> correct_x1s = {50, 50, 50, 516, 516, 516, 982, 982, 982};
    vector<size_t> correct_x2s = {516, 516, 516, 982, 982, 982, 1448, 1448, 1448};
    vector<size_t> correct_y1s = {400, 866, 1332, 400, 866, 1332, 400, 866, 1332};
    vector<size_t> correct_y2s = {866, 1332, 1798, 866, 1332, 1798, 866, 1332, 1798};
    for (size_t i = 0; i < board_size * board_size; i++) {
      REQUIRE(gs3.tiles_[i].x1 == correct_x1s[i]);
      REQUIRE(gs3.tiles_[i].x2 == correct_x2s[i]);
      REQUIRE(gs3.tiles_[i].y1 == correct_y1s[i]);
      REQUIRE(gs3.tiles_[i].y2 == correct_y2s[i]);
    }
  }
  board_size = 4;
  GameState gs4(1500, 50, 400);
  gs4.SelectGame(board_size);
  SECTION("Correct rectangle locations and square width for 4x4 display") {
    vector<size_t> correct_x1s = {50, 50, 50, 50, 400, 400, 400, 400,
                                  750, 750, 750, 750, 1100, 1100, 1100, 1100};
    vector<size_t> correct_x2s = {400, 400, 400, 400, 750, 750, 750, 750,
                                  1100, 1100, 1100, 1100, 1450, 1450, 1450, 1450};
    vector<size_t> correct_y1s = {400, 750, 1100, 1450, 400, 750, 1100, 1450,
                                  400, 750, 1100, 1450, 400, 750, 1100, 1450};
    vector<size_t> correct_y2s = {750, 1100, 1450, 1800, 750, 1100, 1450, 1800,
                                  750, 1100, 1450, 1800, 750, 1100, 1450, 1800};
    for (size_t i = 0; i < board_size * board_size; i++) {
      REQUIRE(gs4.tiles_[i].x1 == correct_x1s[i]);
      REQUIRE(gs4.tiles_[i].x2 == correct_x2s[i]);
      REQUIRE(gs4.tiles_[i].y1 == correct_y1s[i]);
      REQUIRE(gs4.tiles_[i].y2 == correct_y2s[i]);
    }
  }
  board_size = 5;
  GameState gs5(1500, 50, 400);
  gs5.SelectGame(board_size);
  SECTION("Correct rectangle locations and square width for 5x5 display") {
    vector<size_t> correct_x1s = {50, 50, 50, 50, 50, 330, 330, 330, 330, 330, 610, 610, 610, 610, 610,
                                  890, 890, 890, 890, 890, 1170, 1170, 1170, 1170, 1170};
    vector<size_t> correct_x2s = {330, 330, 330, 330, 330, 610, 610, 610, 610, 610, 890, 890, 890, 890, 890,
                                  1170, 1170, 1170, 1170, 1170, 1450, 1450, 1450, 1450, 1450};
    vector<size_t> correct_y1s = {400, 680, 960, 1240, 1520, 400, 680, 960, 1240, 1520, 400, 680, 960, 1240, 1520,
                                  400, 680, 960, 1240, 1520, 400, 680, 960, 1240, 1520};
    vector<size_t> correct_y2s = {680, 960, 1240, 1520, 1800, 680, 960, 1240, 1520, 1800, 680, 960, 1240, 1520, 1800,
                                  680, 960, 1240, 1520, 1800, 680, 960, 1240, 1520, 1800};
    for (size_t i = 0; i < board_size * board_size; i++) {
      REQUIRE(gs5.tiles_[i].x1 == correct_x1s[i]);
      REQUIRE(gs5.tiles_[i].x2 == correct_x2s[i]);
      REQUIRE(gs5.tiles_[i].y1 == correct_y1s[i]);
      REQUIRE(gs5.tiles_[i].y2 == correct_y2s[i]);
    }
  }
}

TEST_CASE("GameState UpdateState updates right move board correctly") {
  size_t board_size = 4;
  GameState gs(1500, 50, 400);
  gs.SelectGame(board_size);
  SECTION("Single tile shifts right") {
    gs.tile_values_ = {{2, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    bool board_changed = gs.UpdateState(GameState::right);
    vector<vector<size_t>> expected = {{0, 0, 0, 2}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    REQUIRE(BoardsEqual(gs.tile_values_, expected));
    REQUIRE(board_changed);
  }
  SECTION("Multiple tiles shift right") {
    gs.tile_values_ = {{2, 0, 4, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    bool board_changed = gs.UpdateState(GameState::right);
    vector<vector<size_t>> expected = {{0, 0, 2, 4}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    REQUIRE(BoardsEqual(gs.tile_values_, expected));
    REQUIRE(board_changed);
  }
  SECTION("All rows shift right") {
    gs.tile_values_ = {{2, 0, 0, 0}, {0, 4, 0, 0}, {0, 0, 8, 0}, {0, 0, 0, 16}};
    bool board_changed = gs.UpdateState(GameState::right);
    vector<vector<size_t>> expected = {{0, 0, 0, 2}, {0, 0, 0, 4}, {0, 0, 0, 8}, {0, 0, 0, 16}};
    REQUIRE(BoardsEqual(gs.tile_values_, expected));
    REQUIRE(board_changed);
  }
  SECTION("Two equal tiles combine right") {
    gs.tile_values_ = {{0, 0, 8, 8}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    bool board_changed = gs.UpdateState(GameState::right);
    vector<vector<size_t>> expected = {{0, 0, 0, 16}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    REQUIRE(BoardsEqual(gs.tile_values_, expected));
    REQUIRE(board_changed);
  }
  SECTION("Two equal tiles combine plus extra tile shifted right") {
    gs.tile_values_ = {{4, 8, 0, 8}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    bool board_changed = gs.UpdateState(GameState::right);
    vector<vector<size_t>> expected = {{0, 0, 4, 16}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    REQUIRE(BoardsEqual(gs.tile_values_, expected));
    REQUIRE(board_changed);
  }
  SECTION("Two equal tiles separated by different tile do not combine right") {
    gs.tile_values_ = {{8, 4, 0, 8}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    bool board_changed = gs.UpdateState(GameState::right);
    vector<vector<size_t>> expected = {{0, 8, 4, 8}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    REQUIRE(BoardsEqual(gs.tile_values_, expected));
    REQUIRE(board_changed);
  }
  SECTION("Multiple tiles combine right") {
    gs.tile_values_ = {{8, 8, 4, 4}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    bool board_changed = gs.UpdateState(GameState::right);
    vector<vector<size_t>> expected = {{0, 0, 16, 8}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    REQUIRE(BoardsEqual(gs.tile_values_, expected));
    REQUIRE(board_changed);
  }
  SECTION("Board that does not change with input does not register as board changing right") {
    gs.tile_values_ = {{8, 4, 8, 4}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    bool board_changed = gs.UpdateState(GameState::right);
    vector<vector<size_t>> expected = {{8, 4, 8, 4}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    REQUIRE(BoardsEqual(gs.tile_values_, expected));
    REQUIRE(board_changed == false);
  }
}

TEST_CASE("GameState UpdateState updates score correctly right move") {
  size_t board_size = 4;
  GameState gs(1500, 50, 400);
  gs.SelectGame(board_size);
  SECTION("Single score update right") {
    gs.tile_values_ = {{2, 2, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    gs.UpdateState(GameState::right);
    REQUIRE(gs.score_ == 4);
  }
  SECTION("Several score updates right") {
    gs.tile_values_ = {{2, 2, 0, 0}, {0, 0, 16, 16}, {4, 0, 4, 0}, {0, 256, 0, 256}};
    gs.UpdateState(GameState::right);
    REQUIRE(gs.score_ == 556);
  }
}

TEST_CASE("GameState UpdateState updates left move board correctly") {
  size_t board_size = 4;
  GameState gs(1500, 50, 400);
  gs.SelectGame(board_size);
  SECTION("Single tile shifts left") {
    gs.tile_values_ = {{0, 0, 0, 2}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    bool board_changed = gs.UpdateState(GameState::left);
    vector<vector<size_t>> expected = {{2, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    REQUIRE(BoardsEqual(gs.tile_values_, expected));
    REQUIRE(board_changed);
  }
  SECTION("Multiple tiles shift left") {
    gs.tile_values_ = {{0, 4, 0, 2}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    bool board_changed = gs.UpdateState(GameState::left);
    vector<vector<size_t>> expected = {{4, 2, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    REQUIRE(BoardsEqual(gs.tile_values_, expected));
    REQUIRE(board_changed);
  }
  SECTION("All rows shift left") {
    gs.tile_values_ = {{2, 0, 0, 0}, {0, 4, 0, 0}, {0, 0, 8, 0}, {0, 0, 0, 16}};
    bool board_changed = gs.UpdateState(GameState::left);
    vector<vector<size_t>> expected = {{2, 0, 0, 0}, {4, 0, 0, 0}, {8, 0, 0, 0}, {16, 0, 0, 0}};
    REQUIRE(BoardsEqual(gs.tile_values_, expected));
    REQUIRE(board_changed);
  }
  SECTION("Two equal tiles combine left") {
    gs.tile_values_ = {{8, 8, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    bool board_changed = gs.UpdateState(GameState::left);
    vector<vector<size_t>> expected = {{16, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    REQUIRE(BoardsEqual(gs.tile_values_, expected));
    REQUIRE(board_changed);
  }
  SECTION("Two equal tiles combine plus extra tile shifted left") {
    gs.tile_values_ = {{4, 8, 0, 8}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    bool board_changed = gs.UpdateState(GameState::left);
    vector<vector<size_t>> expected = {{4, 16, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    REQUIRE(BoardsEqual(gs.tile_values_, expected));
    REQUIRE(board_changed);
  }
  SECTION("Two equal tiles separated by different tile do not combine left") {
    gs.tile_values_ = {{8, 4, 0, 8}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    bool board_changed = gs.UpdateState(GameState::left);
    vector<vector<size_t>> expected = {{8, 4, 8, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    REQUIRE(BoardsEqual(gs.tile_values_, expected));
    REQUIRE(board_changed);
  }
  SECTION("Multiple tiles combine left") {
    gs.tile_values_ = {{8, 8, 4, 4}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    bool board_changed = gs.UpdateState(GameState::left);
    vector<vector<size_t>> expected = {{16, 8, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    REQUIRE(BoardsEqual(gs.tile_values_, expected));
    REQUIRE(board_changed);
  }
  SECTION("Board that does not change with input does not register as board changing left") {
    gs.tile_values_ = {{8, 4, 8, 4}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    bool board_changed = gs.UpdateState(GameState::left);
    vector<vector<size_t>> expected = {{8, 4, 8, 4}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    REQUIRE(BoardsEqual(gs.tile_values_, expected));
    REQUIRE(board_changed == false);
  }
}

TEST_CASE("GameState UpdateState updates score correctly left move") {
  size_t board_size = 4;
  GameState gs(1500, 50, 400);
  gs.SelectGame(board_size);
  SECTION("Single score update left") {
    gs.tile_values_ = {{2, 2, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    gs.UpdateState(GameState::left);
    REQUIRE(gs.score_ == 4);
  }
  SECTION("Several score updates left") {
    gs.tile_values_ = {{2, 2, 0, 0}, {0, 0, 16, 16}, {4, 0, 4, 0}, {0, 256, 0, 256}};
    gs.UpdateState(GameState::left);
    REQUIRE(gs.score_ == 556);
  }
}

TEST_CASE("GameState UpdateState updates down move board correctly") {
  size_t board_size = 4;
  GameState gs(1500, 50, 400);
  gs.SelectGame(board_size);
  SECTION("Single tile shifts down") {
    gs.tile_values_ = {{2, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    bool board_changed = gs.UpdateState(GameState::down);
    vector<vector<size_t>> expected = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {2, 0, 0, 0}};
    REQUIRE(BoardsEqual(gs.tile_values_, expected));
    REQUIRE(board_changed);
  }
  SECTION("Multiple tiles shift down") {
    gs.tile_values_ = {{2, 0, 0, 0}, {4, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    bool board_changed = gs.UpdateState(GameState::down);
    vector<vector<size_t>> expected = {{0, 0, 0, 0}, {0, 0, 0, 0}, {2, 0, 0, 0}, {4, 0, 0, 0}};
    REQUIRE(BoardsEqual(gs.tile_values_, expected));
    REQUIRE(board_changed);
  }
  SECTION("All columns shift down") {
    gs.tile_values_ = {{2, 0, 0, 0}, {0, 4, 0, 0}, {0, 0, 8, 0}, {0, 0, 0, 16}};
    bool board_changed = gs.UpdateState(GameState::down);
    vector<vector<size_t>> expected = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {2, 4, 8, 16}};
    REQUIRE(BoardsEqual(gs.tile_values_, expected));
    REQUIRE(board_changed);
  }
  SECTION("Two equal tiles combine down") {
    gs.tile_values_ = {{8, 0, 0, 0}, {8, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    bool board_changed = gs.UpdateState(GameState::down);
    vector<vector<size_t>> expected = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {16, 0, 0, 0}};
    REQUIRE(BoardsEqual(gs.tile_values_, expected));
    REQUIRE(board_changed);
  }
  SECTION("Two equal tiles combine plus extra tile shifted down") {
    gs.tile_values_ = {{4, 0, 0, 0}, {8, 0, 0, 0}, {0, 0, 0, 0}, {8, 0, 0, 0}};
    bool board_changed = gs.UpdateState(GameState::down);
    vector<vector<size_t>> expected = {{0, 0, 0, 0}, {0, 0, 0, 0}, {4, 0, 0, 0}, {16, 0, 0, 0}};
    REQUIRE(BoardsEqual(gs.tile_values_, expected));
    REQUIRE(board_changed);
  }
  SECTION("Two equal tiles separated by different tile do not combine down") {
    gs.tile_values_ = {{8, 0, 0, 0}, {4, 0, 0, 0}, {0, 0, 0, 0}, {8, 0, 0, 0}};
    bool board_changed = gs.UpdateState(GameState::down);
    vector<vector<size_t>> expected = {{0, 0, 0, 0}, {8, 0, 0, 0}, {4, 0, 0, 0}, {8, 0, 0, 0}};
    REQUIRE(BoardsEqual(gs.tile_values_, expected));
    REQUIRE(board_changed);
  }
  SECTION("Multiple tiles combine down") {
    gs.tile_values_ = {{8, 0, 0, 0}, {8, 0, 0, 0}, {4, 0, 0, 0}, {4, 0, 0, 0}};
    bool board_changed = gs.UpdateState(GameState::down);
    vector<vector<size_t>> expected = {{0, 0, 0, 0}, {0, 0, 0, 0}, {16, 0, 0, 0}, {8, 0, 0, 0}};
    REQUIRE(BoardsEqual(gs.tile_values_, expected));
    REQUIRE(board_changed);
  }
  SECTION("Board that does not change with input does not register as board changing down") {
    gs.tile_values_ = {{8, 0, 0, 0}, {4, 0, 0, 0}, {8, 0, 0, 0}, {4, 0, 0, 0}};
    bool board_changed = gs.UpdateState(GameState::down);
    vector<vector<size_t>> expected = {{8, 0, 0, 0}, {4, 0, 0, 0}, {8, 0, 0, 0}, {4, 0, 0, 0}};
    REQUIRE(BoardsEqual(gs.tile_values_, expected));
    REQUIRE(board_changed == false);
    REQUIRE(gs.score_ == 0);
  }
}

TEST_CASE("GameState UpdateState updates score correctly down move") {
  size_t board_size = 4;
  GameState gs(1500, 50, 400);
  gs.SelectGame(board_size);
  SECTION("Single score update down") {
    gs.tile_values_ = {{2, 0, 0, 0}, {2, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    gs.UpdateState(GameState::down);
    REQUIRE(gs.score_ == 4);
  }
  SECTION("Several score updates down") {
    gs.tile_values_ = {{2, 0, 4, 0}, {2, 0, 0, 256}, {0, 16, 4, 0}, {0, 16, 0, 256}};
    gs.UpdateState(GameState::down);
    REQUIRE(gs.score_ == 556);
  }
}

TEST_CASE("GameState UpdateState updates up move board correctly") {
  size_t board_size = 4;
  GameState gs(1500, 50, 400);
  gs.SelectGame(board_size);
  SECTION("Single tile shifts up") {
    gs.tile_values_ = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {2, 0, 0, 0}};
    bool board_changed = gs.UpdateState(GameState::up);
    vector<vector<size_t>> expected = {{2, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    REQUIRE(BoardsEqual(gs.tile_values_, expected));
    REQUIRE(board_changed);
  }
  SECTION("Multiple tiles shift up") {
    gs.tile_values_ = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 2, 0, 0}, {0, 4, 0, 0}};
    bool board_changed = gs.UpdateState(GameState::up);
    vector<vector<size_t>> expected = {{0, 2, 0, 0}, {0, 4, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    REQUIRE(BoardsEqual(gs.tile_values_, expected));
    REQUIRE(board_changed);
  }
  SECTION("All columns shift up") {
    gs.tile_values_ = {{2, 0, 0, 0}, {0, 4, 0, 0}, {0, 0, 8, 0}, {0, 0, 0, 16}};
    bool board_changed = gs.UpdateState(GameState::up);
    vector<vector<size_t>> expected = {{2, 4, 8, 16}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    REQUIRE(BoardsEqual(gs.tile_values_, expected));
    REQUIRE(board_changed);
  }
  SECTION("Two equal tiles combine up") {
    gs.tile_values_ = {{8, 0, 0, 0}, {8, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    bool board_changed = gs.UpdateState(GameState::up);
    vector<vector<size_t>> expected = {{16, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    REQUIRE(BoardsEqual(gs.tile_values_, expected));
    REQUIRE(board_changed);
  }
  SECTION("Two equal tiles combine plus extra tile shifted up") {
    gs.tile_values_ = {{4, 0, 0, 0}, {8, 0, 0, 0}, {0, 0, 0, 0}, {8, 0, 0, 0}};
    bool board_changed = gs.UpdateState(GameState::up);
    vector<vector<size_t>> expected = {{4, 0, 0, 0}, {16, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    REQUIRE(BoardsEqual(gs.tile_values_, expected));
    REQUIRE(board_changed);
  }
  SECTION("Two equal tiles separated by different tile do not combine up") {
    gs.tile_values_ = {{8, 0, 0, 0}, {4, 0, 0, 0}, {0, 0, 0, 0}, {8, 0, 0, 0}};
    bool board_changed = gs.UpdateState(GameState::up);
    vector<vector<size_t>> expected = {{8, 0, 0, 0}, {4, 0, 0, 0}, {8, 0, 0, 0}, {0, 0, 0, 0}};
    REQUIRE(BoardsEqual(gs.tile_values_, expected));
    REQUIRE(board_changed);
  }
  SECTION("Multiple tiles combine up") {
    gs.tile_values_ = {{8, 0, 0, 0}, {8, 0, 0, 0}, {4, 0, 0, 0}, {4, 0, 0, 0}};
    bool board_changed = gs.UpdateState(GameState::up);
    vector<vector<size_t>> expected = {{16, 0, 0, 0}, {8, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    REQUIRE(BoardsEqual(gs.tile_values_, expected));
    REQUIRE(board_changed);
  }
  SECTION("Board that does not change with input does not register as board changing up") {
    gs.tile_values_ = {{8, 0, 0, 0}, {4, 0, 0, 0}, {8, 0, 0, 0}, {4, 0, 0, 0}};
    bool board_changed = gs.UpdateState(GameState::up);
    vector<vector<size_t>> expected = {{8, 0, 0, 0}, {4, 0, 0, 0}, {8, 0, 0, 0}, {4, 0, 0, 0}};
    REQUIRE(BoardsEqual(gs.tile_values_, expected));
    REQUIRE(board_changed == false);
  }
}

TEST_CASE("GameState UpdateState updates score correctly up move") {
  size_t board_size = 4;
  GameState gs(1500, 50, 400);
  gs.SelectGame(board_size);
  SECTION("Single score update up") {
    gs.tile_values_ = {{2, 0, 0, 0}, {2, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    gs.UpdateState(GameState::up);
    REQUIRE(gs.score_ == 4);
  }
  SECTION("Several score updates up") {
    gs.tile_values_ = {{2, 0, 4, 0}, {2, 0, 0, 256}, {0, 16, 4, 0}, {0, 16, 0, 256}};
    gs.UpdateState(GameState::up);
    REQUIRE(gs.score_ == 556);
  }
}

TEST_CASE("Random new number updates correctly using ExecuteInput") {
  size_t board_size = 4;
  GameState gs(1500, 50, 400);
  gs.SelectGame(board_size);
  SECTION("Board updates right") {
    gs.tile_values_ = {{2, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    gs.ExecuteInput(GameState::right);
    bool found_new_val = false;
    for (size_t i = 0; i < board_size; i++) {
      for (size_t j = 0; j < board_size; j++) {
        if ((i != 0 || j != 3) && gs.tile_values_[i][j] != 0) {
          REQUIRE(found_new_val == false);
          REQUIRE((gs.tile_values_[i][j] == 2 || gs.tile_values_[i][j] == 4));
          found_new_val = true;
        }
      }
    }
    REQUIRE(found_new_val);
  }
  SECTION("Board updates left") {
    gs.tile_values_ = {{0, 0, 0, 2}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    gs.ExecuteInput(GameState::left);
    bool found_new_val = false;
    for (size_t i = 0; i < board_size; i++) {
      for (size_t j = 0; j < board_size; j++) {
        if ((i != 0 || j != 0) && gs.tile_values_[i][j] != 0) {
          REQUIRE(found_new_val == false);
          REQUIRE((gs.tile_values_[i][j] == 2 || gs.tile_values_[i][j] == 4));
          found_new_val = true;
        }
      }
    }
    REQUIRE(found_new_val);
  }
  SECTION("Board updates down") {
    gs.tile_values_ = {{0, 0, 0, 2}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    gs.ExecuteInput(GameState::down);
    bool found_new_val = false;
    for (size_t i = 0; i < board_size; i++) {
      for (size_t j = 0; j < board_size; j++) {
        if ((i != 3 || j != 3) && gs.tile_values_[i][j] != 0) {
          REQUIRE(found_new_val == false);
          REQUIRE((gs.tile_values_[i][j] == 2 || gs.tile_values_[i][j] == 4));
          found_new_val = true;
        }
      }
    }
    REQUIRE(found_new_val);
  }
  SECTION("Board updates up") {
    gs.tile_values_ = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {2, 0, 0, 0}};
    gs.ExecuteInput(GameState::up);
    bool found_new_val = false;
    for (size_t i = 0; i < board_size; i++) {
      for (size_t j = 0; j < board_size; j++) {
        if ((i != 0 || j != 0) && gs.tile_values_[i][j] != 0) {
          REQUIRE(found_new_val == false);
          REQUIRE((gs.tile_values_[i][j] == 2 || gs.tile_values_[i][j] == 4));
          found_new_val = true;
        }
      }
    }
    REQUIRE(found_new_val);
  }
}

TEST_CASE("Board does not update with new number when unchanged") {
  size_t board_size = 4;
  GameState gs(1500, 50, 400);
  gs.SelectGame(board_size);
  SECTION("New number is not added if board doesn't change right") {
    gs.tile_values_ = {{8, 16, 8, 16}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    vector<vector<size_t>> expected = {{8, 16, 8, 16}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    gs.ExecuteInput(GameState::right);
    REQUIRE(BoardsEqual(gs.tile_values_, expected));
  }
  SECTION("New number is not added if board doesn't change left") {
    gs.tile_values_ = {{8, 16, 8, 16}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    vector<vector<size_t>> expected = {{8, 16, 8, 16}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    gs.ExecuteInput(GameState::left);
    REQUIRE(BoardsEqual(gs.tile_values_, expected));
  }
  SECTION("New number is not added if board doesn't change down") {
    gs.tile_values_ = {{8, 0, 0, 0}, {16, 0, 0, 0}, {8, 0, 0, 0}, {16, 0, 0, 0}};
    vector<vector<size_t>> expected = {{8, 0, 0, 0}, {16, 0, 0, 0}, {8, 0, 0, 0}, {16, 0, 0, 0}};
    gs.ExecuteInput(GameState::down);
    REQUIRE(BoardsEqual(gs.tile_values_, expected));
  }
  SECTION("New number is not added if board doesn't change up") {
    gs.tile_values_ = {{8, 0, 0, 0}, {16, 0, 0, 0}, {8, 0, 0, 0}, {16, 0, 0, 0}};
    vector<vector<size_t>> expected = {{8, 0, 0, 0}, {16, 0, 0, 0}, {8, 0, 0, 0}, {16, 0, 0, 0}};
    gs.ExecuteInput(GameState::up);
    REQUIRE(BoardsEqual(gs.tile_values_, expected));
  }
}

TEST_CASE("Test game over") {
  size_t board_size = 4;
  GameState gs(1500, 50, 400);
  gs.SelectGame(board_size);
  SECTION("Game over on right move") {
    gs.tile_values_ = {{128, 64, 128, 0}, {32, 16, 32, 16}, {4, 8, 4, 8}, {8, 4, 8, 4}};
    gs.ExecuteInput(GameState::right);
    REQUIRE(gs.finished_);
  }
  SECTION("Game over on left move") {
    gs.tile_values_ = {{0, 128, 64, 128}, {32, 16, 32, 16}, {4, 8, 4, 8}, {8, 4, 8, 4}};
    gs.ExecuteInput(GameState::left);
    REQUIRE(gs.finished_);
  }
  SECTION("Game over on down move") {
    gs.tile_values_ = {{32, 8, 2, 4}, {64, 16, 4, 2}, {32, 8, 2, 4}, {0, 16, 4, 2}};
    gs.ExecuteInput(GameState::down);
    REQUIRE(gs.finished_);
  }
  SECTION("Game over on up move") {
    gs.tile_values_ = {{0, 8, 2, 4}, {32, 16, 4, 2}, {64, 8, 2, 4}, {32, 16, 4, 2}};
    gs.ExecuteInput(GameState::up);
    REQUIRE(gs.finished_);
  }
}

TEST_CASE("Test game reset") {
  size_t board_size = 4;
  GameState gs(1500, 50, 400);
  gs.SelectGame(board_size);
  gs.ResetGame();
  REQUIRE(gs.score_ == 0);
  REQUIRE(gs.tiles_.empty());
  REQUIRE(gs.tile_values_.empty());
}
