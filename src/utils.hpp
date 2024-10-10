#pragma once
#include <glm.hpp>
#include "backend/backend.h"
#include <vector>
#include "common.h"
#include <functional>

namespace Utils
{
    glm::mat4 get_mvp(glm::mat4 model, glm::mat4 view, glm::mat4 projection) 
    {
        return projection * view * model;
    }

    std::vector<Vertex> get_pos(glm::vec2 pos, float scale)
    {
        glm::vec2 screen = Backend::get_screen_size();
        
        auto calc_x = [&](float scale = 0) {
            return 2 * ((pos.x + scale) / screen.x) - 1;
        };

        auto calc_y = [&](float scale = 0) {
            return 1 - 2 * ((pos.y + scale) / screen.y);
        };

        return {
            	Vertex(glm::vec3(calc_x(scale), calc_y(scale), 0.0f), glm::vec2(1.0f, 0.0f)),
                Vertex(glm::vec3(calc_x(scale), calc_y(), 0.0f), glm::vec2(1.0f, 1.0f)),       
                Vertex(glm::vec3(calc_x(), calc_y(scale), 0.0f), glm::vec2(0.0f, 0.0f)),
                Vertex(glm::vec3(calc_x(), calc_y(), 0.0f), glm::vec2(0.0f, 1.0f))
        };
    }
}