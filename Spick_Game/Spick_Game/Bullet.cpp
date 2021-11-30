#include "Bullet.h"
#include <math.h>
#include "API_Headers/Time.hpp"
#include "API_Headers/Scene.hpp"
Bullet::Bullet(spic::Point pos, spic::Point direction, double speed)
{
	this->position = pos;
	this->direction = direction;
	this->speed = speed;
}

Bullet::Bullet()
{

}

void Bullet::Update()
{
	auto trans = *GetGameObject()->getTransform();
	spic::Time time;
	trans.position.x += amountToMoveX * speed;
	trans.position.y += amountToMoveY * speed;
	GetGameObject()->setTransform(&trans);
}

void Bullet::OnAwake()
{
}

void Bullet::OnStart()
{
}

void Bullet::OnUpdate()
{

	Update();
}

void Bullet::OnRender()
{
}

void Bullet::OnTriggerEnter2D(const Collider& collider)
{
}

void Bullet::OnClick()
{
}

void Bullet::CalculateAmountToMove()
{
	float distance = (float)sqrt(pow(position.x - GetGameObject()->getScene()->GetActiveCamera()->getX() - direction.x, 2) + pow(position.y - GetGameObject()->getScene()->GetActiveCamera()->getY() - direction.y, 2));
	amountToMoveX = (((position.x - GetGameObject()->getScene()->GetActiveCamera()->getX()) - direction.x) * -1) / distance;
	amountToMoveY = (((position.y - GetGameObject()->getScene()->GetActiveCamera()->getY()) - direction.y) * -1) / distance;
}

void Bullet::OnTriggerExit2D(const Collider& collider)
{
}

void Bullet::OnTriggerStay2D(const Collider& collider)
{
}