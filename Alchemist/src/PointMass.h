#pragma once
#include "glm/glm.hpp"
#include "Timestep.h"

namespace Alchemist {
	class PointMass2D {
	public:
	private:
		void integrate(Timestep dt);
	private:
		glm::vec2 m_position;
		glm::vec2 m_velocity;
		glm::vec2 m_acceleration;

		// The closest damping is to 1, the lower the effect of it
		float m_damping = 1;

		// Holds the inverse of the point's mass, since it is more useful for calculations
		float m_mass_inverse;
	};
}