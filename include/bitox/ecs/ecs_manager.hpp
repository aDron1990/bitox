#pragma once

#include "bitox/ecs/component.hpp"
#include "bitox/ecs/id_type.hpp"
#include "bitox/ecs/system.hpp"

#include <map>
#include <vector>
#include <assert.h>

namespace bitox::ecs
{
	class ecs_manager
	{
	private:

		std::map<lid_t, std::vector<component*>> entity_ids_;        //  -\_____ refences to one memory, copy from instances        
		std::map<std::string, std::vector<component*>> components_; //  -/

		std::vector<system*> systems_;
		static ecs_manager* instance_;
		lid_t entity_next_id_ = 0;

	public:

		lid_t create_entity();
		void destroy_entity(lid_t entity_id);

		void add_system(system* sys);
		void remove_system(const system* sys);

		void create_component(const std::string& component_name);
		void destroy_component(const std::string& component_name);

		void add_component(lid_t entity_id, component* component);
		void remove_component(lid_t entity_id, const std::string& component_name);
		component* get_component(lid_t entity_id, const std::string& component_name);

		void update();

		~ecs_manager();
	};
}