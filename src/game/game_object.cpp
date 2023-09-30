#include "bitox/game/game_object.hpp"
#include "bitox/engine/state.hpp"

#include "bitox/graphics/ogl_renderer.hpp"

bitox::game::game_object::game_object()
{
	//entity = create_entity();
}

bitox::game::game_object::~game_object()
{
	bitox::get_ecs()->destroy_entity(entity);
}

id_t bitox::game::game_object::create_entity()
{
	return bitox::get_ecs()->create_entity();
}

void bitox::game::game_object::add_component(id_t entity, ecs::component* component)
{
	bitox::get_ecs()->add_component(entity, component);
}

void bitox::game::game_object::remove_component(const std::string& component)
{
	bitox::get_ecs()->remove_component(entity, component);
}

bitox::ecs::component* bitox::game::game_object::get_component(const std::string& component)
{
	return bitox::get_ecs()->get_component(entity, component);
}