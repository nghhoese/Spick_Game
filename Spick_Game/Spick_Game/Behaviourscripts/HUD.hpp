#pragma once

#include <API_Headers/BehaviourScript.hpp>
#include <API_Headers/Engine.hpp>
#include <API_Headers/Text.hpp>
#include "InputScript.hpp"
#include <API_Headers/Scene.hpp>
#include <API_Headers/GameObject.hpp>
#include "../Controllers/EngineController.hpp"

class HUD : public spic::BehaviourScript {
private:
    int fps;
    int currentHealthPoints;
    int healthpoints;
    int currentCoins;
    int coins;
    int magazine;
    int currentMagazine;
    std::shared_ptr<spic::GameObject> InputObject;
public:
    HUD();
    void OnAwake();
    void OnStart();
    void OnUpdate();
    void OnRender();
    void OnClick();
    void OnTriggerEnter2D(const spic::Collider& collider);
    void OnTriggerExit2D(const spic::Collider& collider);
    void OnTriggerStay2D(const spic::Collider& collider);
    void SetFps(int fps) { this->fps = fps; };
    int GetFps() { return this->fps; };
    void SetHealthPoints(int healthpoints) { this->healthpoints = healthpoints; };
    int GetHealthPoints() { return this->healthpoints; };
    void SetMagazine(int magazine) { this->magazine = magazine; };
    int GetMagazine() { return this->magazine; };
    void SetCoins(int coins) { this->coins = coins; };
    int GetCoins() { return this->coins; };
};