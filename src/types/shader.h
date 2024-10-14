#pragma once
#include <string>
#include <unordered_map>
#include "../math.hpp"

struct Shader
{
public:
    void load(std::string& vertex_path, std::string& fragment_path);
    void use();
    void set_bool(const std::string& name, bool value);
    void set_int(const std::string& name, int value);
    void set_float(const std::string& name, float value);
    void set_vec3(const std::string& name, const Math::Vec3<float>& value);
    void set_vec2(const std::string& name, const Math::Vec2<float>& value);
private:
    void add_address(const std::string& name);
    int ID = 1;
    std::unordered_map<std::string, int> uniforms;
};