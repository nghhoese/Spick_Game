#pragma once

#include "API_Headers/Importation.hpp"
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
#include <API_Headers/Time.hpp>

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
    float deltaTime;
public:
    Player();
    double xPlayer;
    double yPlayer;
    double speed = 1.5;
    const void checkMouseButtons();
    const void checkKeys();
    const spic::Point checkMousePosition();
    void OnAwake();
    void OnStart();
    void OnUpdate();
    void OnRender();
    void OnTriggerEnter2D(const Collider& collider);
    void OnClick();
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

    std::shared_ptr<spic::GameObject> createBullet();
    void Shoot();
    void CalculateAimPosition();
};
