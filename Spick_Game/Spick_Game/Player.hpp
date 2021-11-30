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
#include "Bullet.h"
#include <iostream>
#include <API_Headers/Engine.hpp>
#include "Behaviourscript/InputScript.hpp"

class Player : public spic::BehaviourScript {
private:
    int currentHealthPoints;
    int healthpoints = 100;
    int currentCoins;
    int coins = 10;
    int ammo = 0;
    int bulletSpeed = 10;
    spic::Point aimAngle;
    spic::Point aimPos;
    std::vector<std::shared_ptr<spic::GameObject>> bullets;
    std::shared_ptr<spic::Sprite> sprite;
    spic::Time* time;
    bool notClicked = true;
    spic::Engine* engine;
    std::shared_ptr<spic::GameObject> InputObject;
public:
    Player();
    Player(spic::Engine* engine);
    double xPlayer;
    double yPlayer;
    double speed = 1.5;
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