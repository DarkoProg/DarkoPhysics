#include <unistd.h>

#include <glm/ext/vector_float2.hpp>
#include <glm/glm.hpp>
#include <glm/vec2.hpp>
#include <iostream>
#include <ostream>

#include "Circle.h"

struct Box {
  glm::vec2 min;
  glm::vec2 max;
};

bool boxIntersect(Box &a, Box &b) {
  if (a.max.x < b.min.x or a.min.x > b.max.x) return false;
  if (a.max.y < b.min.y or a.min.y > b.max.y) return false;
  return true;
}

bool circleIntersect(Circle &a, Circle &b) {
  if (a.getRadius() + b.getRadius() >
      glm::distance(a.getPosition(), b.getPosition())) {
    return true;
  }
  return false;
}

int main() {
  Circle circle1 = Circle(glm::vec2{0, 0}, 1.0f);
  Circle circle2 = Circle(glm::vec2{10, 0}, 1.0f);
  Circle circle3 = Circle(glm::vec2{0.5, 0.5}, 1.0f);
  std::cout << circleIntersect(circle1, circle2);
  for (;;) {
    std::cout << "x: " << circle1.getPosition().x << std::endl;
    if (circleIntersect(circle1, circle2)) {
      std::cout << "COLISION!!!!\n";
      break;
    }
    circle1.Move(glm::vec2{0.1f, 0.0f});
    usleep(50000);
  }
}
