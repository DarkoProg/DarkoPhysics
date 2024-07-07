
#include <unistd.h>

#include <cmath>
#include <glm/ext/vector_float2.hpp>
#include <glm/geometric.hpp>
#include <glm/glm.hpp>
#include <glm/vec2.hpp>

#include "Box.h"
#include "Circle.h"
#include "Object.h"
#define GLFW_INCLUDE_NONE
#include "graphic.h"

// #include <iostream>
// #include <ostream>

bool boxIntersect(Box &a, Box &b) {
  if (a.getMax().x < b.getMin().x or a.getMin().x > b.getMax().x) return false;
  if (a.getMax().y < b.getMin().y or a.getMin().y > b.getMax().y) return false;
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

glm::vec2 collisionNormal(Object object1, Object object2) {
  return object1.getPosition() - object2.getPosition();
}

// glm::vec2 collisionNormal(Circle circle1, Circle circle2) {
//   return circle1.getPosition() - circle2.getPosition();
// }

// glm::vec2 collisionNormal(Box box1, Box box2) {
//   glm::vec2 n = box1.getPosition() - box2.getPosition();
//   return n;
// }

int main() {
  Graphic opengl(800, 800);
  if (!opengl.initWindow()) {
    return -1;
  }
  Box box1 = Box(glm::vec2{0, 0}, 1.0f / 10.0f, glm::vec2{1.0f, 1.0f},
                 glm::vec2{1.0f});
  Circle circle1 = Circle(glm::vec2{0, 0}, 1.0f / 10.0f, 1.0f);
  Circle circle2 = Circle(glm::vec2{5, 0.5f}, 1.0f / 10.0f, 1.0f);
  Circle circle3 = Circle(glm::vec2{0.5, 0.5}, 1.0f / 10.0f, 1.0f);
  circle1.setVelocity(glm::vec2{0.1, 0});
  // circle2.setVelocity(glm::vec2{-0.1, 0});
  while (!glfwWindowShouldClose(opengl.getWindow())) {
    opengl.processInput();

    glClearColor(0.4f, 0.4f, 0.6f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(opengl.getWindow());
    glfwPollEvents();
    // std::cout << "circle1: ";
    // circle1.print();
    // std::cout << "circle2: ";
    // circle2.print();
    // if (circleIntersect(circle1, circle2)) {
    //   glm::vec2 colision_normal = collisionNormal(circle1, circle2);
    //   float distance = (colision_normal * colision_normal).length();
    //   repositionObjectsOnCollision(circle1, circle2);
    //   colisionResolution(circle1, circle2, colision_normal / distance);
    //   std::cout << "COLISION!!!!\n";
    //   // std::cout << "Ax: " << circle1.getPosition().x
    //   //           << "   Bx: " << circle2.getPosition().x << std::endl;
    //   // break;
    // }
    // circle1.Move();
    // circle2.Move();
    // usleep(50000);
  }
  opengl.cleanup();
  return 0;
}
