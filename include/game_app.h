#pragma once

#include <iostream>

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/app/KeyEvent.h"
#include "game_state.h"

namespace game {

using cinder::app::KeyEvent;

/**
 * An app for playing the game 2048.
 */
class GameApp : public ci::app::App {
 public:
  /**
   * Constructor which sets all variables to the default values.
   */
  GameApp();

  void draw() override;
  void update() override;
  void keyDown(KeyEvent event) override;
  void keyUp(KeyEvent event) override;

  /**
   * The width of the display window.
   */
  size_t window_width_;

  /**
   * The height of the display window.
   */
  size_t window_height_;

  /**
   * The margin on the outside of the display window.
   */
  size_t margin_;

  /**
   * The number of tiles along the side of the board.
   */
  size_t board_size_;

  /**
   * The width of each square on the game board.
   */
  size_t square_width_;

  /**
   * The height of the UI section above the game board.
   */
  size_t info_height_;

  /**
   * The width of the keyboard overlay.
   */
  size_t key_overlay_w_;

  /**
   * The height of the keyboard overlay.
   */
  size_t key_overlay_h_;

  /**
   * The current state of the game.
   */
  GameState state;

private:
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
