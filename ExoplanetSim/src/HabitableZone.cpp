// HabitableZone.cpp

#include "HabitableZone.h"

HabitableZone::HabitableZone(float innerRadius, float outerRadius,
                             Shader *shader)
	: shader(shader) {
	ringMesh = new RingMesh(innerRadius, outerRadius);
	modelMatrix = glm::mat4(1.0f); // Identity matrix
}

HabitableZone::~HabitableZone() {
	delete ringMesh;
}

void HabitableZone::Draw(const glm::mat4 &view, const glm::mat4 &projection) {
	shader->use();
	shader->setMat4("model", modelMatrix);
	shader->setMat4("view", view);
	shader->setMat4("projection", projection);

	// Set color and transparency
	shader->setVec4(
		"color", glm::vec4(0.0f, 1.0f, 0.0f, 0.4f)); // Green color, 40% opacity

	// Enable blending for transparency
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	ringMesh->Draw();

	// Disable blending
	glDisable(GL_BLEND);
}

void HabitableZone::UpdateRadii(float innerRadius, float outerRadius) {
	delete ringMesh;
	ringMesh = new RingMesh(innerRadius, outerRadius);
}
