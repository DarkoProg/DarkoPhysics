#include <glm/vec3.hpp>

#include "Object.h"

#pragma once

class Circle : public Object {
 private:
  float radius;
  const float PI = 3.1415926;

 public:
  Circle(glm::vec3 Tposition, float Tinverse_mass, float Tradius);
  float getRadius();
  std::vector<GLfloat> generateVertecies() override;
};
