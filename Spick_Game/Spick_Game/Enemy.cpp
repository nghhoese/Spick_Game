#include "Enemy.hpp"
#include "API_Headers/Scene.hpp"
#include <API_Headers/Sprite.hpp>
#include <API_Headers/BoxCollider.hpp>
#include <API_Headers/Collision.hpp>


bool Enemy::IfPlayerNearby()
{
    auto enemyPos = GetGameObject()->getTransform()->position;
    auto playerPos = GetGameObject()->getScene()->GetGameObjectsByName("Player")[0]->getTransform()->position;

    return (enemyPos.x + triggerSpace >= playerPos.x &&
        enemyPos.x - triggerSpace <= playerPos.x &&
        enemyPos.y + triggerSpace >= playerPos.y &&
        enemyPos.y - triggerSpace <= playerPos.y);
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

    //IF something do persue
    


    if (isAlive)
    {
        auto trans = *GetGameObject()->getTransform();
        auto player = GetGameObject()->getScene()->GetGameObjectsByName("Player")[0];
        auto tag = GetGameObject()->GetTags()[0];
       
        auto steeringBehaviour = GetGameObject()->getScene()->GetGameObjectsByName("SteeringBehaviour")[0];
        auto steeringBehaviourComponent = steeringBehaviour->GetComponent<SteeringBehaviour>();
        SteeringBehaviour steer{ trans.position, player->getTransform()->position , vel };
        // move to target till destination is reached
        if (IfPlayerNearby()) // if player is in radius of enemy
        {
            auto steering = persue();
            acc.Add(steering);
            vel.Add(acc);
            vel.Limit(10);
            trans.position.Add(vel);
            double Delta_x = (trans.position.x - player->getTransform()->position.x);
            double Delta_y = (trans.position.y - player->getTransform()->position.y);

            double Result = (atan2(Delta_y, Delta_x) * 180.0000) / 3.14159265;
            trans.rotation = Result + 90;
            acc.x = 0;
            acc.y = 0;
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

spic::Point Enemy::persue()
{
    auto player = GetGameObject()->getScene()->GetGameObjectsByName("Player")[0];
    auto target = player->getTransform()->position;
    spic::Point prediction;
    //TODO: this must be the direction (rotation?) of the player
    prediction.x = cos(player->getTransform()->rotation);
    prediction.y = sin(player->getTransform()->rotation);
    prediction.Mult(100);
    target.Add(prediction);
    return seek(target);
}

spic::Point Enemy::seek(spic::Point target)
{
    spic::Point force;
    force.Sub(target, GetGameObject()->getTransform()->position);
    force.SetMag(10);
    force.Sub(vel);
    force.Limit(0.25);
    return force;
}

void Enemy::OnClick()
{
}
