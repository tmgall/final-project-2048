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

  /**
   * The current state of the game.
   */
  GameState state;

private:
  static const size_t kDefaultWindowWidth = 1500;
  static const size_t kDefaultWindowHeight = 1850;
  static const size_t kDefaultMargin = 50;
  static const size_t kDefaultBoardSize = 8;
  static const size_t kDefaultSquareWidth = 175;
  static const size_t kDefaultInfoHeight = 400;
  static const size_t kDefaultKeyOverlayW = 300;
  static const size_t kDefaultKeyOverlayH = 150;
};

}  // namespace game
