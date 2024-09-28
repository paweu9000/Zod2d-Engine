#pragma once

#include <glad.h>
#include <glfw3.h>
#include <stdio.h>
#include <string>
#include <glm.hpp>

//#############################
//          Logging
//#############################

#ifdef _WIN32
#define DEBUG_BREAK() __debugbreak()
#elif __linux__
#define DEBUG_BREAK() __builtin_debugtrap()
#elif __APPLE__
#define DEBUG_BREAK() __builtin_trap()
#endif

enum TextColor
{
    TEXT_COLOR_BLACK,
    TEXT_COLOR_RED,
    TEXT_COLOR_GREEN,
    TEXT_COLOR_YELLOW,
    TEXT_COLOR_BLUE,
    TEXT_COLOR_MAGENTA,
    TEXT_COLOR_CYAN,
    TEXT_COLOR_WHITE,
    TEXT_COLOR_BRIGHT_BLACK,
    TEXT_COLOR_BRIGHT_RED,
    TEXT_COLOR_BRIGHT_GREEN,
    TEXT_COLOR_BRIGHT_YELLOW,
    TEXT_COLOR_BRIGHT_BLUE,
    TEXT_COLOR_BRIGHT_MAGENTA,
    TEXT_COLOR_BRIGHT_CYAN,
    TEXT_COLOR_BRIGHT_WHITE,
    TEXT_COLOR_COUNT
};
    
template <typename ...Args>
void _log(std::string prefix, std::string msg, TextColor textColor, Args... args)
{
    static std::string TextColorTable[TEXT_COLOR_COUNT] = 
    {    
            "\x1b[30m", // TEXT_COLOR_BLACK
            "\x1b[31m", // TEXT_COLOR_RED
            "\x1b[32m", // TEXT_COLOR_GREEN
            "\x1b[33m", // TEXT_COLOR_YELLOW
            "\x1b[34m", // TEXT_COLOR_BLUE
            "\x1b[35m", // TEXT_COLOR_MAGENTA
            "\x1b[36m", // TEXT_COLOR_CYAN
            "\x1b[37m", // TEXT_COLOR_WHITE
            "\x1b[90m", // TEXT_COLOR_BRIGHT_BLACK
            "\x1b[91m", // TEXT_COLOR_BRIGHT_RED
            "\x1b[92m", // TEXT_COLOR_BRIGHT_GREEN
            "\x1b[93m", // TEXT_COLOR_BRIGHT_YELLOW
            "\x1b[94m", // TEXT_COLOR_BRIGHT_BLUE
            "\x1b[95m", // TEXT_COLOR_BRIGHT_MAGENTA
            "\x1b[96m", // TEXT_COLOR_BRIGHT_CYAN
            "\x1b[97m", // TEXT_COLOR_BRIGHT_WHITE
    };

    char format_buffer[8192] = {};
    sprintf(format_buffer, "%s %s %s \033[0m", TextColorTable[textColor].c_str(), prefix.c_str(), msg.c_str());

    char text_buffer[8192] = {};
    sprintf(text_buffer, format_buffer, args...);

    puts(text_buffer);
}

#define G_LOG(msg, ...) _log("LOG: ", msg, TEXT_COLOR_GREEN, ##__VA_ARGS__);
#define G_WARN(msg, ...) _log("WARN: ", msg, TEXT_COLOR_YELLOW, ##__VA_ARGS__);
#define G_ERROR(msg, ...) _log("ERROR: ", msg, TEXT_COLOR_RED, ##__VA_ARGS__);
#define G_ASSERTION(msg, ...) _log("ASSERTION FAILED\n\t", msg, TEXT_COLOR_BLUE, ##__VA_ARGS__);

#define G_ASSERT(x, ...)         \
{                                   \
    if (!(x))                       \
    {                               \
        std::string file = __FILE__; \
        std::string line = std::to_string(__LINE__); \
        G_ASSERTION("at " + file + ",  " + line);   \
        DEBUG_BREAK();               \
    }                               \
}

//###############################
//          TYPES
//###############################

struct Vertex {
    Vertex() = default;
    Vertex(glm::vec3 pos) {
        position = pos;
    }

    glm::vec3 position;
};