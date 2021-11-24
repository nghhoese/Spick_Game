#pragma once

#include "API_Headers/BehaviourScript.hpp"
#include "API_Headers/GameObject.hpp"
#include <iostream>

class ButtonBehaviour : public spic::BehaviourScript {
private:


public:
    ButtonBehaviour();
    virtual void OnAwake();
    void OnStart();
    void OnUpdate();
    void OnRender();
    void OnTriggerEnter2D(const Collider& collider);
    ButtonBehaviour(const std::string& name);
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
};