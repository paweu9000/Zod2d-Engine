#pragma once
#include <glm.hpp>

namespace Backend
{
    void init();
    void begin_frame();
    void end_frame();
    void create_window();
    bool is_running();
    void cleanup();
    glm::vec2 get_screen_size();
}