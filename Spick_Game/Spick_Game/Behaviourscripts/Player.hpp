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
    double xPlayer;
    double yPlayer;
    int healthpoints;
    int currentHealthPoints;
    int coins;
    int currentCoins;
    int ammo;
    int bulletSpeed;
    int bulletDamage;
    double speed;
    bool notClicked;
    bool isDamageless;
    spic::Point aimAngle;
    spic::Point aimPos;
    std::vector<std::shared_ptr<spic::GameObject>> bullets;
    std::shared_ptr<spic::Sprite> sprite;
    spic::Time* time;
    std::shared_ptr<spic::GameObject> InputObject;
public:
    Player();
    void OnAwake();
    void OnStart();
    void OnUpdate();
    void OnRender();
    void OnTriggerEnter2D(const Collider& collider);
    void OnClick();
    void OnTriggerExit2D(const Collider& collider);
    void OnTriggerStay2D(const Collider& collider);
    void Shoot();
    void SetXPlayer(double x) { this->xPlayer = x; };
    double GetXPlayer() { return this->xPlayer; };
    void SetYPlayer(double y) { this->yPlayer = y; };
    double GetYPlayer() { return this->yPlayer; };
    void SetHealthpoints(int value) { this->healthpoints = value; };
    int GetHealtpoints() { return this->healthpoints; };
    void Setcoins(int value) { this->coins = value; };
    int GetCoins() { return this->coins; };
    void SetSpeed(double value) { this->speed = speed; };
    double GetSpeed() { return this->speed; };
    void SetNotClicked(bool value) { this->notClicked = value; };
    bool GetNotClicked() { return this->notClicked; };
    void SetIsDamageless(bool value) { this->isDamageless = value; };
    bool GetIsDamageLess() { return this->isDamageless; };
};