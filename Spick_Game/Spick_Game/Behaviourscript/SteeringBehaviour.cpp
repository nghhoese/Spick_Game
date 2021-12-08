#include "SteeringBehaviour.hpp"

SteeringBehaviour::SteeringBehaviour(spic::Point object) : object(object)
{
	CreateFeeler();
}

SteeringBehaviour::SteeringBehaviour()
{
}

void SteeringBehaviour::CreateFeeler()
{
	_feeler.x = object.x;
	_feeler.y = object.y;
	_feeler.Add(32);
}

spic::Point SteeringBehaviour::WallAvoidance()
{
	double DistToThisIP = 0.0;
	double DistToClosestIP = 20;

	return spic::Point();
}

spic::Point SteeringBehaviour::Persue(spic::Point evader)
{
	double predatorMaxSpeed = 10;
	double evaderSpeed = 5;
	spic::Point toEvader;
	toEvader.Sub(object, evader);

	double relativeHeading = object.Dot(evader);

	if ((toEvader.Dot(object) > 0) &&
		(relativeHeading < -0.95)) //acos(0.95)=18 degs
	{
		return Seek(evader);
	}

	double LookAheadTime = toEvader.Mag() /
		(predatorMaxSpeed + evaderSpeed);

	evader.Add(evaderSpeed);
	evader.Mult(LookAheadTime);

	return Seek(evader);
}

spic::Point SteeringBehaviour::Seek(spic::Point target)
{
	double objectMaxSpeed = 10;
	double speed = 5;

	target.Sub(object);
	target.Mult(objectMaxSpeed);
	target.Normalize();
	target.Sub(speed);

	return target;
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
