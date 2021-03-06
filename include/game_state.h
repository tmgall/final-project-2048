#pragma once

#include "cinder/Color.h"
#include "cinder/gl/gl.h"
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using glm::vec2;
using std::vector;

namespace game {

/**
 * A class that stores the current state of the 2048 game.
 */
class GameState {
 public:
  /**
   * Constructor which takes custom values.
   * @param window_width height of display window.
   * @param margin margin on the side of display window.
   * @param info_height the height of the section of UI above the game board.
   */
  GameState(size_t window_width, size_t margin, size_t info_height);

  /**
   * Draws the entire game board on the UI in its current state.
   */
  void Display() const;

  /**
   * Enum for concisely describing user input.
   */
  enum Input { right, down, left, up };

  /**
   * Vector of rectangle objects which represent the tiles on the board.
   */
  vector<ci::Rectf> tiles_;

  /**
   * Vector of vectors of size_t primitives representing the matrix of current values on the board.
   */
  vector<vector<size_t>> tile_values_;

  /**
   * Updates the state of the board and adds a new random tile onto an empty board space.
   * @param input a direction right, left, down, or up.
   */
  void ExecuteInput(Input input);

  /**
   * Updates the board state based on the direction of user input.
   * @param input a direction right, left, down, or up.
   * @return true if the board was changed, false otherwise.
   */
  bool UpdateState(Input input);

  /**
   * Generates the game based on the given board size.
   * @param board_size the size of the board.
   */
  void SelectGame(size_t board_size);

  /**
   * Resets squares, score, and tiles.
   */
  void ResetGame();

  /**
   * The current player score.
   */
  size_t score_;

  /**
   * True if the game is finished.
   */
  bool finished_;

  /**
   * True if the player is in the menu screen.
   */
  bool in_menu_;

private:
  size_t window_width_;
  size_t margin_;
  size_t board_size_;
  size_t square_width_;
  size_t info_height_;

  const size_t kFourChanceRatio = 4;

  bool MoveRight();
  bool MoveDown();
  bool MoveLeft();
  bool MoveUp();
  void AddRandomNumberToBoard();
  static void DrawText(const std::string& text, const vec2& pos);
  static ci::Color GetTileColor(size_t val) ;
  bool GameFinished();
  void DisplayMenu() const;
};

}  // namespace game
