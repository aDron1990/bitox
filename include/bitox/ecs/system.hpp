#pragma once

#include "component.hpp"

#include <string>
#include <vector>

namespace bitox::ecs
{
	class system
	{
		friend class ecs_manager;
	private:

		std::string target_component_name_;
		std::vector<std::string> other_required_components_names_;

	public:

		system(const std::string& target_component_name, const std::initializer_list<std::string>& other_required_components_names = {});
		virtual void on_component_update(component* component_) = 0;

	};
}