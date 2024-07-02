#include <glm/vec2.hpp>

#include "Object.h"

#pragma once

class Circle : public Object {
 private:
  float radius;

 public:
  Circle(glm::vec2 Tposition, float Tradius);
  float getRadius();
};
