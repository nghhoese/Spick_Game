#pragma once

#include "SceneBuilder.hpp"
#include <API_Headers/Sprite.hpp>
#include "../Behaviourscript/Standard/ButtonBehaviour.hpp"
#include <API_Headers/Button.hpp>
#include <API_Headers/Text.hpp>

class PlaySceneBuilder : public SceneBuilder {
private:

public:
	std::shared_ptr<spic::Scene> BuildScene();
};