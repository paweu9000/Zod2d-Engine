#pragma once
#include "../common.h"
#include "../math.hpp"
#include "../input/input.h"
#include "../defines.h"
#include "../types/types.hpp"
#include "../utils.hpp"

namespace Player
{
    void init();
    void update();
    void process_input();
    RenderData get_render_data();
}