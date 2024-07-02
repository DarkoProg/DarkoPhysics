#include "Object.h"

#include <glm/detail/qualifier.hpp>
#include <glm/ext/vector_float2.hpp>

Object::Object(glm::vec2 Tposition, float Tinverse_mass)
    : position(Tposition), inverse_mass(Tinverse_mass) {
  velocity = 0;
}

void Object::setIinverse_mass(float Tinverse_mass) {
  inverse_mass = Tinverse_mass;
}
glm::vec2 Object::getPosition() { return position; }
void Object::Move(glm::vec2 move) {
  position.x += move.x;
  position.y += move.y;
}
