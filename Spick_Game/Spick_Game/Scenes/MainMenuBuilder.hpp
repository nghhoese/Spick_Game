#pragma once

#include "SceneBuilder.hpp"
#include <API_Headers/Sprite.hpp>
#include <API_Headers/Button.hpp>
#include <API_Headers/Text.hpp>
#include "../Behaviourscripts/ChangeSceneBehaviour.hpp"

class MainMenuBuilder : public SceneBuilder {
private:
	std::shared_ptr<spic::Button> buttonPlay;
	std::shared_ptr<spic::Button> buttonHelp;
	std::shared_ptr<spic::Button> buttonCredits;
public:
	void BuildScript();
	std::shared_ptr<spic::Scene> BuildScene();
};