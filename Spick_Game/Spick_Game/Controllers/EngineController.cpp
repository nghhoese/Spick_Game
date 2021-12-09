#include "EngineController.hpp"

static EngineController* instance;

EngineController::EngineController() : engine(std::make_unique<spic::Engine>())
{
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

bool EngineController::GetCheatsEnabled()
{
	return engine->getCheatsEnabled();
}

void EngineController::SetCheatsEnabled(bool cheatsBool)
{
	engine->setCheatsEnabled(cheatsBool);
}

bool EngineController::GetIsInLevelTransition()
{
	return engine->getIsInLevelTransition();
}

void EngineController::SetIsInLevelTransition(bool transitionBool)
{
	engine->setIsInLevelTransition(transitionBool);
}