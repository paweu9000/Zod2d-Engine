#pragma once
#include "../common.h"
#include "../types/types.hpp"

namespace Game
{
    void init();
    void update();
    float get_delta_time();
    // FUTURE TODO: 
    RenderData get_render_data();
    // Retrieve all vertices colors etc to do 1 big draw call for faster rendering
}