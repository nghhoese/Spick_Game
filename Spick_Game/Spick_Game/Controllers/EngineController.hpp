#pragma once

#include <iostream>
#include <API_Headers/Engine.hpp>
#include "../Scenes/MainMenuBuilder.hpp"
#include "../Scenes/GameOverSceneBuilder.hpp"
#include "../Scenes/CheatsMenuBuilder.hpp"
#include "../Scenes/HelpSceneBuilder.hpp"
#include "../Scenes/CreditsSceneBuilder.hpp"
#include "../Scenes/CompletedSceneBuilder.hpp"
#include "MusicController.hpp"
#include "wtypes.h"

class EngineController {
private:
	std::unique_ptr<spic::Engine> engine;
	std::unique_ptr<spic::Time> time;
	int screenWidth;
	int screenHeight;
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
	void CreateNewWindow(const std::string& windowName, int width, int height);
	void StartGameLoop();
	void EndGameLoop();
	void SetCurrentLevel(int currentLevelNumber);
	int GetCurrentLevel();
	bool GetIsInLevelTransition();
	void SetIsInLevelTransition(bool transitionBool);
	bool GetCheatsEnabled();
	void SetCheatsEnabled(bool cheatsBool);
	void BuildLevels();
	void BuildGameOverScene();
	void BuildCheatScene();
	void BuildHelpScene();
	void BuildCreditScene();
	void BuildCompletedScene();
	void StartGame();
	float GetTime();
	void GetDesktopResolution();
	std::shared_ptr<spic::Scene> BuildMainMenu();
	std::shared_ptr<spic::Scene> GetSceneByName(const std::string& sceneName);
	std::pair<std::vector<std::pair<int, std::vector<std::vector<int>>>>, std::vector<std::vector<std::pair<std::string, std::any>>>> GetLevel(const std::filesystem::path& path);
	std::vector<std::shared_ptr<spic::Scene>> GetScenes();
	int GetScreenWidth() { return this->screenWidth; };
	void SetScreenWidth(int screenWidth) { this->screenWidth = screenWidth; };
	int GetScreenHeight() { return this->screenHeight; };
	void SetScreenHeight(int screenHeight) { this->screenHeight = screenHeight; };
};