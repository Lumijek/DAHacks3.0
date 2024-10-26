// RingMesh.h

#ifndef RINGMESH_H
#define RINGMESH_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <vector>

class RingMesh {
public:
  RingMesh(float innerRadius, float outerRadius, int segments = 64);
  ~RingMesh();

  void Draw();

private:
  unsigned int VAO, VBO, EBO;
  int indexCount;
};

#endif // RINGMESH_H
