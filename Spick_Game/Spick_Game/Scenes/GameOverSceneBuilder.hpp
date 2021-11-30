#pragma once

#include "SceneBuilder.hpp"
#include <API_Headers/Sprite.hpp>
#include <API_Headers/Button.hpp>
#include <API_Headers/Text.hpp>
#include "../Behaviourscript/ChangeSceneBehaviour.hpp"

class GameOverBuilder : public SceneBuilder {
private:
	std::shared_ptr<spic::Button> buttonBackToMenu;
public:
	void BuildScript(spic::Engine* engine);
	std::shared_ptr<spic::Scene> BuildScene();

};