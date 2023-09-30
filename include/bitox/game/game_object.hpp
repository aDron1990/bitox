#pragma once

#include "bitox/ecs/id_type.hpp"
#include "bitox/ecs/component.hpp"

namespace bitox::game
{
	class game_object
	{
	public:
		game_object();

		id_t entity;

		void add_component(ecs::component* component);

	};
}