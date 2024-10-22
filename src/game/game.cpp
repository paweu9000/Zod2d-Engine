#include "game.h"
#include "player.h"

namespace Game 
{
    float _deltaTime;
    float _lastFrame;

    void init()
    {
        _deltaTime = 0.0f;
        _lastFrame = 0.0f;
        Player::init();
    }

    void update()
    {
        float _currentFrame = glfwGetTime();
        _deltaTime = _currentFrame - _lastFrame;
        _lastFrame = _currentFrame;
        // TODO
        Player::process_input();
        Player::update();
    }

    float get_delta_time()
    {
        return _deltaTime;
    }

    // TODO 
    RenderData get_render_data()
    {
        return Player::get_render_data();
    }
}