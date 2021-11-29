#include "Bullet.h"

Bullet::Bullet(spic::Point pos, spic::Point direction, double speed)
{
	//this->position = GetGameObject()->getTransform()->position;
	//this->direction = direction;
	//this->speed = speed;

}

Bullet::Bullet()
{
}

void Bullet::Update()
{
	auto trans = *GetGameObject()->getTransform();
	trans.position.x += speed;
	trans.position.y += speed;

	GetGameObject()->setTransform(&trans);


	/*this->position.x += direction.x * speed;
	this->position.y += direction.y * speed;
	auto trans = *GetGameObject()->getTransform();
	trans.position = position;
	GetGameObject()->setTransform(&trans);*/
}

void Bullet::OnAwake()
{
}

void Bullet::OnStart()
{
}

void Bullet::OnUpdate()
{
	if (!idle)
	{
		Update();
	}
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
