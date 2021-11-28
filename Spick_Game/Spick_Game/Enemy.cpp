#include "Enemy.hpp"

void Enemy::OnAwake()
{
}

void Enemy::OnStart()
{
}

void Enemy::OnUpdate()
{
}

void Enemy::OnRender()
{
}

void Enemy::OnTriggerEnter2D(const Collider& collider)
{
}

void Enemy::OnTriggerExit2D(const Collider& collider)
{
}

void Enemy::OnTriggerStay2D(const Collider& collider)
{
}

void Enemy::setPath(const std::string& path)
{
	this->path = path;
}

const std::string& Enemy::getPath()
{
	return this->path;
}

void Enemy::setHealthpoints(const int& healthpoints)
{
	this->healthpoints = healthpoints;
}

const int& Enemy::getHealthpoints()
{
	return this->healthpoints;
}

void Enemy::setDamagePerBullet(const int& damagePerBullet)
{
	this->damagePerBullet = damagePerBullet;
}

const int& Enemy::getDamagePerBullet()
{
	return this->damagePerBullet;
}

void Enemy::OnClick()
{
}
