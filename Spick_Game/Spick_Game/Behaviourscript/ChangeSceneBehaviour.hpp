#pragma once

#include "API_Headers/BehaviourScript.hpp"
#include "API_Headers/Engine.hpp"

class ChangeSceneBehaviour : public spic::BehaviourScript {
public:
	ChangeSceneBehaviour(std::string name, std::string scene, spic::Engine* engine);
	void OnUpdate();
	virtual void OnAwake();
	void OnStart();
	void OnRender();
	void OnClick();
	void OnTriggerEnter2D(const Collider& collider);
	/**
	 * @brief Sent when another object leaves a trigger collider
	 *        attached to this object (2D physics only).
	 */
	void OnTriggerExit2D(const Collider& collider);

	/**
	 * @brief Sent each frame where another object is within a trigger
	 *        collider attached to this object (2D physics only).
	 */
	void OnTriggerStay2D(const Collider& collider);

private:
	std::string _scene;
	spic::Engine* _engine;
};