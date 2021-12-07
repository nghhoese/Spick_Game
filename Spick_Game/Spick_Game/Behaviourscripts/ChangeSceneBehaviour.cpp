#include "ChangeSceneBehaviour.hpp"

ChangeSceneBehaviour::ChangeSceneBehaviour(std::string name, std::string scene) : _scene(scene){
	Name(name);
}

void ChangeSceneBehaviour::OnClick()
{
	if (EngineController::GetInstance()->GetGameOver()) {
		// Reset levels
		std::shared_ptr<LevelSceneBuilder> levelSceneBuilder = std::make_shared<LevelSceneBuilder>();

		levelSceneBuilder->BuildLevel(1);
		levelSceneBuilder->BuildLevel(2);
		levelSceneBuilder->BuildLevel(3);

		EngineController::GetInstance()->SetGameOver(false);
	}

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