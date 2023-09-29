#include "bitox/engine/window.hpp"

#include <GLFW/glfw3.h>

bitox::window::window(const int widht, const int height, const std::string& title)
{
    window_handle_ = std::unique_ptr<GLFWwindow, void (*)(GLFWwindow*)>(glfwCreateWindow(widht, height, title.c_str(), nullptr, nullptr), glfwDestroyWindow);
}

void bitox::window::swap_buffers() const
{
    glfwSwapBuffers(window_handle_.get());
}