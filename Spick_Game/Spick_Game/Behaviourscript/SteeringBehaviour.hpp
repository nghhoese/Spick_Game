#pragma once
#include "API_Headers/BehaviourScript.hpp"
#include "API_Headers/Point.hpp"
#include "API_Headers/GameObject.hpp"

class SteeringBehaviour : public spic::BehaviourScript {
private:
	spic::Point _feeler;
	spic::Point object;
	void CreateFeeler();
public:
	SteeringBehaviour(spic::Point object);
	SteeringBehaviour();
	spic::Point WallAvoidance();
	spic::Point Persue(spic::Point evader);
	spic::Point Seek(spic::Point target);

	void OnAwake();
	void OnStart();
	void OnUpdate();
	void OnRender();
	void OnTriggerEnter2D(const Collider& collider);
	void OnClick();
	void OnTriggerExit2D(const Collider& collider);
	void OnTriggerStay2D(const Collider& collider);

};