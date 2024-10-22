#include "gl_renderer.h"
#include <iostream>
#include <functional>
#include "../core/asset_manager.h"
#include "../types/shader.h"

namespace GLRenderer
{
    Shader _shader;

    void init()
    {
        std::string vert_path("shaders/vertex.vert");
        std::string frag_path("shaders/fragment.frag");
        _shader.load(vert_path, frag_path);
        AssetManager::load_textures();

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }

    void render_frame(RenderData render_data, std::vector<uint32_t> indices)
    {
        _shader.use();
        glBindVertexArray(GLBackend::get_vertex_data_vao());
        glBindBuffer(GL_ARRAY_BUFFER, GLBackend::get_vertex_data_vbo());
        glBufferData(GL_ARRAY_BUFFER, render_data.vertices.size() * sizeof(Vertex), &render_data.vertices[0], GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, GLBackend::get_vertex_data_ebo());
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(uint32_t), &indices[0], GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, textureCoords));

        _shader.set_int("tex", 0);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, AssetManager::get_texture(render_data.texture));
        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }
}