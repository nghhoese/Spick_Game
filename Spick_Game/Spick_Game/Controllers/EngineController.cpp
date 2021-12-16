#include "EngineController.hpp"

static EngineController* instance;

EngineController::EngineController() : engine(std::make_unique<spic::Engine>()), time(std::make_unique<spic::Time>())
{
	this->GetDesktopResolution();
}

EngineController* EngineController::GetInstance()
{
	if (!instance)
	{
		instance = new EngineController();
	}
	return instance;
}

int EngineController::GetFPS()
{
	return engine->GetFPS();
}

void EngineController::SetGameOver(bool value)
{
	engine->setGameOver(value);
}

bool EngineController::GetGameOver()
{
	return engine->getGameOver();
}

void EngineController::SetActiveScene(std::string sceneName)
{
	engine->SetActiveScene(sceneName);
}
std::shared_ptr<spic::Scene> EngineController::GetActiveScene()
{
	return engine->GetActiveScene();
}

void EngineController::SetActiveScene(std::shared_ptr<spic::Scene> scene)
{
	engine->SetActiveScene(scene);
}

void EngineController::AddScene(std::shared_ptr<spic::Scene> scene)
{
	engine->AddScene(scene);
}

void EngineController::CreateNewWindow(const std::string& windowName, int width, int height)
{
	engine->CreateNewWindow(windowName, width, height);
}

void EngineController::StartGameLoop()
{
	engine->StartGameLoop();
}

std::shared_ptr<spic::Scene> EngineController::GetSceneByName(const std::string& sceneName)
{
	return engine->GetSceneByName(sceneName);
}

std::pair<std::vector<std::pair<int, std::vector<std::vector<int>>>>, std::vector<std::vector<std::pair<std::string, std::any>>>> EngineController::GetLevel(const std::filesystem::path& path)
{
	return engine->GetLevel(path);
}

std::vector<std::shared_ptr<spic::Scene>> EngineController::GetScenes()
{
	return engine->GetScenes();
}

void EngineController::EndGameLoop()
{
	engine->EndGameLoop();
}

void EngineController::SetCurrentLevel(int currentLevelNumber)
{
	engine->setCurrentLevel(currentLevelNumber);
}

int EngineController::GetCurrentLevel()
{
	return engine->getCurrentLevel();
}

bool EngineController::GetIsInLevelTransition()
{
	return engine->getIsInLevelTransition();
}

void EngineController::SetIsInLevelTransition(bool transitionBool)
{
	engine->setIsInLevelTransition(transitionBool);
}

bool EngineController::GetCheatsEnabled()
{
	return engine->getCheatsEnabled();
}

void EngineController::SetCheatsEnabled(bool cheatsBool)
{
	engine->setCheatsEnabled(cheatsBool);
}

void EngineController::BuildLevels()
{
	std::shared_ptr<LevelSceneBuilder> levelSceneBuilder = std::make_shared<LevelSceneBuilder>();
	levelSceneBuilder->BuildLevel(1);
	levelSceneBuilder->BuildLevel(2);
	levelSceneBuilder->BuildLevel(3);
	SetCurrentLevel(1);
}

void EngineController::BuildGameOverScene()
{
	std::shared_ptr<GameOverBuilder> gameOverSceneBuilder = std::make_shared<GameOverBuilder>();
	std::shared_ptr<spic::Scene> gameOverScene = gameOverSceneBuilder->BuildScene();
	AddScene(gameOverScene);
	gameOverSceneBuilder->BuildScript();
}

void EngineController::BuildCheatScene()
{
	std::shared_ptr<CheatsMenuBuilder> cheatsMenuBuilder = std::make_shared<CheatsMenuBuilder>();
	std::shared_ptr<spic::Scene> cheatsMenuScene = cheatsMenuBuilder->BuildScene();
	AddScene(cheatsMenuScene);
}

void EngineController::BuildHelpScene()
{
	std::shared_ptr<HelpSceneBuilder> helpSceneBuilder = std::make_shared<HelpSceneBuilder>();
	std::shared_ptr<spic::Scene> helpScene = helpSceneBuilder->BuildScene();
	AddScene(helpScene);
}

void EngineController::BuildCreditScene()
{
	std::shared_ptr<CreditsSceneBuilder> creditsSceneBuilder = std::make_shared<CreditsSceneBuilder>();
	std::shared_ptr<spic::Scene> creditsScene = creditsSceneBuilder->BuildScene();
	EngineController::GetInstance()->AddScene(creditsScene);
}

void EngineController::BuildCompletedScene()
{
	std::shared_ptr<CompletedSceneBuilder> completedSceneBuilder = std::make_shared<CompletedSceneBuilder>();
	std::shared_ptr<spic::Scene> completedScene = completedSceneBuilder->BuildScene();
	EngineController::GetInstance()->AddScene(completedScene);
}

void EngineController::StartGame()
{
	CreateNewWindow("Tactical Stealth", GetScreenWidth(), GetScreenHeight());
	std::shared_ptr<spic::Scene> mainMenu = BuildMainMenu();

	AddScene(mainMenu);
	BuildLevels();
	MusicController::GetInstance()->SetLevelMusic();
	MusicController::GetInstance()->SetMainMenuMusic(mainMenu);
	BuildGameOverScene();
	BuildCheatScene();
	BuildHelpScene();
	BuildCreditScene();
	BuildCompletedScene();
	SetActiveScene(mainMenu);
	StartGameLoop();
}

float EngineController::GetTime()
{
	return time->CalculateDeltaTime();
}

void EngineController::GetDesktopResolution()
{
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);
	this->screenWidth = desktop.right;
	this->screenHeight = desktop.bottom;
}

std::shared_ptr<spic::Scene> EngineController::BuildMainMenu()
{
	std::shared_ptr<MainMenuBuilder> mainMenuBuilder = std::make_shared<MainMenuBuilder>();
	std::shared_ptr<spic::Scene> mainMenu = mainMenuBuilder->BuildScene();
	return mainMenu;
}