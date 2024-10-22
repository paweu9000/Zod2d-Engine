#include "player.h"
#include "game.h"
#include <iostream>

namespace Player
{
    float _current_frame;
    State _state;
    Direction _direction;
    Math::Vec2<float> _position;
    float _speed;

    void init()
    {
        _current_frame = 0;
        _state = State::IDLE;
        _direction = Direction::EAST;
        _position = Math::Vec2<float>(PLAYER_INITIAL_X, PLAYER_INITIAL_Y);
        _speed = PLAYER_SPEED;
    }

    void process_input() 
    {
        if (Input::key_down(ZODD_KEY_D)) {
            _state = State::RUN;
            _direction = Direction::EAST;
        } else if (Input::key_down(ZODD_KEY_A)) {
            _state = State::RUN;
            _direction = Direction::WEST;
        } else {
            _state = State::IDLE;
        }
    }

    void update()
    {
        float step_size = (Game::get_delta_time() * _speed);

        // FRAME LOGIC
        _current_frame += step_size;
        if (_state == State::RUN && (int)_current_frame >= PLAYER_RUN_FRAMES) {
            _current_frame = 0.0f;
        } else if (_state == State::IDLE && (int)_current_frame >= PLAYER_IDLE_FRAMES) {
            _current_frame = 0.0f;
        }

        // MOVEMENT LOGIC
        if (_state != State::IDLE) {
            Math::Vec2<float> movement_vector{};

            switch (_direction) {
                case Direction::EAST: {
                    movement_vector.x = step_size * PLAYER_SIZE;
                    break;
                }
                case Direction::WEST: {
                    movement_vector.x = -step_size * PLAYER_SIZE;
                    break;
                }
            }
            _position += movement_vector;
        }
    }

    RenderData get_render_data()
    {
        bool flipped = _direction == Direction::WEST;
        int frames;
        if (_state == State::IDLE) {
            frames = PLAYER_IDLE_FRAMES;
        } else if (_state == State::RUN) {
            frames = PLAYER_RUN_FRAMES;
        } else {
            G_ERROR("INVALID NUMBER OF FRAMES");
        }
        int spritesheet_size = frames * PLAYER_SIZE;
        RenderData data;
        data.texture = get_sprite_name("player", _state);
        data.vertices = Utils::get_vertices(_position, PLAYER_SIZE, PLAYER_SCALE, flipped, (int)_current_frame, spritesheet_size);
        return data;
    }

}