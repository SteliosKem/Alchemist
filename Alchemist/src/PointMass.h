#pragma once
#include "glm/glm.hpp"
#include "Timestep.h"

namespace Alchemist {
	class PointMass2D {
	public:
		PointMass2D(float mass_inverse, float damping = 1, const glm::vec2& acceleration = {0.0f, 0.0f}, 
			const glm::vec2& velocity = { 0.0f, 0.0f }, const glm::vec2& position = { 0.0f, 0.0f })
			: m_acceleration{ acceleration }, m_velocity{ velocity }, m_position{ position }
			, m_mass_inverse{ mass_inverse }, m_damping{damping} {}

		void set_acceleration(const glm::vec2& a) { m_acceleration = a; }
		void set_velocity(const glm::vec2& a) { m_velocity = a; }
		void set_position(const glm::vec2& a) { m_position = a; }
		void set_mass(float mass) { m_mass_inverse = 1 / mass; }
		void set_damp(float damp) { m_damping = damp; }

		glm::vec2 get_position() const { return m_position; }
		glm::vec2 get_velocity() const { return m_velocity; }
		glm::vec2 get_acceleration() const { return m_acceleration; }
		float get_mass() const { return 1 / m_mass_inverse; }
		float get_damping() const { return m_damping; }
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