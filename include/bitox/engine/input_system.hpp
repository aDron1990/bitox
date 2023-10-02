#pragma once

#include "bitox/ecs/system.hpp"

namespace bitox
{
    class input_system : public bitox::ecs::system
    {
    private:

        bool key[128];
        bool key_down[128];
        bool key_up[128];       

        bool has_event = false;

    public:

        struct input_event : public game::scene_node::event_t
        {
            int key;
            int scancode;
            int action;
            int mods;
        };
        
        input_event event;

        input_system();

        void on_component_update(ecs::component* component_) override;
        void after_update() override;
        
        void set_input(int key, int scancode, int action, int mods);

    };
}

