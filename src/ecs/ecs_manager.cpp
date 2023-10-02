#include "bitox/ecs/ecs_manager.hpp"
#include "bitox/engine/state.hpp"

#include <iostream>

bitox::ecs::ecs_manager* bitox::ecs::ecs_manager::instance_ = nullptr;

bitox::ecs::ecs_manager::~ecs_manager()
{
	for (auto&& i : entity_ids_)
	{
		for (auto&& j : i.second)
		{
			delete j;
		}
	}
}

void  bitox::ecs::ecs_manager::add_system(system* sys)
{
	systems_.push_back(sys);
}

void  bitox::ecs::ecs_manager::remove_system(const system* sys)
{
	systems_.erase(std::find(systems_.begin(), systems_.end(), sys));
}

id_t bitox::ecs::ecs_manager::create_entity()
{
	entity_ids_[entity_next_id_] = std::vector<component*>{};
	return entity_next_id_++;
}

void bitox::ecs::ecs_manager::destroy_entity(id_t entity_id)
{
	for (auto& it : entity_ids_[entity_id])
	{
		components_.erase(it->get_name());
		delete it;
	}

	entity_ids_.erase(entity_id);
}

void bitox::ecs::ecs_manager::create_component(const std::string& component_name)
{
	components_[component_name] = std::vector<component*>{};
}

void bitox::ecs::ecs_manager::destroy_component(const std::string& component_name)
{
	auto it = components_.find(component_name);
	for (auto&& i : it->second)
	{
		delete i;
	}

	components_.erase(it->first);
}

void bitox::ecs::ecs_manager::add_component(id_t entity_id, component* component)
{
	if (entity_ids_.find(entity_id) != entity_ids_.end())
	{
		auto& components = entity_ids_[entity_id];
		for (auto&& i : components)
		{
			if (i->name_ == component->name_)
			{
				delete component;
				return;
			}
		}

		component->owner_entity_ = entity_id;
		components.push_back(component);
		components_[component->name_].push_back(component);
	}
}

void bitox::ecs::ecs_manager::remove_component(id_t entity_id, const std::string& component_name)
{
	if (entity_ids_.find(entity_id) != entity_ids_.end())
	{
		for (auto&& i : entity_ids_[entity_id])
		{
			if (i->name_ == component_name)
			{
				delete i;
				entity_ids_[entity_id].erase(std::find(entity_ids_[entity_id].begin(), entity_ids_[entity_id].end(), i));
				auto q = std::find(components_[component_name].begin(), components_[component_name].end(), i);
				components_[component_name].erase(q);
				break;
			}
		}
	}
}

bitox::ecs::component* bitox::ecs::ecs_manager::get_component(id_t entity_id, const std::string& component_name)
{
	if (entity_ids_.find(entity_id) != entity_ids_.end())
	{
		auto& components = entity_ids_[entity_id];
		for (auto&& i : components)
		{
			if (i->name_ == component_name)
			{
				return i;
			}
		}
	}
	return nullptr;
}

void bitox::ecs::ecs_manager::update()
{
	for (auto&& sys : systems_)
	{
		sys->before_update();
		for (auto&& target_component : components_[sys->target_component_name_])
		{
			id_t owner = target_component->get_entity();
			bool work_with_component = true;
			for (auto&& other_component : sys->other_required_components_names_)
			{
				if (get_component(owner, other_component) == nullptr) work_with_component = false;
			}
			if (!work_with_component) continue;
			sys->on_component_update(target_component);
		}
		sys->after_update();
	}
}