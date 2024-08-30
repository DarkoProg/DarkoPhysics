#include "Object.h"

#include <cmath>
#include <glm/fwd.hpp>
#include <glm/vec3.hpp>
#include <iostream>

Object::Object(glm::vec3 Tposition, float Tinverse_mass)
    : position(Tposition), inverse_mass(Tinverse_mass) {
  velocity = glm::vec3{0, 0, 0};
  orientation = glm::mat4{1.0};
}

// #getters
glm::vec3 Object::getPosition() { return position; }
float Object::getInverseMass() { return inverse_mass; }
glm::vec3 Object::getVelocity() { return velocity; }

// setters
void Object::setInverseMass(float Tinverse_mass) {
  inverse_mass = Tinverse_mass;
}
void Object::setVelocity(glm::vec3 Tvelocity) { velocity = Tvelocity; }
void Object::setPosition(glm::vec3 Tposition) { position = Tposition; }

// virtual methods
void Object::print() {
  std::cout << "x: " << position.x << " y: " << position.y << std::endl;
}

// other methods
void Object::Move() { position += velocity; }

std::vector<GLfloat> Object::generateVertecies() {
  return std::vector<GLfloat>();
}
