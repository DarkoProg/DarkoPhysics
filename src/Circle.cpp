#include <Circle.h>

#include "Object.h"

Circle::Circle(glm::vec2 Tposition, float Tradius)
    : Object(Tposition), radius(Tradius) {}

float Circle::getRadius() { return radius; }
