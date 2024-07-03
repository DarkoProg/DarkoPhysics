#include <unistd.h>

#include <cmath>
#include <glm/ext/vector_float2.hpp>
#include <glm/geometric.hpp>
#include <glm/glm.hpp>
#include <glm/vec2.hpp>
#include <iostream>
#include <ostream>

#include "Circle.h"
#include "Object.h"

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

void colisionResolution(Object &obj1, Object &obj2, glm::vec2 colision_normal) {
  glm::vec2 relative_velocity = obj1.getVelocity() - obj2.getVelocity();
  float total_velocity =
      -(1 + M_E) * glm::dot(relative_velocity, colision_normal);
  float impulse =
      total_velocity / (obj1.getInverseMass() + obj2.getInverseMass());

  obj1.setVelocity(obj1.getVelocity() +
                   obj1.getInverseMass() * impulse * colision_normal);
  obj2.setVelocity(obj2.getVelocity() -
                   obj2.getInverseMass() * impulse * colision_normal);
}

void repositionObjectsOnCollision(Circle &obj1, Circle &obj2) {
  obj1.setPosition(obj2.getPosition() - obj2.getRadius() - obj1.getRadius());
}

int main() {
  Circle circle1 = Circle(glm::vec2{0, 0}, 1.0f / 10.0f, 1.0f);
  Circle circle2 = Circle(glm::vec2{5, 0}, 1.0f / 10.0f, 1.0f);
  Circle circle3 = Circle(glm::vec2{0.5, 0.5}, 1.0f / 10.0f, 1.0f);
  circle1.setVelocity(glm::vec2{0.1, 0});
  // circle2.setVelocity(glm::vec2{-0.1, 0});
  for (;;) {
    std::cout << "Ax: " << circle1.getPosition().x
              << "   Bx: " << circle2.getPosition().x << std::endl;
    if (circleIntersect(circle1, circle2)) {
      glm::vec2 colision_normal = circle1.getPosition() - circle2.getPosition();
      float distance = (colision_normal * colision_normal).length();
      repositionObjectsOnCollision(circle1, circle2);
      colisionResolution(circle1, circle2, colision_normal / distance);
      std::cout << "COLISION!!!!\n";
      // std::cout << "Ax: " << circle1.getPosition().x
      //           << "   Bx: " << circle2.getPosition().x << std::endl;
      // break;
    }
    circle1.Move();
    circle2.Move();
    usleep(50000);
  }
}
