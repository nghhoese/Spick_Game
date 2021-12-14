#pragma once

#include "API_Headers/BehaviourScript.hpp"
#include "API_Headers/Scene.hpp"
#include "../Scenes/LevelSceneBuilder.hpp"
#include "../Controllers/EngineController.hpp"

class ReturnToMainMenuBehaviour : public spic::BehaviourScript {
private:
	std::string _scene;
public:
	ReturnToMainMenuBehaviour(const std::string& name);
	void OnUpdate();
	virtual void OnAwake();
	void OnStart();
	void OnRender();
	void OnClick();
	void OnTriggerEnter2D(const spic::Collider& collider);
	void OnTriggerExit2D(const spic::Collider& collider);
	void OnTriggerStay2D(const spic::Collider& collider);
	void sceneChange(const std::string& newScene);
};
