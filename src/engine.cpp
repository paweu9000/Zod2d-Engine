#include "engine.h"
#include "backend/backend.h"
#include "api/gl_backend.h"
#include "api/gl_renderer.h"
#include <vector>
#include "utils.hpp"
#include "game/game.h"
#include "input/input.h"

Math::Vec2 pos{900.f, 500.f};

std::vector<uint32_t> indices = {
	0, 1, 3,
	0, 3, 2
};

void Engine::run() 
{
	Backend::init();
	GLBackend::init();	
	GLRenderer::init();
	Input::init();
	Game::init();

	while (Backend::is_running()) {
		Input::update();
		Game::update();
		Backend::begin_frame();
		GLBackend::rebind_buffers();
		GLRenderer::render_frame(Game::get_render_data(), indices);
		Backend::end_frame();
	}

	Backend::cleanup();
}
