#include <glm/ext/vector_float2.hpp>
#include <glm/vec2.hpp>

#include "Object.h"

#pragma once

class Box : public Object {
 private:
  glm::vec2 min;
  glm::vec2 max;

 public:
  Box(glm::vec2 Tposition, float Tinverse_mass, glm::vec2 min, glm::vec2 max);

  glm::vec2 getMin();
  glm::vec2 getMax();
};
