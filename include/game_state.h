#pragma once

#include "cinder/gl/gl.h"

using glm::vec2;

namespace game {

class GameState {
 public:
  GameState();
  GameState(size_t window_width, size_t window_height, size_t margin, size_t board_size, size_t square_width,
            size_t info_height, size_t key_overlay_w, size_t key_overlay_h);

  void Display() const;

  bool right_key_pressed = false;
  bool left_key_pressed = false;
  bool up_key_pressed = false;
  bool down_key_pressed = false;

 private:
  size_t window_width_;
  size_t window_height_;
  size_t margin_;
  size_t board_size_;
  size_t square_width_;
  size_t info_height_;
  size_t key_overlay_w_;
  size_t key_overlay_h_;

  void DrawText(const std::string& text, const vec2& pos) const;

  void DrawKeyOverlay() const;

  const size_t kDefaultWindowWidth = 1500;
  const size_t kDefaultWindowHeight = 1850;
  const size_t kDefaultMargin = 50;
  const size_t kDefaultBoardSize = 4;
  const size_t kDefaultSquareWidth = 350;
  const size_t kDefaultInfoHeight = 400;
  const size_t kDefaultKeyOverlayW = 300;
  const size_t kDefaultKeyOverlayH = 150;
};

}  // namespace idealgas
