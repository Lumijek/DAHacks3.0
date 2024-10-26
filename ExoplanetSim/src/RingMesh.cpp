// RingMesh.cpp

#include "RingMesh.h"
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>

RingMesh::RingMesh(float innerRadius, float outerRadius, int segments) {
	std::vector<glm::vec3> vertices;
	std::vector<unsigned int> indices;

	float deltaAngle = 2.0f * glm::pi<float>() / segments;

	// Generate vertices
	for (int i = 0; i <= segments; ++i) {
		float angle = i * deltaAngle;
		float xInner = innerRadius * cos(angle);
		float zInner = innerRadius * sin(angle);
		float xOuter = outerRadius * cos(angle);
		float zOuter = outerRadius * sin(angle);

		// Inner vertex
		vertices.emplace_back(glm::vec3(xInner, 0.0f, zInner));
		// Outer vertex
		vertices.emplace_back(glm::vec3(xOuter, 0.0f, zOuter));
	}

	// Generate indices for triangles
	for (int i = 0; i < segments * 2; i += 2) {
		indices.push_back(i);
		indices.push_back(i + 1);
		indices.push_back(i + 2);

		indices.push_back(i + 1);
		indices.push_back(i + 3);
		indices.push_back(i + 2);
	}

	indexCount = static_cast<int>(indices.size());

	// Setup OpenGL buffers and arrays
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	// Vertex buffer
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3),
	             vertices.data(), GL_STATIC_DRAW);

	// Element buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int),
	             indices.data(), GL_STATIC_DRAW);

	// Vertex attributes
	glEnableVertexAttribArray(0); // Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void *)0);

	glBindVertexArray(0);
}

RingMesh::~RingMesh() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

void RingMesh::Draw() {
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}
