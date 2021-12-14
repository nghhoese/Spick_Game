#pragma once

#include "API_Headers/Point.hpp"
#include "API_Headers/KeyCode.hpp"
#include "API_Headers/GameObject.hpp"
#include "API_Headers/BehaviourScript.hpp"
#include "API_Headers/Time.hpp"
#include "API_Headers/Importation.hpp"
#include "../Controllers/EngineController.hpp"
#include "Player.hpp"
#include <IOSTREAM>

class InputScript : public spic::BehaviourScript {
private:
	std::unique_ptr<spic::Time> time;
	std::unique_ptr<spic::Importation> input;
	float deltaTime;
	bool speedup;
	bool speeddown;
	bool pausing;
	bool clicked;
	bool paused;
	bool loadFps;
public:
	InputScript();
	const void checkMouseButtons();
	const void checkKeys();
	const void CheckPause();
	const spic::Point checkMousePosition();
	const spic::GameObject* GetPlayer();
    void OnAwake();
    void OnStart();
    void OnUpdate();
    void OnRender();
    void OnTriggerEnter2D(const spic::Collider& collider);
    void OnClick();
    void OnTriggerExit2D(const spic::Collider& collider);
    void OnTriggerStay2D(const spic::Collider& collider);
	void SetDeltaTime(float value) { this->deltaTime = value; }
	float GetDeltaTime() { return this->deltaTime; };
	void SetSpeedUp(bool value) { this->speedup = value; };
	bool GetSpeedUp() { return this->speedup; };
	void SetSpeedDown(bool value) { this->speeddown = value; };
	bool GetSpeedDown() { return this->speeddown; };
	void SetPausing(bool value) { this->pausing = value; };
	bool GetPausing() { return this->pausing; };
	void SetClicked(bool value) { this->clicked = value; };
	bool GetClicked() { return this->clicked; };
	void SetPaused(bool value) { this->paused = value; };
	bool GetPaused() { return this->paused; };
	void SetLoadFps(bool value) { this->loadFps = value; };
	bool GetLoadFps() { return this->loadFps; };
	void PauseGame();
	void UnPauseGame();
};