#pragma once

#include "SceneBuilder.hpp"
#include <API_Headers/Sprite.hpp>
#include <API_Headers/Button.hpp>
#include <API_Headers/Text.hpp>
#include <API_Headers/Animator.hpp>

#include "../Behaviourscripts/ChangeSceneBehaviour.hpp"

class HelpSceneBuilder : public SceneBuilder {
private:
	std::shared_ptr<spic::Button> buttonBack;
public:
	std::shared_ptr<spic::Scene> BuildScene();

};
