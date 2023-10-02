#pragma once

#include "bitox/ecs/id_type.hpp"
#include "bitox/game/scene_node.hpp"

#include <string>

namespace bitox::ecs
{
	class component
	{
		friend class ecs_manager;

	private:

		const std::string name_;
		id_t owner_entity_ = -1;

    protected:

        game::scene_node* owner_ = nullptr;

	public:

		component(const std::string& name) : name_{ name } {};
		virtual ~component() = default;
		const std::string& get_name() const { return name_; };
		id_t get_entity() const { return owner_entity_; }
        game::scene_node* get_owner() const { return owner_; };

	};
}