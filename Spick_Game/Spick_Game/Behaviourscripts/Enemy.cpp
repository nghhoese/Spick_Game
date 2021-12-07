#include "Enemy.hpp"
#include "API_Headers/Scene.hpp"
#include <API_Headers/Sprite.hpp>
#include <API_Headers/BoxCollider.hpp>
#include <API_Headers/Collision.hpp>

Enemy::Enemy() : speed(1.5), turnCount(0), isTurned(false), isAlive(true)
{
}

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
	if (this->healthpoints < 0) {
        isAlive = false;
		auto trans = *GetGameObject()->getTransform();
		trans.scale = 0.01;
		trans.position.x = -50;
		trans.position.y = -10;
		GetGameObject()->setTransform(&trans);
		GetGameObject()->GetComponent<spic::Sprite>()->OnRender();
	}

    if (isAlive)
    {
        auto trans = *GetGameObject()->getTransform();
        auto tag = GetGameObject()->GetTags()[0];
        if (tag == "red")
        {
            trans.position.y += speed;
        }
        else if (tag == "blue")
        {
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
    auto sprite = GetGameObject()->GetComponent<spic::Sprite>();
    if (sprite != nullptr)
    {
        sprite->SetSprite(path);
    }
}

const std::string& Enemy::getPath()
{
	return this->path;
}

void Enemy::OnClick()
{
}
