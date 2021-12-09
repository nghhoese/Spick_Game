#include "SteeringBehaviour.hpp"

SteeringBehaviour::SteeringBehaviour(spic::Point objectPos, spic::Point playerPos, spic::Point vel) : _enemyPos(objectPos), _playerPos(playerPos), vel(vel)
{
	CreateFeeler();
}

SteeringBehaviour::SteeringBehaviour()
{
}

void SteeringBehaviour::CreateFeeler()
{
	_feeler.x = _enemyPos.x;
	_feeler.y = _enemyPos.y;
	_feeler.Add(32);
}

spic::Point SteeringBehaviour::WallAvoidance()
{
	double DistToThisIP = 0.0;
	double DistToClosestIP = 20;

	return spic::Point();
}

spic::Point SteeringBehaviour::Persue()
{
	auto target = _playerPos;
	spic::Point prediction;
	//TODO: this must be the direction (rotation?) of the player
	//prediction.x = cos()
	prediction.x = 5;
	prediction.y = 5;
	prediction.Mult(10);
	target.Add(prediction);
	return Seek(target);
}

spic::Point SteeringBehaviour::Seek(spic::Point target)
{
	spic::Point force;
	force.Sub(target, _enemyPos);
	force.SetMag(10);
	force.Sub(vel);
	force.Limit(0.25);
	return force;
}


void SteeringBehaviour::OnAwake()
{
}

void SteeringBehaviour::OnStart()
{
}

void SteeringBehaviour::OnUpdate()
{
}

void SteeringBehaviour::OnRender()
{
}

void SteeringBehaviour::OnTriggerEnter2D(const Collider& collider)
{
}

void SteeringBehaviour::OnClick()
{
}

void SteeringBehaviour::OnTriggerExit2D(const Collider& collider)
{
}

void SteeringBehaviour::OnTriggerStay2D(const Collider& collider)
{
}
