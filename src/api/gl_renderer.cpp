#include "gl_renderer.h"
#include <iostream>
#include <functional>
#include "../core/asset_manager.h"

enum ErrorType {
    SHADER, PROGRAM
};

namespace GLRenderer
{
    GLuint _shaderProgram = 0;

    const char* vertexShaderSource = "#version 460 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec2 aTexCoord;\n"
    "out vec2 TexCoord;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos, 1.0);\n"
    "   TexCoord = aTexCoord;\n"
    "}\0";
    const char* fragmentShaderSource = "#version 460 core\n"
    "out vec4 FragColor;\n"
    "in vec2 TexCoord;\n"
    "uniform sampler2D tex;\n"
    "void main()\n"
    "{\n"
    "   FragColor = texture(tex, TexCoord) * vec4(1.f, 1.f, 0.f, 1.f);\n"
    "}\n\0";

    void init()
    {
        load_shaders();
        AssetManager::load_textures();
    }

    void load_shaders()
    {
        auto _checkErrors = [](GLuint id, ErrorType type) {
            int success;
            char infoLog[512];
            if (type == SHADER) {
                glGetShaderiv(id, GL_COMPILE_STATUS, &success);
                if (!success) {
                    glGetShaderInfoLog(id, 512, nullptr, infoLog);
                    G_ERROR(infoLog);
                }
            } else {
                glGetProgramiv(id, GL_LINK_STATUS, &success);
                if (!success) {
                    glGetProgramInfoLog(id, 512, nullptr, infoLog);
                    G_ERROR(infoLog);
                }
            }
        };

        GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
        glCompileShader(vertexShader);
        _checkErrors(vertexShader, SHADER);

        GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
        glCompileShader(fragmentShader);
        _checkErrors(fragmentShader, SHADER);

        _shaderProgram = glCreateProgram();
        glAttachShader(_shaderProgram, vertexShader);
        glAttachShader(_shaderProgram, fragmentShader);
        glLinkProgram(_shaderProgram);
        _checkErrors(_shaderProgram, PROGRAM);

        glDeleteShader(fragmentShader);
        glDeleteShader(vertexShader);
    }

    void render_frame(std::vector<Vertex> vertices, std::vector<uint32_t> indices)
    {
        glUseProgram(_shaderProgram);
        glBindVertexArray(GLBackend::get_vertex_data_vao());
        glBindBuffer(GL_ARRAY_BUFFER, GLBackend::get_vertex_data_vbo());
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, GLBackend::get_vertex_data_ebo());
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(uint32_t), &indices[0], GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, textureCoords));

        glUniform1i(glGetUniformLocation(_shaderProgram, "tex"), 0);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, AssetManager::get_texture("pope"));
        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }
}