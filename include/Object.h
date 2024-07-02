#include <glm/glm.hpp>
#include <glm/vec2.hpp>

#pragma once

class Object {
 private:
  glm::vec2 position;

 public:
  Object(glm::vec2 Tposition);

  glm::vec2 getPosition();
  void Move(glm::vec2 move);
};
