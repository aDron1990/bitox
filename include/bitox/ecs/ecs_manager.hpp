#pragma once

#include "bitox/ecs/component.hpp"
#include "bitox/ecs/id_type.hpp"
#include "bitox/ecs/system.hpp"

#include <map>
#include <vector>

namespace bitox::ecs
{
	class ecs_manager
	{
	private:

		std::map<id_t, std::vector<component*>> entity_ids_;        //  -\_____ refences to one memory, copy from instances        
		std::map<std::string, std::vector<component*>> components_; //  -/

		std::vector<system*> systems_;

		id_t entity_next_id_ = 0;

	public:

		id_t create_entity();
		void destroy_entity(id_t entity_id);

		void add_system(system* sys);
		void remove_system(const system* sys);

		void create_component(const std::string& component_name);
		void destroy_component(const std::string& component_name);

		void add_component(id_t entity_id, component* component);
		void remove_component(id_t entity_id, const std::string& component_name);
		component* get_component(id_t entity_id, const std::string& component_name);

		void update();

		~ecs_manager();
	};
}