#pragma once

#include "../common.h"
#include <vector>

namespace GLBackend
{
    void init();
    void rebind_buffers();

    GLuint get_vertex_data_vao();
    GLuint get_vertex_data_vbo();
    GLuint get_vertex_data_ebo();
}