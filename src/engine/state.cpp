#include "bitox/engine/state.hpp"
#include "bitox/engine/__state_instance.hpp"

bitox::state_t state = bitox::state_t{};

std::shared_ptr<bitox::application> bitox::get_app()
{
    return state.app_;
}

std::shared_ptr<bitox::window> bitox::get_window()
{
    return state.window_;
}

std::shared_ptr<bitox::ecs::ecs_manager> bitox::get_ecs()
{
    return state.ecs_;
}

std::shared_ptr<bitox::input_system> bitox::get_input()
{
    return state.input_;
}