#include <glm/glm.hpp>
#include <glm/mat4x4.hpp>
#include <glm/vec2.hpp>

#pragma once

class Object {
 private:
  glm::vec2 position;
  float inverse_mass;
  glm::vec2 velocity;
  glm::mat4 orientation;

 public:
  Object(glm::vec2 Tposition, float Tinverse_mass);

  // getters
  float getInverseMass();
  glm::vec2 getVelocity();
  glm::vec2 getPosition();

  // setters
  void setInverseMass(float Tinverse_mass);
  void setVelocity(glm::vec2 Tvelocity);
  void setPosition(glm::vec2 Tposition);

  // virtual methods
  void print();

  // other methods
  void Move();
};
