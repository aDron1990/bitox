#include "bitox/engine/state.hpp"
#include "bitox/engine/__state_instance.hpp"

std::shared_ptr<bitox::application> bitox::get_app()
{
    return state.app_;
}

std::shared_ptr<bitox::window> bitox::get_window()
{
    return state.window_;
}