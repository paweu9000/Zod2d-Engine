#include "backend.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

namespace Backend
{
    //###########################################
    //              VARIABLES
    //##########################################
    
    GLFWwindow* _window = nullptr;
    GLFWmonitor* _monitor;
    const GLFWvidmode* _mode;
    int _width = 0;
    int _height = 0;
    bool _is_running;

    //##############################
    //              CORE
    //##############################

    void init() {
        glfwInit();

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_CORE_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);

        glfwWindowHint(GLFW_VISIBLE, GLFW_TRUE);
        glfwWindowHint(GLFW_FOCUS_ON_SHOW, GLFW_TRUE);
        _monitor = glfwGetPrimaryMonitor();
        _mode = glfwGetVideoMode(_monitor);
        glfwWindowHint(GLFW_RED_BITS, _mode->redBits);
        glfwWindowHint(GLFW_GREEN_BITS, _mode->greenBits);
        glfwWindowHint(GLFW_BLUE_BITS, _mode->blueBits);
        glfwWindowHint(GLFW_REFRESH_RATE, _mode->refreshRate);
        _width = _mode->width;
        _height = _mode->height;
        _is_running = true;
        Backend::create_window();
        G_ASSERT(_window != NULL);

        glfwSetFramebufferSizeCallback(_window, framebuffer_size_callback);

        glfwMakeContextCurrent(_window);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            G_ERROR("Failed to load GLAD");
        }

        glViewport(0, 0, _width, _height);
    }

    void create_window() {
        _window = glfwCreateWindow(_width, _height, "Gaem", nullptr, nullptr);
    }

    void begin_frame() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glfwPollEvents();
    }

    void end_frame() {
        glfwSwapBuffers(_window);
    }

    bool is_running() {
        return _is_running;
    }

    void cleanup() {
        glfwTerminate();
    }

    Math::Vec2<int> get_screen_size()
    {
        return {_width, _height};
    }

    GLFWwindow* get_window_pointer()
    {
        return _window;
    }

    void close_window()
    {
        _is_running = false;
    }
}