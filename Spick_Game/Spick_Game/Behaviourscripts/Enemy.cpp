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
        if (IfPlayerNearby()) // if player is in radius of enemy
        {
            steering = persue();
            double Delta_x = (trans.position.x - player->getTransform()->position.x);
            double Delta_y = (trans.position.y - player->getTransform()->position.y);

            double Result = (atan2(Delta_y, Delta_x) * 180.0000) / 3.14159265;
            trans.rotation = Result + 90;
           
        }
        else {
            steering = wander();
            //trans.rotation = atan2(vel.y, vel.x);
        }

        acc.Add(steering);
        vel.Add(acc);

        vel.Limit(10);
        //do wall avoidance
        //vel.Add(wallAvoidance());
        trans.position.Add(vel);
        
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
    force.SetMag(speed);
    force.Sub(vel);
    force.Limit(0.25);
    return force;
}

spic::Point Enemy::wander() {
    double wanderR = 32;
    double wanderD = 120;
    int change = 4;
    wandertheta += rand() % change + (change * -1);

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
    return seek(target);
}

spic::Point Enemy::wallAvoidance()
{
    double wanderR = 32;
    auto enemy = GetGameObject();
    auto enemyPos = enemy->getTransform()->position;
    
    // Create feeler
    spic::Point feeler;
    feeler.x = enemyPos.x;
    feeler.y = enemyPos.y;
    feeler.Add(64);

    // if feeler of enemy intersects with wall
    auto wall = Collision::AABB(enemy, "wall");
    spic::Point closestPoint;
    spic::Point overShoot;
    spic::Point steeringForce = vel;
    if (wall)
    {
        auto wallPos = Collision::AABB(enemy, "wall")->GetGameObject()->getTransform()->position;

        if (feeler.x >= wallPos.x &&
            feeler.x - 128 <= wallPos.x &&
            feeler.y >= wallPos.y &&
            feeler.y - 128 <= wallPos.y) {
            //calculate new direction
            overShoot.Sub(feeler, wallPos);
            auto newWallPos = wallPos.Normalize();
            newWallPos.Mult(overShoot.Mag());
            steeringForce = seek(newWallPos);
        }
    }
    
    return steeringForce;
}

void Enemy::OnClick()
{
}
