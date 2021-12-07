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
	return false;
}

void EngineController::SetActiveScene(std::string sceneName)
{
	engine->SetActiveScene(sceneName);
}

void EngineController::SetActiveScene(std::shared_ptr<spic::Scene> scene)
{
	engine->SetActiveScene(scene);
}

void EngineController::AddScene(std::shared_ptr<spic::Scene> scene)
{
	engine->AddScene(scene);
}

void EngineController::CreateNewWindow(const std::string& windowName)
{
	engine->CreateNewWindow(windowName);
}

void EngineController::StartGameLoop()
{
	engine->StartGameLoop();
}

std::pair<std::vector<std::pair<int, std::vector<std::vector<int>>>>, std::vector<std::vector<std::pair<std::string, std::any>>>> EngineController::GetLevel(const std::filesystem::path& path)
{
	return engine->GetLevel(path);
}
