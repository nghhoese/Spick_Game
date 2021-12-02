#pragma once
#include "API_Headers/BehaviourScript.hpp"
#include "API_Headers/Point.hpp"
#include "API_Headers/GameObject.hpp"
#include "Enemy.hpp"

class Bullet : public spic::BehaviourScript {
public:
    spic::Point position;
    double speed;
    double amountToMoveX;
    double amountToMoveY;
    spic::Point direction;
    int damage;

    Bullet(spic::Point pos, spic::Point direction, double speed, int damage);
    Bullet();
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
private:
    bool hit = true;
};