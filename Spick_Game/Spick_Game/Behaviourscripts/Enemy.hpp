#pragma once

#include "API_Headers/BehaviourScript.hpp"
#include "../Behaviourscripts/SteeringBehaviour.hpp"
#include "API_Headers/Point.hpp"
#include <math.h>
#include <string>
#include "API_Headers/Time.hpp"

class Enemy : public spic::BehaviourScript {
private:
    std::string path;
    int healthpoints;
    int damagePerBullet;
    bool isTurned = false;
    int turnCount = 0;
    double speed;
    bool IfPlayerNearby();
    int triggerSpace = 250;
    bool check = false;
    bool isPersuing = false;
    int persueCount = 0;
    double wandertheta = 0;
    spic::Point target;
    bool isAlive = true;
    spic::Point acc; //versnelling
    spic::Point vel; //snelheid
public:
    Enemy();
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

    spic::Point persue();

    spic::Point seek(spic::Point target);

    spic::Point wander();

    spic::Point wallAvoidance();
    void setHealthpoints(int healthpoints) { this->healthpoints = healthpoints; };
    int getHealthpoints() { return this->healthpoints; };
    void setDamagePerBullet(int damagePerBullet) { this->damagePerBullet = damagePerBullet; };
    int getDamagePerBullet() { return this->damagePerBullet; };
    void setSpeed(double speed) { this->speed = speed; }
    double getSpeed() { return this->speed; }
};