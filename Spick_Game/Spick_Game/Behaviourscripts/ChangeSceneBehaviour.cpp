#include "ChangeSceneBehaviour.hpp"

ChangeSceneBehaviour::ChangeSceneBehaviour(const std::string& name, const std::string& scene) : _scene(scene){
	Name(name);
}

void ChangeSceneBehaviour::OnClick()
{
	std::shared_ptr<LevelSceneBuilder> levelSceneBuilder = std::make_shared<LevelSceneBuilder>();

	if (EngineController::GetInstance()->GetCurrentLevel() == 2) {		
		std::shared_ptr<spic::GameObject> existingPlayerObject = EngineController::GetInstance()->GetSceneByName("level1")->GetGameObjectsByName("Player")[0];
		auto level2 = EngineController::GetInstance()->GetSceneByName("level2");

		//EngineController::GetInstance()->GetSceneByName("level1")->SwitchGameObjectToScene(existingPlayerObject);

		//auto p2 = std::make_shared<spic::GameObject>(*existingPlayerObject);
		level2->AddGameObject(existingPlayerObject);
		//auto PlayerComponent = p2->GetComponent<Player>();
		//PlayerComponent->OnStart();
		//levelSceneBuilder->BuildLevel(EngineController::GetInstance()->GetCurrentLevel());
	}

	if (EngineController::GetInstance()->GetGameOver()) {
		//std::shared_ptr<LevelSceneBuilder> levelSceneBuilder = std::make_shared<LevelSceneBuilder>();
		levelSceneBuilder->BuildLevel(1);
		levelSceneBuilder->BuildLevel(2);
		levelSceneBuilder->BuildLevel(3);
		EngineController::GetInstance()->SetCurrentLevel(1);
		EngineController::GetInstance()->SetGameOver(false);
	}

	auto test = _scene;
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