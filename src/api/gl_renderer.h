#pragma once

#include <vector>
#include "gl_backend.h"

namespace GLRenderer
{
    void init();
    void render_frame(std::vector<Vertex> vertices, std::vector<uint32_t> indices);
}