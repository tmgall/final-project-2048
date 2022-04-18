#include "game_app.h"

namespace game {

GameApp::GameApp() :
                 state(GameState(kDefaultWindowWidth, kDefaultWindowHeight,
                                 kDefaultMargin, kDefaultBoardSize,kDefaultSquareWidth,
                                 kDefaultInfoHeight,kDefaultKeyOverlayW,
                                 kDefaultKeyOverlayH)) {
  ci::app::setWindowSize(kDefaultWindowWidth, kDefaultWindowHeight);
}

void GameApp::draw() {
  ci::Color background_color("black");
  ci::gl::clear(background_color);
  state.Display();
}

void GameApp::update() {
  state.Display();
}

void GameApp::keyDown(KeyEvent event) {
  if (event.getCode() == KeyEvent::KEY_RIGHT) {
    state.UpdateState(GameState::right);
  } else if (event.getCode() == KeyEvent::KEY_LEFT) {
    state.UpdateState(GameState::left);
  } else if (event.getCode() == KeyEvent::KEY_DOWN) {
    state.UpdateState(GameState::down);
  } else if (event.getCode() == KeyEvent::KEY_UP) {
    state.UpdateState(GameState::up);
  }
  update();
}

}  // namespace game
