#pragma once

#include "SceneBuilder.hpp"
#include <API_Headers/Sprite.hpp>
#include <API_Headers/Button.hpp>
#include <API_Headers/Text.hpp>
#include "../Behaviourscript/ChangeSceneBehaviour.hpp"
#include "../Behaviourscript/SteeringBehaviour.hpp"
#include "../Level.hpp"
#include "../HUD.hpp"

class LevelSceneBuilder : public SceneBuilder {
private:

public:
	std::shared_ptr<spic::Scene> BuildLevelScene(spic::Engine* engine, int levelNumber);

	void BuildLevel(spic::Engine* engine, int levelNumber);
};