#define STB_IMAGE_IMPLEMENTATION
#include "asset_manager.h"
#include <unordered_map>
#include <filesystem>

namespace AssetManager
{

    std::unordered_map<std::string_view, GLuint> _textures;

    void add_texture(std::string_view name, const char* path)
    {
        GLuint texture;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        int width, height, nrChannels;
        unsigned char* data = stbi_load(path, &width, &height, &nrChannels, 0);

        G_ASSERT(data);

        GLenum format;
        if (nrChannels == 1) format = GL_RED;
        else if (nrChannels == 3) format = GL_RGB;
        else if (nrChannels == 4) format = GL_RGBA;

        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        stbi_image_free(data);

        _textures.emplace(name, texture);
    }

    void load_textures()
    {
        stbi_set_flip_vertically_on_load(true);
        add_texture("pope", "assets/pope.png");
    }

    GLuint get_texture(std::string_view name)
    {
        return _textures.at(name);
    }

}