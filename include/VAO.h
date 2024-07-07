#ifndef VAO_CLASS_H
#define VAO_CLASS_H

#include "VBO.h"
#include "glad/glad.h"

class VAO {
 public:
  // ID reference for the Vertex Array Object
  GLuint ID;
  // Constructor that generates a VAO ID
  VAO();

  // Links a VBO to the VAO using a certain layout
  /* void LinkVBO(VBO& VBO, GLuint layout); */
  /* void LinkAttribute(VBO& VBO, GLuint layout, GLuint numComponents, GLenum
   * type, GLsizeiptr, void* offset); */
  void LinkAttribute(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type,
                     GLsizeiptr stride, void* offset);
  // Binds the VAO
  void Bind();
  // Unbinds the VAO
  void Unbind();
  // Deletes the VAO
  void Delete();
};
#endif
