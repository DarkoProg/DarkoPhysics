
#include <unistd.h>

#include <cmath>
#include <glm/ext/vector_float2.hpp>
#include <glm/fwd.hpp>
#include <glm/geometric.hpp>
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <ostream>
#include <vector>

#include "Box.h"
#include "Circle.h"
#include "Object.h"
#include "ShaderProgram.h"
#include "VAO.h"
#include "VBO.h"
#define GLFW_INCLUDE_NONE
#include <iostream>

#include "Graphic.h"
// #include <ostream>
std::vector<Object *> objects;
std::vector<GLfloat> vert;

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

void colisionResolution(Object &obj1, Object &obj2, glm::vec3 colision_normal) {
  glm::vec3 relative_velocity = obj1.getVelocity() - obj2.getVelocity();
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

glm::vec3 collisionNormal(Object object1, Object object2) {
  return object1.getPosition() - object2.getPosition();
}

// glm::vec3 collisionNormal(Circle circle1, Circle circle2) {
//   return circle1.getPosition() - circle2.getPosition();
// }

// glm::vec3 collisionNormal(Box box1, Box box2) {
//   glm::vec3 n = box1.getPosition() - box2.getPosition();
//   return n;
// }

int main() {
  objects.push_back(new Circle(glm::vec3(0.5f, 0.5f, 0), 1.0f / 10.0f, 0.5f));
  objects.push_back(new Box(glm::vec3(0.0f, 0.0f, 0), 1.0f / 10.0f,
                            glm::vec3(0.5f, 0.5f, 0),
                            glm::vec3(0.5f, 0.5f, 0)));

  for (int i = 0; i < objects.size(); i++) {
    std::vector<GLfloat> temp_verticies = objects[i]->generateVertecies();
    for (int i = 0; i < temp_verticies.size(); i++) {
      // std::cout << temp_verticies[i] << std::endl;
    }
    vert.insert(vert.end(), temp_verticies.begin(), temp_verticies.end());
  }

  std::cout << vert.size() << " aaa" << std::endl;
  std::cout << vert.size() / 3 << " num of vert" << std::endl;
  Graphic opengl(800, 800);
  if (!opengl.initWindow()) {
    return -1;
  }

  VAO VAO1;
  VAO1.Bind();
  VBO VBO1(vert, vert.size() * sizeof(GLfloat));
  VAO1.LinkAttribute(VBO1, 0, 3, GL_FLOAT, 3 * sizeof(GL_FLOAT), (void *)0);
  // Your function
  Shader ShaderProgram("../shaders/default.vert", "../shaders/default.frag");

  // Box box1 = Box(glm::vec3{0, 0}, 1.0f / 10.0f, glm::vec3{1.0f, 1.0f},
  //                glm::vec3{1.0f});
  // Circle circle1 = Circle(glm::vec3{0, 0}, 1.0f / 10.0f, 1.0f);
  // Circle circle2 = Circle(glm::vec3{5, 0.5f}, 1.0f / 10.0f, 1.0f);
  // Circle circle3 = Circle(glm::vec3{0.5, 0.5}, 1.0f / 10.0f, 1.0f);
  // circle1.setVelocity(glm::vec3{0.1, 0});
  // circle2.setVelocity(glm::vec3{-0.1, 0});
  while (!glfwWindowShouldClose(opengl.getWindow())) {
    opengl.processInput();

    glClearColor(0.4f, 0.4f, 0.6f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    ShaderProgram.Activate();
    VAO1.Bind();
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glDrawArrays(GL_TRIANGLES, 0, vert.size() / 3);
    glfwSwapBuffers(opengl.getWindow());
    glfwPollEvents();

    // std::cout << "circle1: ";
    // circle1.print();
    // std::cout << "circle2: ";
    // circle2.print();
    // if (circleIntersect(circle1, circle2)) {
    //   glm::vec3 colision_normal = collisionNormal(circle1, circle2);
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
