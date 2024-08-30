#include <glm/glm.hpp>
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include <vector>

#include "ShaderProgram.h"

#pragma once

class Object {
 private:
  glm::vec3 position;
  float inverse_mass;
  glm::vec3 velocity;
  glm::mat4 orientation;

 public:
  Object(glm::vec3 Tposition, float Tinverse_mass);

  // getters
  float getInverseMass();
  glm::vec3 getVelocity();
  glm::vec3 getPosition();

  // setters
  void setInverseMass(float Tinverse_mass);
  void setVelocity(glm::vec3 Tvelocity);
  void setPosition(glm::vec3 Tposition);

  // virtual methods
  virtual void print();
  virtual std::vector<GLfloat> generateVertecies();

  // other methods
  void Move();
};
