#include "bitox/engine/application.hpp"
#include "bitox/engine/__state_instance.hpp"
#include "bitox/engine/state.hpp"
#include "bitox/graphics/ogl_render_system.hpp"
#include "bitox/engine/input_system.hpp"

#include <GLFW/glfw3.h>

void window_close_callback(GLFWwindow* window);

bitox::application::application()
{
	glfwInit();
    
	state.window_ = std::make_shared<window>( 800, 600, "test" );
	state.ecs_ = std::make_shared<ecs::ecs_manager>();
    state.input_ =  std::make_shared<input_system>();
	state.ecs_->add_system(new bitox::graphics::ogl_render_system);
    state.ecs_->add_system(state.input_.get());
	state.ecs_->create_component("ogl_renderer");
	state.ecs_->create_component("transform");
    state.ecs_->create_component("input");

	glfwSetWindowCloseCallback(state.window_.get()->window_handle_.get(), window_close_callback);

}

bitox::application::~application()
{
	glfwTerminate();
}

void bitox::application::run()
{
	while (running)
	{
		glfwPollEvents();
		state.ecs_->update();
		state.window_->swap_buffers();
	}
}

void window_close_callback(GLFWwindow* window)
{
	state.app_->on_close();
}