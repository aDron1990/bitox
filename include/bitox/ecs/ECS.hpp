#pragma once

#include "bitox/ecs/ecs_manager.hpp"
#include "bitox/ecs/system.hpp"

namespace bitox::ecs
{
	class ECS
	{
	private:

		static ecs_manager* manager;

	public:

		void initialize();
		void terminate();

		void update();

	};
}