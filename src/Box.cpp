#include "Box.h"

#include <glm/ext/vector_float2.hpp>

#include "Object.h"

Box::Box(glm::vec2 Tposition, float Tinverse_mass, glm::vec2 Tmin,
         glm::vec2 Tmax)
    : Object(Tposition, Tinverse_mass), min(Tmin), max(Tmax) {}

glm::vec2 Box::getMin() { return min; }
glm::vec2 Box::getMax() { return max; }
