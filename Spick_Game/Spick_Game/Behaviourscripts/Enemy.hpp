#pragma once

#include "API_Headers/BehaviourScript.hpp"
#include <string>

class Enemy : public spic::BehaviourScript {
private:
    int healthpoints;
    int damagePerBullet;
    std::string path;
    bool isTurned;
    int turnCount;
    double speed;
    bool isAlive;
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
    void setHealthpoints(int healthpoints) { this->healthpoints = healthpoints; };
    int getHealthpoints() { return this->healthpoints; };
    void setDamagePerBullet(int damagePerBullet) { this->damagePerBullet = damagePerBullet; };
    int getDamagePerBullet() { return this->damagePerBullet; };
    void setSpeed(double speed) { this->speed = speed; }
    double getSpeed() { return this->speed; }
};