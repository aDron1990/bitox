#include "bitox/engine/application.hpp"
#include "bitox/engine/state.hpp"
#include "bitox/engine/__state_instance.hpp"

#include <iostream>

extern bitox::application* bitox::create_app(int argc, char** argv);

int main(int argc, char** argv)
{
    state.app_ = std::shared_ptr<bitox::application>{ bitox::create_app(argc, argv) };
    state.app_->run();
}