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
    auto steeringBehaviour = GetGameObject()->getScene()->GetGameObjectsByName("Steeringbehaviour")[0];
    auto steeringBehaviourComponent = steeringBehaviour->GetComponent<SteeringBehaviour>();

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

        auto tag = GetGameObject()->GetTags()[0];

        auto player = GetGameObject()->getScene()->GetGameObjectsByName("Player")[0];
        auto target = player->getTransform()->position;
        // move to target till destination is reached
        if (IfPlayerNearby()) // if player is in radius of enemy
        {
            auto steering = steeringBehaviourComponent->Persue(target);
            acc.Add(steering);

            vel.Add(acc);
            vel.Limit(10);
            trans.position.Add(vel);
            acc.x = 0;
            if (Collision::AABB(GetGameObject(), "wall"))
            {
                //isTurned = true;
                vel.Mult(-1);
                //speed *= -1;
                double Result = (atan2(trans.position.y, trans.position.x) * 180.0000) / 3.14159265;
                trans.rotation = Result + (rand() % 180 + 90);
            }
            acc.y = 0;
            /*else {
                turnCount++;
                if (turnCount == 64)
                {
                    isTurned = false;
                    turnCount = 0;
                }
            }*/
        }
        else {
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
            //else if (Collision::AABB(GetGameObject(), "player")) {
            //    PlayerComponent->yPlayer -= (PlayerComponent->speed);
            //}
            else {
                turnCount++;
                if (turnCount == 64)
                {
                    isTurned = false;
                    turnCount = 0;
                }
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
    // get player position (target)
    auto player = GetGameObject()->getScene()->GetGameObjectsByName("Player")[0];
    auto target = player->getTransform()->position;
    spic::Point prediction;
    prediction.x = 5;
    prediction.y = 5;
    prediction.Mult(1);
    target.Add(prediction);
    return seek(target);
}

spic::Point Enemy::seek(spic::Point target)
{
    spic::Point force;
    force.Sub(target, GetGameObject()->getTransform()->position);
    force.SetMag(5);
    force.Sub(vel);
    force.Limit(10);
    return force;
}

void Enemy::OnClick()
{
}
