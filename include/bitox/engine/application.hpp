#pragma once

#include "bitox/api.hpp"
#include "bitox/engine/window.hpp"

namespace bitox
{
    class BITOX_API application
    {
    private:

        bool running = true;

    public:

        application();
        virtual ~application();

        void run();

        virtual void on_close() { close(); };
        void close() { running = false; };

    };

    application* create_app(int argc, char** argv);
}
