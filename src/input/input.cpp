#include "input.h"
#include <glfw3.h>

namespace Input
{
    bool _key_pressed[372];
    bool _key_down[372];
    bool _key_down_last_frame[372];
    GLFWwindow* _window;
    Math::Vec2<double> _cursor_pos;

    void init()
    {
        _window = Backend::get_window_pointer();
        glfwSetCursorPos(_window, _cursor_pos.x, _cursor_pos.y);
    }

    void update()
    {
        if (key_pressed(ZODD_KEY_ESCAPE)) {
            Backend::close_window();
        }

        for (int i = 32; i < 349; ++i) {
            if (glfwGetKey(_window, i) == GLFW_PRESS) {
                _key_down[i] = true;
            } else {
                _key_down[i] = false;
            }

            if (_key_down[i] && !_key_down_last_frame[i]) {
                _key_pressed[i] = true;
            } else {
                _key_pressed[i] = false;
            }

            _key_down_last_frame[i] = _key_down[i];
        }

        glfwGetCursorPos(_window, &_cursor_pos.x, &_cursor_pos.y);
    }

    bool key_pressed(unsigned int keycode)
    {
        return _key_pressed[keycode];
    }

    bool key_down(unsigned int keycode)
    {
        return _key_down[keycode];
    }

    Math::Vec2<double> get_cursor_location()
    {
        return _cursor_pos;
    }
}