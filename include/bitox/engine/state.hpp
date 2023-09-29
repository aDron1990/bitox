#pragma once

#include "bitox/engine/state.hpp"
#include "bitox/engine/window.hpp"
#include "bitox/engine/application.hpp"

#include <memory>

namespace bitox
{
    struct state_t
    {
        std::shared_ptr<application> app_;
        std::shared_ptr<window> window_;
    };

    std::shared_ptr<application> get_app();
    std::shared_ptr<window> get_window();

}