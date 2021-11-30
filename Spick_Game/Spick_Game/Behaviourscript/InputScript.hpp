#pragma once

#include "API_Headers/Point.hpp"
#include "API_Headers/KeyCode.hpp"
#include "API_Headers/GameObject.hpp"
#include "API_Headers/BehaviourScript.hpp"
#include "API_Headers/Time.hpp"
#include "API_Headers/Importation.hpp"
#include "API_Headers/Engine.hpp"
#include "../Player.hpp"
#include <IOSTREAM>

class InputScript : public spic::BehaviourScript {
private:
	spic::Importation* input;
	spic::Time* time;
	spic::Engine* engine;
	float deltaTime;
	bool speedup = false;
	bool speeddown = false;
	bool clicked = true;
public:
	InputScript();
	bool loadFps = false;
	const void checkMouseButtons();
	const void checkKeys();
	const spic::Point checkMousePosition();
	const spic::GameObject* GetPlayer();
    void OnAwake();
    void OnStart();
    void OnUpdate();
    void OnRender();
    void OnTriggerEnter2D(const Collider& collider);
    void OnClick();
    void OnTriggerExit2D(const Collider& collider);
    void OnTriggerStay2D(const Collider& collider);
};