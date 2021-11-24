#pragma once
#include <API_Headers/BehaviourScript.hpp>
#include <API_Headers/Engine.hpp>

class HUD : public spic::BehaviourScript {
private:
    int fps = 0;
    spic::Engine* engine;
public:
    HUD(spic::Engine* engine);
    void OnAwake();
    void OnStart();
    void OnUpdate();
    void OnRender();
    void OnTriggerEnter2D(const Collider& collider);
    void OnTriggerExit2D(const Collider& collider);
    void OnTriggerStay2D(const Collider& collider);

    void SetFps(const int& fps);
    const int& GetFps();
};