#include "Object.h"

#include <glm/detail/qualifier.hpp>
#include <glm/ext/vector_float2.hpp>

Object::Object(glm::vec2 Tposition, float Tinverse_mass)
    : position(Tposition), inverse_mass(Tinverse_mass) {
  velocity = glm::vec2{0, 0};
}

// #getters
glm::vec2 Object::getPosition() { return position; }
float Object::getInverseMass() { return inverse_mass; }
glm::vec2 Object::getVelocity() { return velocity; }

// setters
void Object::setInverseMass(float Tinverse_mass) {
  inverse_mass = Tinverse_mass;
}
void Object::setVelocity(glm::vec2 Tvelocity) { velocity = Tvelocity; }
void Object::setPosition(glm::vec2 Tposition) { position = Tposition; }

// other methods
void Object::Move() { position += velocity; }
