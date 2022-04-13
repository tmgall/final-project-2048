#include <catch2/catch.hpp>

#include <game_state.h>
#include <game_app.h>

using game::GameState;
using game::GameApp;
using cinder::app::KeyEvent;

TEST_CASE("Key press registered") {
  GameApp ga;
  SECTION("Right key on") {
    ga.state.right_key_pressed = false;
    ga.keyDown(KeyEvent(0, KeyEvent::KEY_RIGHT, 0, 0, 0, 0));
    REQUIRE(ga.state.right_key_pressed);
  }
  SECTION("Left key on and off") {
    ga.state.left_key_pressed = false;
    ga.keyDown(KeyEvent(0, KeyEvent::KEY_LEFT, 0, 0, 0, 0));
    REQUIRE(ga.state.left_key_pressed);
  }
  SECTION("Down key on and off") {
    ga.state.down_key_pressed = false;
    ga.keyDown(KeyEvent(0, KeyEvent::KEY_DOWN, 0, 0, 0, 0));
    REQUIRE(ga.state.down_key_pressed);
  }
  SECTION("Up key on and off") {
    ga.state.up_key_pressed = false;
    ga.keyDown(KeyEvent(0, KeyEvent::KEY_UP, 0, 0, 0, 0));
    REQUIRE(ga.state.up_key_pressed);
  }
}

TEST_CASE("Key release registered") {
  GameApp ga;
  SECTION("Right key released") {
    ga.state.right_key_pressed = true;
    ga.keyUp(KeyEvent(0, KeyEvent::KEY_RIGHT, 0, 0, 0, 0));
    REQUIRE(!ga.state.right_key_pressed);
  }
  SECTION("Left key released") {
    ga.state.left_key_pressed = true;
    ga.keyUp(KeyEvent(0, KeyEvent::KEY_LEFT, 0, 0, 0, 0));
    REQUIRE(!ga.state.left_key_pressed);
  }
  SECTION("Down key released") {
    ga.state.down_key_pressed = true;
    ga.keyUp(KeyEvent(0, KeyEvent::KEY_DOWN, 0, 0, 0, 0));
    REQUIRE(!ga.state.down_key_pressed);
  }
  SECTION("Up key released") {
    ga.state.up_key_pressed = true;
    ga.keyUp(KeyEvent(0, KeyEvent::KEY_UP, 0, 0, 0, 0));
    REQUIRE(!ga.state.up_key_pressed);
  }
}

