#pragma once

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
  void keyDown(KeyEvent event) override;

  /**
   * The current board state of the game.
   */
  GameState state;

private:
  static const size_t kDefaultWindowWidth = 1500;
  static const size_t kDefaultWindowHeight = 1850;
  static const size_t kDefaultMargin = 50;
  static const size_t kDefaultInfoHeight = 400;
};

}  // namespace game
