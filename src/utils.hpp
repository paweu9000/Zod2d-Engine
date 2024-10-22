#pragma once
#include "backend/backend.h"
#include <vector>
#include "common.h"
#include <functional>

namespace Utils
{

    inline std::vector<Vertex> get_pos(Math::Vec2<float> pos, float scale)
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

    inline std::vector<Vertex> get_vertices(Math::Vec2<float> pos, float size, float scale, bool flipped, int frame, int spritesheet_size)
    {
        auto screen = Backend::get_screen_size();

        float tex_left = (frame * size) / spritesheet_size;
        float tex_right = ((frame + 1) * size) / spritesheet_size;
        float tex_bottom = 0.0f;
        float tex_top = 1.0f;

        if (flipped) {
            std::swap(tex_left, tex_right);
        }
        
        auto calc_x = [&](float scale = 0) {
            return 2 * ((pos.x + scale) / screen.x) - 1;
        };

        auto calc_y = [&](float scale = 0) {
            return 1 - 2 * ((pos.y + scale) / screen.y);
        };

        return {
            	Vertex({calc_x(scale * size), calc_y(scale * size), 0.0f}, {tex_right, tex_bottom}),
                Vertex({calc_x(scale * size), calc_y(), 0.0f}, {tex_right, tex_top}),       
                Vertex({calc_x(), calc_y(scale * size), 0.0f}, {tex_left, tex_bottom}),
                Vertex({calc_x(), calc_y(), 0.0f}, {tex_left, tex_top})
        };
    }
}