#pragma once

#include "API_Headers/Point.hpp"
#include "API_Headers/KeyCode.hpp"
#include "API_Headers/BehaviourScript.hpp"
#include "API_Headers/Transform.hpp"
#include "API_Headers/GameObject.hpp"
#include <API_Headers/Rectangle.hpp>
#include <API_Headers/Scene.hpp>
#include <API_Headers/Camera.hpp>
#include <API_Headers/Sprite.hpp>
#include <API_Headers/Text.hpp>
#include "Bullet.hpp"
#include <iostream>
#include <API_Headers/Engine.hpp>
#include "InputScript.hpp"
#include "HUD.hpp"
#include "../Controllers/EngineController.hpp"
#include "../Controllers/AIController.hpp"

class Enemy : public spic::BehaviourScript {
private:
    std::string path;
    int healthpoints;
    int damagePerBullet;
    bool isTurned = false;
    int turnCount = 0;
    double speed;
    bool IfPlayerNearby();
    bool InShootingRange();
    bool isShooting = false;;
    int triggerSpace = 250;
    int shootingSpace = 150;
    spic::Point sight;
    bool check = false;
    bool isPersuing = false;
    int persueCount = 0;
    double wandertheta = 0;
    bool isAlive = true;
    spic::Point acc; //versnelling
    spic::Point vel; //snelheid
    std::unique_ptr<AIController> AI;
    bool notInitialized;
    void Shoot();
    int ammo;
    int magazine;
    int currentMagazine;
    int coolDown;
    int bulletSpeed;
    int bulletDamage;
    std::vector<std::shared_ptr<Bullet>> bullets;
    std::shared_ptr<spic::GameObject> player;
    std::shared_ptr<spic::Sprite> sprite;
    bool hit;
public:
    Enemy();
    void OnAwake();
    void OnStart();
    void OnUpdate();
    void OnRender();
    void OnClick();
    void SetMagazine(int magazine) { this->magazine = magazine; };
    void OnTriggerEnter2D(const spic::Collider& collider);
    void OnTriggerExit2D(const spic::Collider& collider);
    void OnTriggerStay2D(const spic::Collider& collider);
    void setPath(const std::string& path);
    const std::string& getPath();
    void FillBucket();
    void setHealthpoints(int healthpoints) { this->healthpoints = healthpoints; };
    int getHealthpoints() { return this->healthpoints; };
    void setDamagePerBullet(int damagePerBullet) { this->damagePerBullet = damagePerBullet; };
    int getDamagePerBullet() { return this->damagePerBullet; };
    void setSpeed(double speed) { this->speed = speed; }
    double getSpeed() { return this->speed; }
};