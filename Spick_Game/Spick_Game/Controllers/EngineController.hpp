#pragma once

#include <iostream>
#include <API_Headers/Engine.hpp>

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
	std::shared_ptr<spic::Scene> GetActiveScene();
	void SetActiveScene(std::shared_ptr<spic::Scene> scene);
	void AddScene(std::shared_ptr<spic::Scene> scene);
	void CreateNewWindow(const std::string& windowName);
	void StartGameLoop();
	std::shared_ptr<spic::Scene> GetSceneByName(const std::string& sceneName);
	std::pair<std::vector<std::pair<int, std::vector<std::vector<int>>>>, std::vector<std::vector<std::pair<std::string, std::any>>>> GetLevel(const std::filesystem::path& path);
};