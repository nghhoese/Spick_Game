#include "AIController.hpp"

AIController::AIController(spic::GameObject persuerGameObject, spic::Point vel, spic::GameObject escapeeGameObject, double speed) : wandertheta(0), speed(speed)
{
    persuer = std::make_unique<spic::GameObject>(persuerGameObject);
    escapee = std::make_unique<spic::GameObject>(escapeeGameObject);
}

spic::Point AIController::Wander()
{
    double wanderR = 32;
    double wanderD = 120;
    int change = 10;
    wandertheta += rand() % change + (change * -1);

    spic::Point pos = vel;
    pos.Normalize();
    pos.Mult(wanderD);
    pos.Add(persuer->getTransform()->position);
    double h = atan2(vel.y, vel.x);

    spic::Point offset;
    offset.x = wanderR * cos(wandertheta + h);
    offset.y = wanderR * sin(wandertheta + h);

    spic::Point target;
    target.x = pos.x;
    target.y = pos.y;
    target.Add(offset);

    target = WallAvoidance(target);

    sight = pos;
    return Seek(target);
}

spic::Point AIController::Persue()
{
    auto target = escapee->getTransform()->position;
    spic::Point prediction;
    prediction.x = cos(escapee->getTransform()->rotation);
    prediction.y = sin(escapee->getTransform()->rotation);
    target.Add(prediction);
    auto targetWithWallAvoidance = WallAvoidance(target);
    if (targetWithWallAvoidance.x == target.x && targetWithWallAvoidance.y == target.y)
    {
        return Seek(target);
    }
    return Seek(targetWithWallAvoidance);
}

spic::Point AIController::Seek(spic::Point target)
{
    spic::Point force;
    force.Sub(target, persuer->getTransform()->position);
    force.SetMag(speed);
    force.Sub(vel);
    force.Limit(0.25);
    return force;
}

spic::Point AIController::WallAvoidance(spic::Point target)
{
    auto temp = persuer.get();
    auto wall = Collision::AABB(persuer.get(), "wall");

    if (wall)
    {
        auto wallPos = wall->GetGameObject()->getTransform()->position;
        if (wallPos.y >= persuer->getTransform()->position.y)
        {
            target.y += (-1000);
            target.x += -500;

        }
        else if (wallPos.y <= persuer->getTransform()->position.y)
        {
            target.y += 1000;
            target.x += (-500);
        }

        if (wallPos.x >= persuer->getTransform()->position.x)
        {
            target.x += (-1000);
            target.y += 500;

        }
        else if (wallPos.x <= persuer->getTransform()->position.x)
        {
            target.x += 1000;
            target.y += (-500);

        }
    }

    return target;
}

void AIController::Update(spic::GameObject persuerGameObject, spic::Point vel, spic::GameObject escapeeGameObject)
{
    auto persueTrans = *persuer->getTransform();
    persueTrans.position = persuerGameObject.getTransform()->position;
    persuer->setTransform(&persueTrans);

    auto escapeeTrans = *escapee->getTransform();
    escapeeTrans.position = escapeeGameObject.getTransform()->position;
    escapeeTrans.rotation = escapeeGameObject.getTransform()->rotation;
    escapee->setTransform(&escapeeTrans);

    this->vel = vel;
}
