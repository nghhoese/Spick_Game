#pragma once

#include <iostream>
#define SDL_MAIN_HANDLED
#include "API_Headers/Scene.hpp"
#include "API_Headers/Engine.hpp"

class SceneBuilder {
	private: 

	public: 
		std::shared_ptr<spic::Scene> BuildScene();

		void scriptBuilder(const spic::Engine& engine);
};
