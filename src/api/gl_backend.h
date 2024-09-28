#pragma once

#include "../common.h"
#include <vector>

namespace GLBackend
{
    void init();
    void upload_vertex_data(std::vector<Vertex>& vertices, std::vector<uint32_t> indices);

    GLuint get_vertex_data_vao();
    GLuint get_vertex_data_vbo();
    GLuint get_vertex_data_ebo();
}