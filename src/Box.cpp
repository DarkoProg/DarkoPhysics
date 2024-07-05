#include "Box.h"

#include "Object.h"

Box::Box(glm::vec2 Tposition, float Tinverse_mass, float width, float height)
    : Object(Tposition, Tinverse_mass), width(width), height(height) {}
