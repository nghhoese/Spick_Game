#pragma once
#include "API_Headers/BehaviourScript.hpp"
#include "API_Headers/Point.hpp"
#include "API_Headers/GameObject.hpp"
#include "API_Headers/Scene.hpp"
#include "../Behaviourscripts/Enemy.hpp"

class SteeringBehaviour : public spic::BehaviourScript {
private:
	spic::Point _feeler;
	spic::Point _enemyPos;
	spic::Point _playerPos;


	spic::Point vel;
	void CreateFeeler();
public:
	SteeringBehaviour(spic::Point objectPos, spic::Point playerPos, spic::Point vel);
	SteeringBehaviour();
	spic::Point WallAvoidance();
	spic::Point Persue();
	spic::Point Seek(spic::Point target);
	//void SetObject(spic::Point object);

	void OnAwake();
	void OnStart();
	void OnUpdate();
	void OnRender();
	void OnTriggerEnter2D(const spic::Collider& collider);
	void OnClick();
	void OnTriggerExit2D(const spic::Collider& collider);
	void OnTriggerStay2D(const spic::Collider& collider);

};