#include "game_app.h"

namespace game {

GameApp::GameApp() :
                 window_width_(kDefaultWindowWidth), window_height_(kDefaultWindowHeight), margin_(kDefaultMargin),
                 board_size_(kDefaultBoardSize), square_width_(kDefaultSquareWidth), info_height_(kDefaultInfoHeight),
                 key_overlay_w_(kDefaultKeyOverlayW), key_overlay_h_(kDefaultKeyOverlayH),
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

}  // namespace game
