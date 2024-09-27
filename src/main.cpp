#include "backend/backend.h"

int main() {
    Backend::init();

    while (Backend::is_running()) {
        Backend::begin_frame();
        Backend::end_frame();
    }

    Backend::cleanup();
    return 0;
}