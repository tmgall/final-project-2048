#pragma once

#include "cinder/gl/gl.h"
#include <vector>

using glm::vec2;
using std::vector;

namespace game {

class GameState {
 public:
  /**
   * Constructor which sets all variables to default values.
   */
  GameState();

  /**
   * Constructor which takes custom values.
   * @param window_width height of display window.
   * @param window_height width of display window.
   * @param margin margin on the side of display window.
   * @param board_size number of tiles along a side of the board.
   * @param square_width the width of each tile.
   * @param info_height the height of the section of UI above the game board.
   * @param key_overlay_w the width of the keyboard overlay.
   * @param key_overlay_h the height of the keyboard overlay.
   */
  GameState(size_t window_width, size_t window_height, size_t margin, size_t board_size, size_t square_width,
            size_t info_height, size_t key_overlay_w, size_t key_overlay_h);
  /**
   * Draws the entire game board on the UI in its current state.
   */
  void Display() const;

  /**
   * True if the right arrow key is currently being pressed.
   */
  bool right_key_pressed = false;

  /**
   * True if the left arrow key is currently being pressed.
   */
  bool left_key_pressed = false;

  /**
   * True if the up arrow key is currently being pressed.
   */
  bool up_key_pressed = false;

  /**
   * True if the down arrow key is currently being pressed.
   */
  bool down_key_pressed = false;

  /**
   * Vector of rectangle objects which represent the tiles on the board.
   */
  vector<ci::Rectf> tiles;

private:
  size_t window_width_;
  size_t window_height_;
  size_t margin_;
  size_t board_size_;
  size_t square_width_;
  size_t info_height_;
  size_t key_overlay_w_;
  size_t key_overlay_h_;

  void DrawText(const std::string& text, const vec2& pos) const;

  void DrawKeyOverlay() const;

  const size_t kDefaultWindowWidth = 1500;
  const size_t kDefaultWindowHeight = 1850;
  const size_t kDefaultMargin = 50;
  const size_t kDefaultBoardSize = 4;
  const size_t kDefaultSquareWidth = 350;
  const size_t kDefaultInfoHeight = 400;
  const size_t kDefaultKeyOverlayW = 300;
  const size_t kDefaultKeyOverlayH = 150;
};

}  // namespace game
