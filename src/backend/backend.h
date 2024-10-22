#pragma once
#include "../common.h"
#include "../math.hpp"
#include <glfw3.h>

namespace Backend
{
    void init();
    void begin_frame();
    void end_frame();
    void create_window();
    bool is_running();
    void cleanup();
    Math::Vec2<int> get_screen_size();
    GLFWwindow* get_window_pointer();
    void close_window();
}