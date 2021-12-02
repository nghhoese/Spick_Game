#pragma once

#include "API_Headers/BehaviourScript.hpp"
#include <string>

class Enemy : public spic::BehaviourScript {
private:
    int healthpoints;
    int damagePerBullet;
    std::string path;
    bool isMoving = false;
    bool isTurned = false;
    int turnCount = 0;
    double speed = 1.5;
public:
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
};