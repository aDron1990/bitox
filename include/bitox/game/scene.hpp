#pragma once

#include "bitox/game/scene_node.hpp"
//#include "bitox/game/game_object.hpp"

#include <ntree.hpp>

#include <memory>

namespace bitox::game
{
	class scene
	{
	private:

	public:

		forest::ntree<std::shared_ptr<scene_node>> scene_tree;

		scene();
		virtual ~scene() = default;


	};
}