#pragma once

#include "bitox/ecs/id_type.hpp"
#include "bitox/game/scene_node.hpp"
#include "bitox/ecs/component.hpp"

namespace bitox::game
{
	class game_object : public scene_node
	{
	public:

		lid_t entity;

	public:
		

        

		game_object();
		virtual ~game_object();

		void add_component(ecs::component* component);
		void remove_component(const std::string& name);
		ecs::component* get_component(const std::string& name);

        

	};
}