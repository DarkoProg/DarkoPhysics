#include "Circle.h"

#include <cmath>
#include <iostream>
#include <iterator>

Circle::Circle(glm::vec3 Tposition, float Tinverse_mass, float Tradius)
    : Object(Tposition, Tinverse_mass), radius(Tradius) {}

float Circle::getRadius() { return radius; }

std::vector<GLfloat> Circle::generateVertecies() {
  int number_of_points = 100;
  float base_angle = (float)(PI * 2 / number_of_points);
  std::vector<GLfloat> vertices;
  std::vector<GLfloat> last_vertice;

  for (int i = 1; i <= number_of_points; i++) {
    vertices.push_back(getPosition().x);
    vertices.push_back(getPosition().y);
    vertices.push_back(0);

    vertices.push_back(getPosition().x + radius * sin(base_angle * (i - 1)));
    vertices.push_back(getPosition().y - radius * cos(base_angle * (i - 1)));
    vertices.push_back(0);

    vertices.push_back(getPosition().x + radius * sin(base_angle * i));
    vertices.push_back(getPosition().y - radius * cos(base_angle * i));
    vertices.push_back(0);
  }

  return vertices;
}
