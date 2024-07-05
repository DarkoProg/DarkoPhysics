#include "Circle.h"

Circle::Circle(glm::vec2 Tposition, float Tinverse_mass, float Tradius)
    : Object(Tposition, Tinverse_mass), radius(Tradius) {}

float Circle::getRadius() { return radius; }
