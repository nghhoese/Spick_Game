#pragma once

#include "SceneBuilder.hpp"
#include <API_Headers/Sprite.hpp>
#include <API_Headers/Button.hpp>
#include <API_Headers/Text.hpp>
#include "../Behaviourscripts/ChangeSceneBehaviour.hpp"

class CheatsMenuBuilder : public SceneBuilder {
private:
	std::shared_ptr<spic::Button> buttonDamageLess;
	std::shared_ptr<spic::Button> buttonUpMovementSpeed;
	std::shared_ptr<spic::Button> buttonMakeUndetectable;
	std::shared_ptr<spic::Button> buttonBackToLevel;
public:
	std::shared_ptr<spic::Scene> BuildScene();
};