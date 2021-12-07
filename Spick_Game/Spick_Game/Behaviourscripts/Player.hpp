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

class Player : public spic::BehaviourScript {
private:
    int healthpoints = 100;
    int currentCoins;
    int coins = 0;
    int ammo = 0;
    int bulletSpeed = 10;
    int bulletDamage = 30;
    spic::Point aimAngle;
    spic::Point aimPos;
    std::vector<std::shared_ptr<spic::GameObject>> bullets;
    std::shared_ptr<spic::Sprite> sprite;
    spic::Time* time;
    std::shared_ptr<spic::GameObject> InputObject;
public:
    Player();
    int currentHealthPoints;
    double xPlayer;
    double yPlayer;
    double speed = 5;
    bool notClicked = true;
    bool isDamageless = false;
    void OnAwake();
    void OnStart();
    void OnUpdate();
    void OnRender();
    void OnTriggerEnter2D(const Collider& collider);
    void OnClick();
    void OnTriggerExit2D(const Collider& collider);
    void OnTriggerStay2D(const Collider& collider);
    void Shoot();
};