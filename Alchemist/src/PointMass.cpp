#include "PointMass.h"

namespace Alchemist {
	void PointMass2D::integrate(float dt) {
		// Update velocity
		m_velocity += m_acceleration * dt;
		// Scale velocity down depending on damping factor
		m_velocity *= powf(m_damping, dt);

		// Update position
		m_position += m_velocity * dt;
	}
}