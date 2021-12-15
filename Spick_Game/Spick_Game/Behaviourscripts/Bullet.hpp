#pragma once

#include <math.h>
#include "API_Headers/BehaviourScript.hpp"
#include "API_Headers/Point.hpp"
#include "API_Headers/GameObject.hpp"
#include "API_Headers/Time.hpp"
#include "API_Headers/Scene.hpp"


class Bullet : public spic::BehaviourScript {
private:
    bool hit;
    bool broken;
    double speed;
    double amountToMoveX;
    double amountToMoveY;
    int damage;
    bool isPlayer = false;
    spic::Point direction;
    spic::Point position;
public:
    Bullet(spic::Point pos, spic::Point direction, double speed, int damage);
    void Update();
    void OnAwake();
    void OnStart();
    void OnUpdate();
    void SetPlayer(bool player) { this->isPlayer = player; };
    void OnRender();
    void OnTriggerEnter2D(const spic::Collider& collider);
    void OnClick();
    int GetDamage() { return damage; };
    void CalculateAmountToMove();
    void OnTriggerExit2D(const spic::Collider& collider);
    void OnTriggerStay2D(const spic::Collider& collider);
    void SetBroken(bool value) { this->broken = value; };
    bool GetBroken() { return this->broken; };
    void SetDirection(int x, int y) { this->direction.x = x;this->direction.y = y; };
    spic::Point GetDirection() { return direction; };
    void SetPosition(spic::Point position) { this->position = position; };
    spic::Point GetPosition() { return this->position; };
};
