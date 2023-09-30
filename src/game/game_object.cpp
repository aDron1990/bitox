#include "bitox/game/game_object.hpp"
#include "bitox/engine/state.hpp"


bitox::game::game_object::game_object()
{
	entity = get_ecs()->create_entity();
}

bitox::game::game_object::~game_object()
{
	get_ecs()->destroy_entity(entity);
};

void bitox::game::game_object::add_component(ecs::component* component)
{
	get_ecs()->add_component(entity, component);
}

void bitox::game::game_object::remove_component(const std::string& name)
{
	get_ecs()->remove_component(entity, name);
}

bitox::ecs::component* bitox::game::game_object::get_component(const std::string& name)
{
	return get_ecs()->get_component(entity, name);
}