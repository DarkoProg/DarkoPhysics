#include "Object.h"

#include <glm/detail/qualifier.hpp>
#include <glm/ext/vector_float2.hpp>

Object::Object(glm::vec2 Tposition) { position = Tposition; }

glm::vec2 Object::getPosition() { return position; }
void Object::Move(glm::vec2 move) {
  position.x += move.x;
  position.y += move.y;
}
