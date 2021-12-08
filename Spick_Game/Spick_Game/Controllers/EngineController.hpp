#pragma once

#include <iostream>
#include <API_Headers/Engine.hpp>
#include <API_Headers/GameObject.hpp>

class EngineController {
private:
	std::unique_ptr<spic::Engine> engine;
	EngineController();
public:
	static EngineController* GetInstance();
	int GetFPS();
	void SetGameOver(bool value);
	bool GetGameOver();
	void SetActiveScene(std::string sceneName);
	void SetActiveScene(std::shared_ptr<spic::Scene> scene);
	void AddScene(std::shared_ptr<spic::Scene> scene);
	void CreateNewWindow(const std::string& windowName);
	void StartGameLoop();
	void SetCurrentLevel(int currentLevelNumber);
	int GetCurrentLevel();
	bool GetCheatsEnabled();
	void SetCheatsEnabled(bool cheatsBool);
	std::shared_ptr<spic::Scene> GetSceneByName(const std::string& sceneName);
	std::pair<std::vector<std::pair<int, std::vector<std::vector<int>>>>, std::vector<std::vector<std::pair<std::string, std::any>>>> GetLevel(const std::filesystem::path& path);
};