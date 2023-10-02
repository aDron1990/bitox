#pragma once

namespace bitox::game
{
	class scene_node
	{
	public:

        struct event_t
        {
            int event_type = 0;
            void* data = nullptr;
        };



		virtual ~scene_node() = default;
        virtual void on_event(const event_t& event) {};
	};
}