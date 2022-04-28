#include "game_app.h"

namespace game {

GameApp::GameApp() :
                 state(GameState(kDefaultWindowWidth, kDefaultWindowHeight,
                                 kDefaultMargin, kDefaultBoardSize,kDefaultInfoHeight)) {
  ci::app::setWindowSize(kDefaultWindowWidth, kDefaultWindowHeight);
}

void GameApp::draw() {
  ci::Color background_color("gray");
  ci::gl::clear(background_color);
  state.Display();
}

void GameApp::update() { // don't need
  state.Display();
}

void GameApp::keyDown(KeyEvent event) {
  if (event.getCode() == KeyEvent::KEY_RIGHT) {
    state.ExecuteInput(GameState::right);
  } else if (event.getCode() == KeyEvent::KEY_LEFT) {
    state.ExecuteInput(GameState::left);
  } else if (event.getCode() == KeyEvent::KEY_DOWN) {
    state.ExecuteInput(GameState::down);
  } else if (event.getCode() == KeyEvent::KEY_UP) {
    state.ExecuteInput(GameState::up);
  }
  update();
}

}  // namespace game
