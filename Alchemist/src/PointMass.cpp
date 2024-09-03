#include "PointMass.h"

namespace Alchemist {
	void PointMass2D::integrate(float dt) {
		glm::vec2 final_acceleration = m_acceleration + m_force_accumulator * m_mass_inverse;
		// Update velocity
		m_velocity += final_acceleration * dt;
		// Scale velocity down depending on damping factor
		m_velocity *= powf(m_damping, dt);

		// Update position
		m_position += m_velocity * dt;

		// Zero out forces
		clear_force_accumulator();
	}

	void ForceRegistry::update_forces(float dt) {
		for (const auto& i : registrations) {
			i.force_generator->update_force(i.point_mass, dt);
		}
	}

	void PointMassGravity::update_force(PointMass2D* point_mass, float dt) {
		point_mass->add_force(m_gravity * point_mass->get_mass());
	}
}