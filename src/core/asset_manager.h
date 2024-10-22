#pragma once
#include <stb_image.h>
#include "../common.h"
#include <string>

namespace AssetManager 
{
    void load_textures();
    GLuint get_texture(std::string name);
}