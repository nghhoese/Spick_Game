#pragma once

#include "API_Headers/BehaviourScript.hpp"
#include "../Controllers/EngineController.hpp"

class QuitBehaviour : public spic::BehaviourScript {
private:

public:
	QuitBehaviour();
	void OnUpdate();
	virtual void OnAwake();
	void OnStart();
	void OnRender();
	void OnClick();
	void OnTriggerEnter2D(const spic::Collider& collider);
	void OnTriggerExit2D(const spic::Collider& collider);
	void OnTriggerStay2D(const spic::Collider& collider);
};
