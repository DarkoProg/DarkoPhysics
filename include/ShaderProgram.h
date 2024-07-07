#include <glad/glad.h>

#include <cerrno>
#include <string>
#pragma once

std::string get_file_contents(const char* filename);

class Shader {
 public:
  // Reference ID of the Shader Program
  GLuint ID;
  // Constructor that build the Shader Program from 2 different shaders
  Shader();
  Shader(const char* vertexFile, const char* fragmentFile,
         const char* tessalationControlFile,
         const char* tessalationEvaluationFile);
  Shader(const char* vertexFile, const char* fragmentFile);

  // Activates the Shader Program
  void Activate();
  // Deletes the Shader Program
  void Delete();

 private:
  // Checks if the different Shaders have compiled properly
  void compileErrors(unsigned int shader, const char* type);
};
