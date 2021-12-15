#pragma once
#include "API_Headers/Point.hpp"
#include "API_Headers/GameObject.hpp"
#include "API_Headers/Collision.hpp"

class AIController {
public:
	AIController(spic::GameObject persuerGameObject, spic::Point vel, spic::GameObject escapeeGameObject, double speed);
	spic::Point Wander();
	spic::Point Persue();
	spic::Point Seek(spic::Point target);
	spic::Point WallAvoidance(spic::Point target);
	spic::Point GetSight() { return this->sight; };
	void Update(spic::GameObject persuerGameObject, spic::Point vel, spic::GameObject escapeeGameObject);

private:
	spic::Point vel;
	std::unique_ptr<spic::GameObject> persuer;
	std::unique_ptr<spic::GameObject> escapee;
	spic::Point sight;
	double wandertheta;
	double speed;
};
