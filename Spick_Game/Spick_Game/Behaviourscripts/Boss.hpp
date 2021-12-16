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

class Boss : public spic::BehaviourScript {
private:

    bool isAlive = true;
    bool notInitialized;

    int magazine;
    int currentMagazine;
    int coolDown;
    int burstSpeed;
    int burstCooldown;
    int bulletSpeed;
    int bulletDamage;
    int bulletCounter;
    int maxhealthpoints;
    int healthpoints;
    int damagePerBullet;

    std::string path;
    std::vector<std::shared_ptr<Bullet>> bullets;
    std::shared_ptr<spic::GameObject> player;
    std::shared_ptr<spic::Sprite> sprite;
    spic::Transform trans;
    std::unique_ptr<AIController> AI;

    void Shoot();
    void CalculateRotation(spic::Point object, spic::Point target);
    void BulletHandling();
    void DoBossThings();
public:
    Boss();
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
};
