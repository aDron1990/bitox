#pragma once

#include "bitox/ecs/component.hpp"
#include "bitox/graphics/shader.hpp"

#include <memory>

namespace bitox::graphics
{
	class ogl_renderer : public ecs::component
	{
	public:

		ogl_renderer() : component{ "ogl_renderer" } {};
		std::unique_ptr<shader> program;


	};
}