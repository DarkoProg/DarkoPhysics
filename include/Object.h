#include <glm/glm.hpp>
#include <glm/vec2.hpp>

#pragma once

class Object {
 private:
  glm::vec2 position;
  float inverse_mass;
  float velocity;

 public:
  Object(glm::vec2 Tposition, float Tinverse_mass);

  float getIinverse_mass();
  void setIinverse_mass(float Tinverse_mass);
  glm::vec2 getPosition();
  void Move(glm::vec2 move);
};
