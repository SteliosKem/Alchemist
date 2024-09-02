#include "PointMass.h"

namespace Alchemist {
	void PointMass2D::integrate(Timestep dt) {
		// Update velocity
		m_velocity += m_acceleration * (float)dt;
		// Scale velocity down depending on damping factor
		m_velocity *= powf(m_damping, dt);

		// Update position
		m_position += m_velocity * (float)dt;
	}
}