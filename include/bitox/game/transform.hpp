#pragma once

#include "bitox/ecs/component.hpp"

#include <glm/glm.hpp>

namespace bitox::game
{
	class transform : public ecs::component
	{
	public:

		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;

		transform() : component{ "transform" }, position{ 0.0f }, rotation{ 0.0f }, scale{ 1.0f } {}

	};
}