#pragma once

#include "bitox/api.hpp"

#include <memory>
#include <string>

struct GLFWwindow;
extern "C" void glfwDestroyWindow(GLFWwindow * window);

namespace bitox
{
    class window
    {
    private:

        using glfw_window_ptr = std::unique_ptr<GLFWwindow, void (*) (GLFWwindow*)>;
        glfw_window_ptr window_handle_ = glfw_window_ptr(nullptr, glfwDestroyWindow);

    public:

        window(const int widht, const int height, const std::string& title);

        void swap_buffers() const;

    };
}