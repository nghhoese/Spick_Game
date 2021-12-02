#pragma once
#include <API_Headers/BehaviourScript.hpp>
#include <API_Headers/Engine.hpp>
#include <API_Headers/Text.hpp>
#include "Behaviourscript/InputScript.hpp"
#include <API_Headers/Scene.hpp>
#include <API_Headers/GameObject.hpp>

class HUD : public spic::BehaviourScript {
private:
    int fps = 0;
    int currentHealthPoints;
    int healthpoints;
    int currentCoins;
    int coins;
    std::shared_ptr<spic::GameObject> InputObject;
    spic::Engine* engine;
public:
    HUD(spic::Engine* engine);
    void OnAwake();
    void OnStart();
    void OnUpdate();
    void OnRender();
    void OnClick();
    void OnTriggerEnter2D(const Collider& collider);
    void OnTriggerExit2D(const Collider& collider);
    void OnTriggerStay2D(const Collider& collider);

    void SetFps(const int& fps);
    const int& GetFps();
    void SetHealthPoints(const int& healthpoints);
    const int& GetHealthPoints();
    void SetCoins(const int& coins);
    const int& GetCoins();
};