#pragma once
#include "../common.h"
#include <string>
#include <vector>

struct RenderData
{
    std::vector<Vertex> vertices;
    std::string texture;
};

enum class Direction
{
    EAST, WEST
};

enum class State
{
    IDLE, RUN
};

inline std::string get_sprite_name(std::string name, State state)
{
    std::string suffix;

    switch (state) {
        case State::IDLE: {
            suffix = "_idle";
            break;
        }
        case State::RUN: {
            suffix = "_run";
            break;
        }
    }

    std::string result = name+suffix;

    return result;
}