#include "Enemy.hpp"
#include "API_Headers/Scene.hpp"
#include <API_Headers/Sprite.hpp>
#include <API_Headers/BoxCollider.hpp>
#include <API_Headers/Collision.hpp>


bool Enemy::IfPlayerNearby()
{
    auto enemyPos = GetGameObject()->getTransform()->position;
    auto playerPos = GetGameObject()->getScene()->GetGameObjectsByName("Player")[0]->getTransform()->position;

    auto enemyDirection = GetGameObject()->getTransform()->rotation;
    
    double Delta_x = (enemyPos.x - playerPos.x);
    double Delta_y = (enemyPos.y - playerPos.y);

    double enemyToPlayerDir = ((atan2(Delta_y, Delta_x) * 180.0000) / 3.14159265) + 90;

    auto radians = 45;

    if (enemyDirection - radians <= enemyToPlayerDir &&
        enemyDirection + radians >= enemyToPlayerDir)
    {
        return (enemyPos.x + triggerSpace >= playerPos.x &&
        enemyPos.x - triggerSpace <= playerPos.x &&
        enemyPos.y + triggerSpace >= playerPos.y &&
        enemyPos.y - triggerSpace <= playerPos.y);
    }
    return false;
    
}

bool Enemy::InShootingRange()
{
    auto enemyPos = GetGameObject()->getTransform()->position;
    auto playerPos = GetGameObject()->getScene()->GetGameObjectsByName("Player")[0]->getTransform()->position;

    return (enemyPos.x + shootingSpace >= playerPos.x &&
        enemyPos.x - shootingSpace <= playerPos.x &&
        enemyPos.y + shootingSpace >= playerPos.y &&
        enemyPos.y - shootingSpace <= playerPos.y);
}

Enemy::Enemy() : speed(1.5), turnCount(0), isTurned(false), isAlive(true), notInitialized(true)
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
    vel.x = 0;
    vel.y = 0;
    acc.x = 0;
    acc.y = 0;
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
        if (GetGameObject()->getScene()->GetGameObjectsByName("Player").size() > 0) {
            if (notInitialized)
            {
                notInitialized = false;
                auto tempEnem = *GetGameObject();
                auto tempPlay = *GetGameObject()->getScene()->GetGameObjectsByName("Player")[0];
                AI = std::make_unique<AIController>(*GetGameObject(), vel, *GetGameObject()->getScene()->GetGameObjectsByName("Player")[0], speed);
            }
           
            auto trans = *GetGameObject()->getTransform();
            auto player = GetGameObject()->getScene()->GetGameObjectsByName("Player")[0];
            auto tag = GetGameObject()->GetTags()[0];
            AI->Update(*GetGameObject(), vel, *player);
            spic::Point steering;
            steering.x = 0;
            steering.y = 0;
       
            if (IfPlayerNearby())
            {
                double Delta_x = (trans.position.x - player->getTransform()->position.x);
                double Delta_y = (trans.position.y - player->getTransform()->position.y);

                double Result = (atan2(Delta_y, Delta_x) * 180.0000) / 3.14159265;
                trans.rotation = Result + 90;

                if (!InShootingRange())
                {
                    steering = AI->Persue();
                    acc.Add(steering);
                    vel.Add(acc);
                    vel.Limit(10);

                    trans.position.Add(vel);
                }
                else {
                    //shoot at player
                }
            }
            else {
                steering = AI->Wander();
                double Delta_x = (trans.position.x - AI->GetSight().x);
                double Delta_y = (trans.position.y - AI->GetSight().y);

                double Result = (atan2(Delta_y, Delta_x) * 180.0000) / 3.14159265;
                trans.rotation = Result + 90;

                acc.Add(steering);
                vel.Add(acc);

                vel.Limit(10);
                trans.position.Add(vel);
            }
        
            GetGameObject()->setTransform(&trans);
        }
    }
}


void Enemy::OnRender()
{
}

void Enemy::OnTriggerEnter2D(const spic::Collider& collider)
{
}

void Enemy::OnTriggerExit2D(const spic::Collider& collider)
{
}

void Enemy::OnTriggerStay2D(const spic::Collider& collider)
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
