#include "gl_backend.h"
#include <iostream>

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

        glClear(GL_COLOR_BUFFER_BIT);
    }

    void rebind_buffers()
    {
        if (_vertexDataVAO != 0) {
            glDeleteVertexArrays(1, &_vertexDataVAO);
            glDeleteBuffers(1, &_vertexDataVBO);
            glDeleteBuffers(1, &_vertexDataEBO);
        }

        glGenVertexArrays(1, &_vertexDataVAO);
        glGenBuffers(1, &_vertexDataVBO);
        glGenBuffers(1, &_vertexDataEBO);
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