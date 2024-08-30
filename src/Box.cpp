#include "Box.h"

#include <glm/ext/vector_float2.hpp>
#include <iostream>
#include <vector>

#include "Object.h"

Box::Box(glm::vec3 Tposition, float Tinverse_mass, glm::vec3 Tmin,
         glm::vec3 Tmax)
    : Object(Tposition, Tinverse_mass), min(Tmin), max(Tmax) {}

glm::vec3 Box::getMin() { return min; }
glm::vec3 Box::getMax() { return max; }

std::vector<GLfloat> Box::generateVertecies() {
  std::vector<GLfloat> verticies;
  verticies.push_back(getPosition().x - min.x);
  verticies.push_back(getPosition().y - min.y);
  verticies.push_back(0);
  verticies.push_back(getPosition().x + max.x);
  verticies.push_back(getPosition().y - min.y);
  verticies.push_back(0);
  verticies.push_back(getPosition().x + max.x);
  verticies.push_back(getPosition().y + max.y);
  verticies.push_back(0);

  verticies.push_back(getPosition().x - min.x);
  verticies.push_back(getPosition().y - min.y);
  verticies.push_back(0);
  verticies.push_back(getPosition().x - min.x);
  verticies.push_back(getPosition().y + max.y);
  verticies.push_back(0);
  verticies.push_back(getPosition().x + max.x);
  verticies.push_back(getPosition().y + max.y);
  verticies.push_back(0);

  return verticies;
}
