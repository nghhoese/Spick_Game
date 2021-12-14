#include "Enemy.hpp"
#include "API_Headers/Scene.hpp"
#include <API_Headers/Sprite.hpp>
#include <API_Headers/BoxCollider.hpp>
#include <API_Headers/Collision.hpp>


bool Enemy::IfPlayerNearby()
{
    // check if rotation is in direction of player or not
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

    //IF something do persue
    


    if (isAlive)
    {
        auto trans = *GetGameObject()->getTransform();
        auto player = GetGameObject()->getScene()->GetGameObjectsByName("Player")[0];
        auto tag = GetGameObject()->GetTags()[0];
       
       /* auto steeringBehaviour = GetGameObject()->getScene()->GetGameObjectsByName("SteeringBehaviour")[0];
        auto steeringBehaviourComponent = steeringBehaviour->GetComponent<SteeringBehaviour>();
        SteeringBehaviour steer{ trans.position, player->getTransform()->position , vel };*/
        // move to target till destination is reached
        spic::Point steering;
        steering.x = 0;
        steering.y = 0;
       
            if (IfPlayerNearby()) // if player is in radius of enemy
            {
                //TODO: checkWallAvoindance
                    //TODO: if in shooting range

                double Delta_x = (trans.position.x - player->getTransform()->position.x);
                double Delta_y = (trans.position.y - player->getTransform()->position.y);

                double Result = (atan2(Delta_y, Delta_x) * 180.0000) / 3.14159265;
                trans.rotation = Result + 90;

                if (!InShootingRange())
                {
                    steering = persue();
                    acc.Add(steering);
                    vel.Add(acc);
                    vel.Limit(10);

                    trans.position.Add(vel);
                }
            }
            else {
                
                double Delta_x = (trans.position.x - sight.x);
                double Delta_y = (trans.position.y - sight.y);

                double Result = (atan2(Delta_y, Delta_x) * 180.0000) / 3.14159265;
                trans.rotation = Result + 90;
                steering = wander();
                acc.Add(steering);
                vel.Add(acc);

                vel.Limit(10);
                /*if (wallAvoidance())
                {
                }*/
                trans.position.Add(vel);
                
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

spic::Point Enemy::persue()
{
    auto player = GetGameObject()->getScene()->GetGameObjectsByName("Player")[0];
    auto target = player->getTransform()->position;
    spic::Point prediction;
    prediction.x = cos(player->getTransform()->rotation);
    prediction.y = sin(player->getTransform()->rotation);
    target.Add(prediction);
    return seek(target);
}

spic::Point Enemy::seek(spic::Point target)
{
    spic::Point force;
    force.Sub(target, GetGameObject()->getTransform()->position);
    force.SetMag(speed);
    force.Sub(vel);
    force.Limit(0.25);
    return force;
}

spic::Point Enemy::wander() {
    auto enemyPos = GetGameObject()->getTransform()->position;
    double wanderR = 32;
    double wanderD = 120;
    int change = 100;
    wandertheta += rand() % change + (change * -1);
    spic::Point map;
    map.x = 1418;
    map.y = 1418;
    
    spic::Point pos = vel;
    pos.Normalize();
    pos.Mult(wanderD);
    pos.Add(GetGameObject()->getTransform()->position);
    double h = atan2(vel.y, vel.x);

    spic::Point offset;
    offset.x = wanderR * cos(wandertheta + h);
    offset.y = wanderR * sin(wandertheta + h);


    spic::Point target;
    target.x = pos.x;
    target.y = pos.y;
    target.Add(offset);

    target = wallAvoidance(target);
    //if (enemyPos.x >= map.x)
    //{
    //    target.x *= -1; //doet het goed
    //}

    //if (enemyPos.x <= 64)
    //{
    //    target.x *= -1; // kinks
    //    target.x += 1000;
    //}

    //if (enemyPos.y >= map.y)
    //{
    //    target.y *= -1; //doet het goed
    //}

    //if (enemyPos.y <= 64)
    //{
    //    target.y *= -1; //boven
    //    target.y += 1000;
    //}

    sight = pos;
    return seek(target);
}

spic::Point Enemy::wallAvoidance(spic::Point target)
{
    auto enemy = GetGameObject();
    auto enemyPos = enemy->getTransform()->position;
    
    spic::Point map;
    map.x = 1418;
    map.y = 1418;

    auto wall = Collision::AABB(enemy, "wall");

    if (wall)
    {
        auto wallPos = wall->GetGameObject()->getTransform()->position;
        if (wallPos.y >= enemyPos.y)
        {
            //target.y *= -1; //onder
            target.y += (-1000);
            target.x += -500;

        } else if(wallPos.y <= enemyPos.y)
        {
            //target.y *= -1;//boven
            target.y += 1000;
            target.x += (-500);
        }
        
        if (wallPos.x >= enemyPos.x) //*
        {
            //target.x *= -1; // rechts
            target.x += (-1000);
            target.y += 500;

        } else if (wallPos.x <= enemyPos.x)
        {
            //target.x *= -1; //links
            target.x += 1000;
            target.y += (-500);

        }
    }

    return target;
    //if (enemyPos.x >= map.x)
    //{
    //    target.x *= -1; //doet het goed
    //}

    //if (enemyPos.x <= 64)
    //{
    //    target.x *= -1; // kinks
    //    target.x += 1000;
    //}

    //if (enemyPos.y >= map.y)
    //{
    //    target.y *= -1; //doet het goed
    //}

    //if (enemyPos.y <= 64)
    //{
    //    target.y *= -1; //boven
    //    target.y += 1000;
    //}


    /*if (enemyPos.x >= map.x || enemyPos.x <= 64)
    {
        vel.x = vel.x * -1;
        wallIntersect = false;
    }
    else if (enemyPos.y <= 64 || enemyPos.y >= map.y) {
        vel.y = vel.y * -1;
        wallIntersect = false;
    }*/



    /*if (enemyPos.x >= map.x ||
        enemyPos.x <= 64 ||
        enemyPos.y >= map.y ||
        enemyPos.y <= 64) {
        return false;
    }
    return true;*/
    //return wallIntersect;
    //return wallIntersect;
}

void Enemy::OnClick()
{
}
