#pragma once

#include "SceneBuilder.hpp"
#include <API_Headers/Sprite.hpp>
#include <API_Headers/Button.hpp>
#include <API_Headers/Text.hpp>
#include "../Behaviourscripts/ChangeSceneBehaviour.hpp"
#include "../Behaviourscripts/Quit.hpp"

class MainMenuBuilder : public SceneBuilder {
private:
	std::shared_ptr<spic::Button> buttonPlay;
	std::shared_ptr<spic::Button> buttonHelp;
	std::shared_ptr<spic::Button> buttonCredits;
	std::shared_ptr<spic::Button> buttonQuit;
public:
	std::shared_ptr<spic::Scene> BuildScene();
};