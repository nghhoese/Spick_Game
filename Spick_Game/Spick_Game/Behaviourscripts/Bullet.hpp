#pragma once

#include <math.h>
#include "API_Headers/BehaviourScript.hpp"
#include "API_Headers/Point.hpp"
#include "API_Headers/GameObject.hpp"
#include "API_Headers/Time.hpp"
#include "API_Headers/Scene.hpp"
#include "Enemy.hpp"

class Bullet : public spic::BehaviourScript {
public:
    Bullet(spic::Point pos, spic::Point direction, double speed, int damage);
    void Update();
    void OnAwake();
    void OnStart();
    void OnUpdate();
    void OnRender();
    void OnTriggerEnter2D(const Collider& collider);
    void OnClick();
    void CalculateAmountToMove();
    void OnTriggerExit2D(const Collider& collider);
    void OnTriggerStay2D(const Collider& collider);
    bool inUse = false;
    bool broken = true;
    spic::Point position;
    spic::Point direction;
private:
    bool hit;
    

    double speed;
    double amountToMoveX;
    double amountToMoveY;

    int damage;

};
