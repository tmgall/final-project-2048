#include "game_app.h"

namespace game {

GameApp::GameApp() {
  ci::app::setWindowSize(kWindowSize, kWindowSize);
}

void GameApp::draw() {
  ci::Color background_color("black");
  ci::gl::clear(background_color);

  container_.Display();
}

void GameApp::update() {
  container_.AdvanceOneFrame();
}

}  // namespace idealgas
