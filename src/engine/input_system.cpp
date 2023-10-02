#include "bitox/engine/input_system.hpp"
#include "bitox/engine/state.hpp"

#include <GLFW/glfw3.h>
#include <iostream>

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

bitox::input_system::input_system() : system{"input"}
{
    glfwSetKeyCallback(get_window()->window_handle_.get(), key_callback);
}

void bitox::input_system::on_component_update(ecs::component* component_)
{
    if (has_event) component_->get_owner()->on_event(event);
}

void bitox::input_system::after_update()
{
    has_event = false;
}

void bitox::input_system::set_input(int key, int scancode, int action, int mods)
{
    has_event = true;
    event.event_type = 1;
    event.key = key;
    event.scancode = scancode;
    event.action = action;
    event.mods = mods;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    bitox::get_input()->set_input(key, scancode, action, mods);
}