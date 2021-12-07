#pragma once

#include "API_Headers/BehaviourScript.hpp"
#include "API_Headers/Scene.hpp"
#include "../Scenes/LevelSceneBuilder.hpp"
#include "../Controllers/EngineController.hpp"

class ChangeSceneBehaviour : public spic::BehaviourScript {
public:
	ChangeSceneBehaviour(std::string name, std::string scene);
	void OnUpdate();
	virtual void OnAwake();
	void OnStart();
	void OnRender();
	void OnClick();
	void OnTriggerEnter2D(const Collider& collider);
	void OnTriggerExit2D(const Collider& collider);
	void OnTriggerStay2D(const Collider& collider);
private:
	std::string _scene;
};