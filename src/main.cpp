#include "backend/backend.h"
#include "api/gl_backend.h"
#include <vector>

std::vector<Vertex> vertices = {
    Vertex(glm::vec3(0.5f,  0.5f, 0.0f)),
    Vertex(glm::vec3(0.5f, -0.5f, 0.0f)),
    Vertex(glm::vec3(-0.5f, -0.5f, 0.0f)),
    Vertex(glm::vec3(-0.5f,  0.5f, 0.0f))
};

std::vector<uint32_t> indices = {
    0, 1, 3,
    1, 2, 3
};

int main() {
    Backend::init();
    GLBackend::init();

    while (Backend::is_running()) {
        Backend::begin_frame();
        GLBackend::upload_vertex_data(vertices, indices);
        Backend::end_frame();
    }

    Backend::cleanup();
    return 0;
}