#pragma once
#include <stb_image.h>
#include "../common.h"
#include <string_view>

namespace AssetManager 
{
    void load_textures();
    GLuint get_texture(std::string_view name);
}