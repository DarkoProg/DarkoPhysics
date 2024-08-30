#include <glm/ext/vector_float2.hpp>
#include <glm/vec3.hpp>

#include "Object.h"

#pragma once

class Box : public Object {
 private:
  glm::vec3 min;
  glm::vec3 max;

 public:
  Box(glm::vec3 Tposition, float Tinverse_mass, glm::vec3 min, glm::vec3 max);

  glm::vec3 getMin();
  glm::vec3 getMax();

  std::vector<GLfloat> generateVertecies() override;
};
