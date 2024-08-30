#include "Circle.h"

Circle::Circle(glm::vec3 Tposition, float Tinverse_mass, float Tradius)
    : Object(Tposition, Tinverse_mass), radius(Tradius) {}

float Circle::getRadius() { return radius; }

std::vector<GLfloat> Circle::generateVertecies() {
  std::vector<GLfloat> verticies;

  return verticies;
}
