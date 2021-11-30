#pragma once
#include "API_Headers/BehaviourScript.hpp"
#include "API_Headers/Point.hpp"
#include "API_Headers/GameObject.hpp"



class Bullet : public spic::BehaviourScript {
public:
    spic::Point position;
    double speed;
    double amountToMoveX;
    double amountToMoveY;
    spic::Point direction;

    Bullet(spic::Point pos, spic::Point direction, double speed);
    Bullet();
    void Update();

    void OnAwake();
    void OnStart();
    void OnUpdate();
    void OnRender();
    void OnTriggerEnter2D(const Collider& collider);
    void OnClick();
    void CalculateAmountToMove();
    /**
     * @brief Sent when another object leaves a trigger collider
     *        attached to this object (2D physics only).
     */
    void OnTriggerExit2D(const Collider& collider);

    /**
     * @brief Sent each frame where another object is within a trigger
     *        collider attached to this object (2D physics only).
     */
    void OnTriggerStay2D(const Collider& collider);
private:

};