#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

class Graphic {
 private:
  GLFWwindow* window;
  int width;
  int height;

 public:
  Graphic(int Twidth, int Theight);
  bool initWindow();
  bool initGlad();
  GLFWwindow* getWindow();
  void processInput();
  void cleanup();
};
