#pragma once

#include "bitox/ecs/id_type.hpp"
#include "bitox/ecs/component.hpp"

#include <string>

namespace bitox::game
{
	class game_object
	{
	private:

		

	public:

		id_t entity;

		game_object();
		~game_object();

		void add_component(id_t entity, ecs::component* component);
		void remove_component(const std::string& component);
		ecs::component* get_component(const std::string& component);
		id_t create_entity();

		//virtual void on_event();

	};
}