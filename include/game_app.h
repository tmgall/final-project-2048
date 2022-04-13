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
  GameApp();

  void draw() override;
  void update() override;
  void keyDown(KeyEvent event) override;
  void keyUp(KeyEvent event) override;

  const size_t kWindowWidth = 1500;
  const size_t kWindowHeight = 1850;
  const size_t kMargin = 50;
  const size_t kBoardSize = 4;
  const size_t kSquareWidth = 350;
  const size_t kInfoHeight = 400;
  const size_t kKeyOverlayW = 300;
  const size_t kKeyOverlayH = 150;
 private:
  GameState state;
};

}  // namespace idealgas
