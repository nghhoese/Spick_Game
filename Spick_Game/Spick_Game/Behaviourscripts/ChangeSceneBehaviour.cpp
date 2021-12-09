#include "ChangeSceneBehaviour.hpp"
#include <API_Headers/AudioSource.hpp>

ChangeSceneBehaviour::ChangeSceneBehaviour(const std::string& name, const std::string& scene) : _scene(scene){
	Name(name);
}

void ChangeSceneBehaviour::OnClick()
{
	if (EngineController::GetInstance()->GetGameOver()) {
		std::shared_ptr<LevelSceneBuilder> levelSceneBuilder = std::make_shared<LevelSceneBuilder>();
		levelSceneBuilder->BuildLevel(1);
		levelSceneBuilder->BuildLevel(2);
		levelSceneBuilder->BuildLevel(3);
		EngineController::GetInstance()->SetGameOver(false);
	}
	if (!EngineController::GetInstance()->GetSceneByName(_scene)->GetGameObjectsByTag("music").empty()) {
		if (!EngineController::GetInstance()->GetActiveScene()->GetGameObjectsByTag("music").empty()) {
			EngineController::GetInstance()->GetActiveScene()->GetGameObjectsByTag("music")[0]->GetComponent <spic::AudioSource>()->Stop();
		}		
	}
	EngineController::GetInstance()->SetActiveScene(_scene);
	if (!EngineController::GetInstance()->GetActiveScene()->GetGameObjectsByTag("music").empty()) {
		EngineController::GetInstance()->GetActiveScene()->GetGameObjectsByTag("music")[0]->GetComponent <spic::AudioSource>()->Play(true);

	}


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