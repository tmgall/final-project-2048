#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "game_state.h"

namespace game {

/**
 * An app for playing the game 2048.
 */
class GameApp : public ci::app::App {
 public:
  GameApp();

  void draw() override;
  void update() override;

  const int kWindowSize = 2000;
  const int kMargin = 100;

 private:
  GameState container_;
};

}  // namespace idealgas
