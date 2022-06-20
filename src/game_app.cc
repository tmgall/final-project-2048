#include "game_app.h"

namespace game {

GameApp::GameApp() :
                 state(GameState(kDefaultWindowWidth, kDefaultMargin, kDefaultInfoHeight)) {
  ci::app::setWindowSize(kDefaultWindowWidth, kDefaultWindowHeight);
}

void GameApp::draw() {
  ci::Color background_color("gray");
  ci::gl::clear(background_color);
  state.Display();
}

void GameApp::keyDown(KeyEvent event) {
  if (event.getCode() == KeyEvent::KEY_RIGHT) {
    if (state.in_menu_) {
      state.SelectGame(3);
      state.in_menu_ = false;
    } else {
      state.ExecuteInput(GameState::right);
    }
  } else if (event.getCode() == KeyEvent::KEY_LEFT) {
    if (state.in_menu_) {
      state.SelectGame(2);
      state.in_menu_ = false;
    } else {
      state.ExecuteInput(GameState::left);
    }
  } else if (event.getCode() == KeyEvent::KEY_DOWN) {
    if (state.in_menu_) {
      state.SelectGame(4);
      state.in_menu_ = false;
    } else {
      state.ExecuteInput(GameState::down);
    }
  } else if (event.getCode() == KeyEvent::KEY_UP) {
    if (state.in_menu_) {
      state.SelectGame(5);
      state.in_menu_ = false;
    } else {
      state.ExecuteInput(GameState::up);
    }
  } else if (event.getCode() == KeyEvent::KEY_SPACE) {
    if (state.finished_ && !state.in_menu_) {
      state.in_menu_ = true;
      state.finished_ = false;
      state.ResetGame();
    }
  }
  update();
}

}  // namespace game
