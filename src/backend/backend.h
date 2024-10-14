#pragma once
#include "../math.hpp"

namespace Backend
{
    void init();
    void begin_frame();
    void end_frame();
    void create_window();
    bool is_running();
    void cleanup();
    Math::Vec2<int> get_screen_size();
}