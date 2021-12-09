#pragma once

#include <math.h>
#include "API_Headers/BehaviourScript.hpp"
#include "API_Headers/Point.hpp"
#include "API_Headers/GameObject.hpp"
#include "API_Headers/Time.hpp"
#include "API_Headers/Scene.hpp"
#include "Enemy.hpp"

class Bullet : public spic::BehaviourScript {
private:
    bool hit;
    bool broken;
    double speed;
    double amountToMoveX;
    double amountToMoveY;
    int damage;
    spic::Point direction;
    spic::Point position;
public:
    Bullet(spic::Point pos, spic::Point direction, double speed, int damage);
    void Update();
    void OnAwake();
    void OnStart();
    void OnUpdate();
    void OnRender();
    void OnTriggerEnter2D(const spic::Collider& collider);
    void OnClick();
    void CalculateAmountToMove();
    void OnTriggerExit2D(const spic::Collider& collider);
    void OnTriggerStay2D(const spic::Collider& collider);
    void SetBroken(bool value) { this->broken = value; };
    bool GetBroken() { return this->broken; };
    void SetDirection(spic::Point direction) { this->direction = direction; };
    spic::Point GetDirection() { return direction; };
    void SetPosition(spic::Point position) { this->position = position; };
    spic::Point GetPosition() { return this->position; };
};
