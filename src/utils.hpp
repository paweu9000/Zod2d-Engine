#pragma once
#include <glm.hpp>

namespace Utils
{
    glm::mat4 get_mvp(glm::mat4 model, glm::mat4 view, glm::mat4 projection) 
    {
        return projection * view * model;
    }
}