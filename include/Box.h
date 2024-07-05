#include <glm/vec2.hpp>

#include "Object.h"

#pragma once

class Box : public Object {
 private:
  float width;
  float height;

 public:
  Box(glm::vec2 Tposition, float Tinverse_mass, float width, float height);
};
