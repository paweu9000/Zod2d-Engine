#pragma once
#include <string>
#include <glm.hpp>
#include <unordered_map>

struct Shader
{
public:
    void load(std::string& vertex_path, std::string& fragment_path);
    void use();
    void set_bool(const std::string& name, bool value);
    void set_int(const std::string& name, int value);
    void set_float(const std::string& name, float value);
    void set_mat4(const std::string& name, glm::mat4 value);
    void set_vec3(const std::string& name, const glm::vec3& value);
    void set_vec2(const std::string& name, const glm::vec2& value);
private:
    void add_address(const std::string& name);
    int ID = 1;
    std::unordered_map<std::string, int> uniforms;
};