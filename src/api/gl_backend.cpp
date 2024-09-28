#include "gl_backend.h"
#include <iostream>

const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";

namespace GLBackend
{
    GLuint _vertexDataVAO = 0;
    GLuint _vertexDataVBO = 0;
    GLuint _vertexDataEBO = 0;
    GLuint _vertexShader = 0;
    GLuint _fragmentShader = 0;
    GLuint _shaderProgram = 0;

    void init()
    {
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            G_ERROR("Failed to load glad\n");
            return;
        }

        GLint major, minor;
        glGetIntegerv(GL_MAJOR_VERSION, &major);
        glGetIntegerv(GL_MINOR_VERSION, &minor);
        const GLubyte* vendor = glGetString(GL_VENDOR);
        const GLubyte* renderer = glGetString(GL_RENDERER);
        std::cout << "\nGPU: " << renderer << "\n";
        std::cout << "GL Version " << major << "." << minor << "\n";

        // int flags;
        // glGetIntegerv(GL_CONTEXT_FLAGS, &flags); 
        // if (flags & GL_CONTEXT_FLAG_DEBUG_BIT){
        //     glEnable(GL_DEBUG_OUTPUT);
        //     glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
        // }

        _vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(_vertexShader, 1, &vertexShaderSource, nullptr);
        glCompileShader(_vertexShader);
        _fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(_fragmentShader, 1, &fragmentShaderSource, nullptr);
        glCompileShader(_fragmentShader);

        _shaderProgram = glCreateProgram();
        glAttachShader(_shaderProgram, _vertexShader);
        glAttachShader(_shaderProgram, _fragmentShader);
        glLinkProgram(_shaderProgram);

        glDeleteShader(_vertexShader);
        glDeleteShader(_fragmentShader);

        glClear(GL_COLOR_BUFFER_BIT);
    }

    void upload_vertex_data(std::vector<Vertex>& vertices, std::vector<uint32_t> indices)
    {
        if (_vertexDataVAO != 0) {
            glDeleteVertexArrays(1, &_vertexDataVAO);
            glDeleteBuffers(1, &_vertexDataVBO);
            glDeleteBuffers(1, &_vertexDataEBO);
        }

        glGenVertexArrays(1, &_vertexDataVAO);
        glGenBuffers(1, &_vertexDataVBO);
        glGenBuffers(1, &_vertexDataEBO);
        glUseProgram(_shaderProgram);
        glBindVertexArray(_vertexDataVAO);
        glBindBuffer(GL_ARRAY_BUFFER, _vertexDataVBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _vertexDataEBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(uint32_t), &indices[0], GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    GLuint get_vertex_data_vao()
    {
        return _vertexDataVAO;
    }

    GLuint get_vertex_data_vbo()
    {
        return _vertexDataVBO;
    }

    GLuint get_vertex_data_ebo()
    {
        return _vertexDataEBO;
    }
}