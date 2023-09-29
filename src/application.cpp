#include "bitox/engine/application.hpp"
#include "bitox/engine/__state_instance.hpp"
#include "bitox/engine/state.hpp"

#include <GLFW/glfw3.h>

bitox::application::application()
{
	glfwInit();
	state.window_ = std::make_shared<window>( 800, 600, "test" );
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
		state.window_->swap_buffers();
	}
}