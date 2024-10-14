#include "shader.h"
#include "../common.h"
#include <fstream>
#include <sstream>

enum ErrorType {
    SHADER, PROGRAM
};

std::string load_from_file(std::string path)
{
    std::ifstream source_code(path);
    std::string str;
    std::string line;
    while (std::getline(source_code, line)) {
        str += line + "\n";
    }

    return str;
}

void Shader::load(std::string& vertex_path, std::string& fragment_path) {
    auto _checkErrors = [](GLuint id, ErrorType type) {
            int success;
            char infoLog[512];
            if (type == SHADER) {
                glGetShaderiv(id, GL_COMPILE_STATUS, &success);
                if (!success) {
                    glGetShaderInfoLog(id, 512, nullptr, infoLog);
                    G_ERROR(infoLog);
                }
            } else {
                glGetProgramiv(id, GL_LINK_STATUS, &success);
                if (!success) {
                    glGetProgramInfoLog(id, 512, nullptr, infoLog);
                    G_ERROR(infoLog);
                }
            }
        };

    std::string vertexSource = load_from_file(vertex_path);
    std::string fragmentSource = load_from_file(fragment_path);

    const char* vertexShaderSource = vertexSource.c_str();
    const char* fragmentShaderSource = fragmentSource.c_str();

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
    glCompileShader(vertexShader);
    _checkErrors(vertexShader, SHADER);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
    glCompileShader(fragmentShader);
    _checkErrors(fragmentShader, SHADER);

    ID = glCreateProgram();
    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);
    glLinkProgram(ID);
    _checkErrors(ID, PROGRAM);

    glDeleteShader(fragmentShader);
    glDeleteShader(vertexShader);
}

void Shader::use()
{
    glUseProgram(ID);
}

void Shader::set_bool(const std::string& name, bool value)
{
    add_address(name);
    glUniform1i(uniforms[name], value);
}

void Shader::set_int(const std::string& name, int value)
{
    add_address(name);
    glUniform1i(uniforms[name], value);
}

void Shader::set_float(const std::string& name, float value)
{
    add_address(name);
    glUniform1f(uniforms[name], value);
}

void Shader::set_vec3(const std::string& name, const Math::Vec3<float>& value)
{
    add_address(name);
    glUniform3fv(uniforms[name], 1, &value.x);
}

void Shader::set_vec2(const std::string& name, const Math::Vec2<float>& value)
{
    add_address(name);
    glUniform2fv(uniforms[name], 1, &value.x);
}

void Shader::add_address(const std::string& name)
{
    if (uniforms.find(name) == uniforms.end()) {
        uniforms[name] = glGetUniformLocation(ID, name.c_str());
    }
}