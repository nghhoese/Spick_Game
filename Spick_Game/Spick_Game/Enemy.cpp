#include "Enemy.hpp"
#include "API_Headers/Scene.hpp"
#include <API_Headers/Sprite.hpp>
#include <API_Headers/BoxCollider.hpp>
#include "Collision.hpp"



void Enemy::OnAwake()
{
}

void Enemy::OnStart()
{
    auto trans = *GetGameObject()->getTransform();
    double Delta_x = (trans.position.x);
    double Delta_y = (trans.position.y);

    double Result = (atan2(Delta_y, Delta_x) * 180.0000) / 3.14159265;
    trans.rotation = Result + (rand() % 180 + 90);
    GetGameObject()->setTransform(&trans);
}

void Enemy::OnUpdate()
{
	if (healthpoints < 0) {
		auto trans = *GetGameObject()->getTransform();
		trans.scale = 0.01;
		trans.position.x = -20;
		trans.position.x = -20;
		GetGameObject()->setTransform(&trans);
		GetGameObject()->GetComponent<spic::Sprite>()->OnRender();
	}

    if (!isMoving)
    {
        auto trans = *GetGameObject()->getTransform();

        auto tag = GetGameObject()->GetTags()[0];
        // move till destination is reached
        if (tag == "red")
        {
            //up and down
            trans.position.y += speed;
        }
        else if (tag == "blue")
        {
            //left and right
            trans.position.x += speed;
        }
        else
        {
            trans.position.x += speed;
            trans.position.y += speed;
        }

        if (Collision::AABB(GetGameObject(), "wall") && !isTurned)
        {
            isTurned = true;
            speed = speed * -1;
            double Result = (atan2(trans.position.y, trans.position.x) * 180.0000) / 3.14159265;
            trans.rotation = Result + (rand() % 180 + 90);

        }
        else {
            turnCount++;
            if (turnCount == 64)
            {
                isTurned = false;
                turnCount = 0;
            }
        }
        GetGameObject()->setTransform(&trans);
    }
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
