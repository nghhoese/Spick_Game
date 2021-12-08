#include "ChangeSceneBehaviour.hpp"

ChangeSceneBehaviour::ChangeSceneBehaviour(const std::string& name, const std::string& scene) : _scene(scene){
	Name(name);
}

void ChangeSceneBehaviour::OnClick()
{
	if (EngineController::GetInstance()->GetCurrentLevel() != 1 && !EngineController::GetInstance()->GetCheatsEnabled() && !EngineController::GetInstance()->GetGameOver()) {
		std::string levelString = "level" + std::to_string(EngineController::GetInstance()->GetCurrentLevel());
		_scene = levelString;

		std::string previousLevelString = "level" + std::to_string(EngineController::GetInstance()->GetCurrentLevel() - 1);

		std::shared_ptr<spic::GameObject> existingPlayerObject = EngineController::GetInstance()->GetSceneByName(previousLevelString)->GetGameObjectsByName("Player")[0];

		auto level2 = EngineController::GetInstance()->GetSceneByName(levelString);

		level2->AddGameObject(existingPlayerObject);

		auto PlayerComponent = existingPlayerObject->GetComponent<Player>();
		PlayerComponent->FillBucket();
	    PlayerComponent->OnStart();

	}

	if (EngineController::GetInstance()->GetGameOver()) {
		std::shared_ptr<LevelSceneBuilder> levelSceneBuilder = std::make_shared<LevelSceneBuilder>();
		levelSceneBuilder->BuildLevel(1);
		levelSceneBuilder->BuildLevel(2);
		levelSceneBuilder->BuildLevel(3);
		EngineController::GetInstance()->SetCurrentLevel(1);
		EngineController::GetInstance()->SetGameOver(false);
	}

	EngineController::GetInstance()->SetCheatsEnabled(false);
	EngineController::GetInstance()->SetActiveScene(_scene);
}

void ChangeSceneBehaviour::OnUpdate() {
}

void ChangeSceneBehaviour::OnAwake()
{
}

void ChangeSceneBehaviour::OnStart()
{
}

void ChangeSceneBehaviour::OnRender()
{
}

void ChangeSceneBehaviour::OnTriggerEnter2D(const Collider& collider)
{
}

void ChangeSceneBehaviour::OnTriggerExit2D(const Collider& collider)
{
}

void ChangeSceneBehaviour::OnTriggerStay2D(const Collider& collider)
{
}