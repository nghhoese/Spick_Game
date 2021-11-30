#include "Bullet.h"
#include <math.h>
#include "API_Headers/Time.hpp"
#include "API_Headers/Scene.hpp"
Bullet::Bullet(spic::Point pos, spic::Point direction, double speed)
{
	this->direction = direction;
	this->speed = speed;
	float distance = (float)sqrt(pow(direction.x - pos.x, 2) + pow(direction.y - pos.y, 2));
	amountToMoveX = (((direction.x - pos.x) / distance) * speed);
	amountToMoveY = (((direction.y - pos.y) / distance) * speed);
}

Bullet::Bullet()
{
}

void Bullet::Update()
{
	auto trans = *GetGameObject()->getTransform();
	trans.position.x += amountToMoveX;
	trans.position.y += amountToMoveY;
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

void Bullet::OnTriggerExit2D(const Collider& collider)
{
}

void Bullet::OnTriggerStay2D(const Collider& collider)
{
}