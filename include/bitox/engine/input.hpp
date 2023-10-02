#pragma once

#include "bitox/ecs/component.hpp"
#include "bitox/game/scene_node.hpp"

namespace bitox
{
    class input : public ecs::component
    {
    public:

        input(game::scene_node* node) : component("input")
        {
            owner_ = node;
        }
    };
}
