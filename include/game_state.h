#pragma once

#include "cinder/gl/gl.h"

using glm::vec2;

namespace game {

/**
 * The container in which all of the gas particles are contained. This class
 * stores all of the particles and updates them on each frame of the simulation.
 */
class GameState {
 public:
  /**
   * TODO: Add more parameters to this constructor, and add documentation.
   */
  GameState();

  /**
   * Displays the container walls and the current positions of the particles.
   */
  void Display() const;

  /**
   * Updates the positions and velocities of all particles (based on the rules
   * described in the assignment documentation).
   */
  void AdvanceOneFrame();

 private:
  size_t board_size = 4;
};

}  // namespace idealgas
