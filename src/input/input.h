#pragma once
#include "keycodes.h"
#include "../math.hpp"

namespace Input
{
    void init();
    void update();
    bool key_pressed(unsigned int keycode);
    bool key_down(unsigned int keycode);
    Math::Vec2<double> get_cursor_location();
}