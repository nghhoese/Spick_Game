#pragma once

#include "SceneBuilder.hpp"
#include <API_Headers/Sprite.hpp>
#include <API_Headers/Button.hpp>
#include <API_Headers/Text.hpp>

class MainMenuBuilder : public SceneBuilder {
private:
	std::shared_ptr<spic::Button> buttonPlay;
	std::shared_ptr<spic::Button> buttonOptions;
public:
	void BuildScript(spic::Engine* engine);
	std::shared_ptr<spic::Scene> BuildScene();
	
};