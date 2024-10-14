#pragma once
#include "backend/backend.h"
#include <vector>
#include "common.h"
#include <functional>

namespace Utils
{

    std::vector<Vertex> get_pos(Math::Vec2<float> pos, float scale)
    {
        auto screen = Backend::get_screen_size();
        
        auto calc_x = [&](float scale = 0) {
            return 2 * ((pos.x + scale) / screen.x) - 1;
        };

        auto calc_y = [&](float scale = 0) {
            return 1 - 2 * ((pos.y + scale) / screen.y);
        };

        return {
            	Vertex({calc_x(scale), calc_y(scale), 0.0f}, {1.0f, 0.0f}),
                Vertex({calc_x(scale), calc_y(), 0.0f}, {1.0f, 1.0f}),       
                Vertex({calc_x(), calc_y(scale), 0.0f}, {0.0f, 0.0f}),
                Vertex({calc_x(), calc_y(), 0.0f}, {0.0f, 1.0f})
        };
    }
}