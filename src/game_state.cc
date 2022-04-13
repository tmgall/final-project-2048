#include "game_state.h"

namespace game {

using glm::vec2;

GameState::GameState() {
  window_width_ = kDefaultWindowWidth;
  window_height_ = kDefaultWindowHeight;
  margin_ = kDefaultMargin;
  board_size_ = kDefaultBoardSize;
  square_width_ = kDefaultSquareWidth;
  info_height_ = kDefaultInfoHeight;
  key_overlay_w_ = kDefaultKeyOverlayW;
  key_overlay_h_ = kDefaultKeyOverlayH;
}

GameState::GameState(size_t window_width, size_t window_height, size_t margin, size_t board_size, size_t square_width,
                     size_t info_height, size_t key_overlay_w, size_t key_overlay_h) {
  window_width_ = window_width;
  window_height_ = window_height;
  margin_ = margin;
  board_size_ = board_size;
  square_width_ = square_width;
  info_height_ = info_height;
  key_overlay_w_ = key_overlay_w;
  key_overlay_h_ = key_overlay_h;

}

void GameState::Display() const {
  ci::gl::color(ci::Color("white"));
  DrawKeyOverlay();
  for (size_t i = 0; i < board_size_; i++) {
    for (size_t j = 0; j < board_size_; j++) {
      vec2 top_left(margin_ + square_width_ * i, info_height_ + square_width_ * j);
      vec2 bottom_right(margin_ + square_width_ * (i + 1), info_height_ + square_width_ * (j + 1));
      ci::gl::drawStrokedRect(ci::Rectf(top_left, bottom_right));
    }
  }
}

void GameState::DrawText(const std::string& text, const vec2& pos) const {
  ci::Font f("roboto regular", 70);
  ci::gl::drawStringRight(text, pos, ci::Color("white"), f);
}

void GameState::DrawKeyOverlay() const {
  size_t x_top_left = window_width_ - margin_ - key_overlay_w_;
  size_t y_top_left = info_height_ - margin_ - key_overlay_h_;
  ci::Rectf left_rect(vec2(x_top_left, y_top_left),
                      vec2(x_top_left + key_overlay_w_ * 0.3, y_top_left + key_overlay_h_));
  ci::Rectf right_rect(vec2(x_top_left + key_overlay_w_ * 0.7, y_top_left),
                       vec2(x_top_left + key_overlay_w_, y_top_left + key_overlay_h_));
  ci::Rectf up_rect(vec2(x_top_left + key_overlay_w_ * 0.3, y_top_left),
                    vec2(x_top_left + key_overlay_w_ * 0.7, y_top_left + key_overlay_h_ / 2));
  ci::Rectf down_rect(vec2(x_top_left + key_overlay_w_ * 0.3, y_top_left + key_overlay_h_ / 2),
                      vec2(x_top_left + key_overlay_w_ * 0.7, y_top_left + key_overlay_h_));
  ci::gl::drawStrokedRect(left_rect);
  ci::gl::drawStrokedRect(right_rect);
  ci::gl::drawStrokedRect(up_rect);
  ci::gl::drawStrokedRect(down_rect);
  if (left_key_pressed) {
    ci::gl::drawSolidRect(left_rect);
  }
  if (right_key_pressed) {
    ci::gl::drawSolidRect(right_rect);
  }
  if (up_key_pressed) {
    ci::gl::drawSolidRect(up_rect);
  }
  if (down_key_pressed) {
      ci::gl::drawSolidRect(down_rect);
  }
}

}  // namespace idealgas
