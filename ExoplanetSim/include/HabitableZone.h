// HabitableZone.h

#ifndef HABITABLEZONE_H
#define HABITABLEZONE_H

#include "RingMesh.h"
#include "Shader.h"

class HabitableZone {
public:
  HabitableZone(float innerRadius, float outerRadius, Shader *shader);
  ~HabitableZone();

  void Draw(const glm::mat4 &view, const glm::mat4 &projection);

  // Method to update radii
  void UpdateRadii(float innerRadius, float outerRadius);

private:
  RingMesh *ringMesh;
  Shader *shader;
  glm::mat4 modelMatrix;
};

#endif // HABITABLEZONE_H
