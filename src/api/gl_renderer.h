#pragma once

#include <vector>
#include "gl_backend.h"
#include "../types/types.hpp"

namespace GLRenderer
{
    void init();
    void render_frame(RenderData render_data, std::vector<uint32_t> indices);
}