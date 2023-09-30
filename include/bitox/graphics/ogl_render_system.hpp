#pragma once

#include "memory"

#include "bitox/ecs/system.hpp"
#include "bitox/graphics/shader.hpp"

namespace bitox::graphics
{
	class ogl_render_system : public ecs::system
	{
	private:

		std::shared_ptr<shader> program;
		unsigned int VBO, VAO;

	public:

		ogl_render_system();
		
		void before_update() override;
		void on_component_update(ecs::component* component) override;
		
	};
}