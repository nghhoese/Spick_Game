#pragma once

#include "API_Headers/BehaviourScript.hpp"
#include "BehaviourScript/SteeringBehaviour.hpp"
#include "API_Headers/Point.hpp"
#include <math.h>
#include <string>

class Enemy : public spic::BehaviourScript {
private:
    int healthpoints;
    int damagePerBullet;
    std::string path;
    bool isTurned = false;
    int turnCount = 0;
    double speed = 5;
    bool IfPlayerNearby();
    int triggerSpace = 250;
    bool check = false;
public:
    bool isAlive = true;
    spic::Point acc; //versnelling
    spic::Point vel; //snelheid
    void OnAwake();
    void OnStart();
    void OnUpdate();
    void OnRender();
    void OnClick();
    void OnTriggerEnter2D(const Collider& collider);
    void OnTriggerExit2D(const Collider& collider);
    void OnTriggerStay2D(const Collider& collider);

    void setPath(const std::string& path);
    const std::string& getPath();

    void setHealthpoints(const int& healthpoints);
    const int& getHealthpoints();

    void setDamagePerBullet(const int& damagePerBullet);
    const int& getDamagePerBullet();

    void setSpeed(const double& speed) { this->speed = speed; }
    const int& getSpeed() { return this->speed; }

    spic::Point persue();

    spic::Point seek(spic::Point target);
};