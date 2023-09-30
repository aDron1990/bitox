#pragma once

#include "bitox/ecs/id_type.hpp"

#include <string>

namespace bitox::ecs
{
	class component
	{
		friend class ecs_manager;

	private:

		const std::string name_;
		id_t owner_entity_ = -1;

	public:

		component(const std::string& name) : name_{ name } {};
		virtual ~component() = default;
		const std::string& get_name() const { return name_; };
		id_t get_entity() const { return owner_entity_; }

	};
}