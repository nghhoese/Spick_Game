#pragma once

#include "API_Headers/BehaviourScript.hpp"
#include <string>

class Enemy : public spic::BehaviourScript {
private:
    int healthpoints;
    int damagePerBullet;
    std::string path;
public:
    void OnAwake();
    void OnStart();
    void OnUpdate();
    void OnRender();
    void OnTriggerEnter2D(const Collider& collider);
    void OnTriggerExit2D(const Collider& collider);
    void OnTriggerStay2D(const Collider& collider);

    void setPath(const std::string& path);
    const std::string& getPath();

    void setHealthpoints(const int& healthpoints);
    const int& getHealthpoints();

    void setDamagePerBullet(const int& damagePerBullet);
    const int& getDamagePerBullet();
};