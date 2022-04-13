#include "game_app.h"

namespace game {

GameApp::GameApp() : state(GameState(kWindowWidth, kWindowHeight, kMargin,
                                     kBoardSize,kSquareWidth, kInfoHeight,
                                     kKeyOverlayW, kKeyOverlayH)) {
  ci::app::setWindowSize(kWindowWidth, kWindowHeight);
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
    state.right_key_pressed = true;
  } else if (event.getCode() == KeyEvent::KEY_LEFT) {
    state.left_key_pressed = true;
  } else if (event.getCode() == KeyEvent::KEY_DOWN) {
    state.down_key_pressed = true;
  } else if (event.getCode() == KeyEvent::KEY_UP) {
    state.up_key_pressed = true;
  }
  update();
}

  void GameApp::keyUp(KeyEvent event) {
    if (event.getCode() == KeyEvent::KEY_RIGHT) {
      state.right_key_pressed = false;
    } else if (event.getCode() == KeyEvent::KEY_LEFT) {
      state.left_key_pressed = false;
    } else if (event.getCode() == KeyEvent::KEY_DOWN) {
      state.down_key_pressed = false;
    } else if (event.getCode() == KeyEvent::KEY_UP) {
      state.up_key_pressed = false;
    }
    update();
  }

}  // namespace idealgas
