#pragma once

#include "SceneBuilder.hpp"
#include <API_Headers/Sprite.hpp>
#include <API_Headers/Button.hpp>
#include <API_Headers/Text.hpp>
#include "../Behaviourscripts/ChangeSceneBehaviour.hpp"

class CompleteSceneBuilder : public SceneBuilder {
private:
	std::shared_ptr<spic::Button> buttonBackToMenu;
public:
	std::shared_ptr<spic::Scene> BuildScene();
};