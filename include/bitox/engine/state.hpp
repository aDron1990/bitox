#pragma once

#include "bitox/engine/state.hpp"
#include "bitox/engine/window.hpp"
#include "bitox/engine/application.hpp"
#include "bitox/engine/input_system.hpp"
#include "bitox/ecs/ecs_manager.hpp"

#include <memory>

namespace bitox
{
    struct state_t
    {
        std::shared_ptr<application> app_;
        std::shared_ptr<window> window_;
        std::shared_ptr<ecs::ecs_manager> ecs_;
        std::shared_ptr<input_system> input_;
    };

    std::shared_ptr<application> get_app();
    std::shared_ptr<window> get_window();
    std::shared_ptr<ecs::ecs_manager> get_ecs();
    std::shared_ptr<input_system> get_input();
}