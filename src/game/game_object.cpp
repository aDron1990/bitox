#include "bitox/game/game_object.hpp"
#include "bitox/engine/state.hpp"
#include "bitox/ecs/ecs_manager.hpp"

bitox::game::game_object::game_object()
{
	entity = get_ecs()->create_entity();
}

void bitox::game::game_object::add_component(ecs::component* component)
{
	get_ecs()->add_component(entity, component);
}