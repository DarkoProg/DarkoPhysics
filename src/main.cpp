#include <glm/ext/vector_float2.hpp>
#include <glm/glm.hpp>
#include <glm/vec2.hpp>
#include <iostream>
#include <ostream>

struct Box {
  glm::vec2 min;
  glm::vec2 max;
};

struct Circle {
  float radius;
  glm::vec2 position;
};

bool boxIntersect(Box &a, Box &b) {
  if (a.max.x < b.min.x or a.min.x > b.max.x) return false;
  if (a.max.y < b.min.y or a.min.y > b.max.y) return false;
  return true;
}

bool circleIntersect(Circle &a, Circle &b) {
  if (a.radius + b.radius > glm::distance(a.position, b.position)) {
    return true;
  }
  return false;
}

int main() {
  Box box1 = Box{glm::vec2{0, 0}, glm::vec2{1, 1}};
  Box box2 = Box{glm::vec2{0.5, 0.5}, glm::vec2{1.5, 1.5}};
  Box box3 = Box{glm::vec2{1.5, 1.5}, glm::vec2{2.5, 2.5}};
  Box box4 = Box{glm::vec2{-1.5, -1.5}, glm::vec2{0.5, 0.5}};
  std::cout << boxIntersect(box1, box3) << std::endl;
  Circle circle1 = Circle{1.0f, glm::vec2{0, 0}};
  Circle circle2 = Circle{1.0f, glm::vec2{2, 2}};
  Circle circle3 = Circle{1.0f, glm::vec2{0.5, 0.5}};
  std::cout << circleIntersect(circle1, circle2);
}
