#include "ChangeSceneBehaviour.hpp"
#include <API_Headers/AudioSource.hpp>
#include <chrono>
#include <thread>
using namespace std::this_thread;
using namespace std::chrono_literals;
ChangeSceneBehaviour::ChangeSceneBehaviour(const std::string& name, const std::string& scene) : _scene(scene){
	Name(name);
}

void ChangeSceneBehaviour::OnClick()
{
	if (EngineController::GetInstance()->GetIsInLevelTransition()) {
		if (EngineController::GetInstance()->GetCurrentLevel() != 1) {
			std::string levelString = "level" + std::to_string(EngineController::GetInstance()->GetCurrentLevel());
			_scene = levelString;

			std::string previousLevelString = "level" + std::to_string(EngineController::GetInstance()->GetCurrentLevel() - 1);

			std::shared_ptr<spic::GameObject> existingPlayerObject = EngineController::GetInstance()->GetSceneByName(previousLevelString)->GetGameObjectsByName("Player")[0];

			auto currentLevel = EngineController::GetInstance()->GetSceneByName(levelString);

			currentLevel->AddGameObject(existingPlayerObject);

			auto PlayerComponent = EngineController::GetInstance()->GetSceneByName(levelString)->GetGameObjectsByName("Player")[0]->GetComponent<Player>();
			PlayerComponent->FillBucket();
			PlayerComponent->OnStart();
		}
	}

	if (EngineController::GetInstance()->GetGameOver()) {
		std::shared_ptr<LevelSceneBuilder> levelSceneBuilder = std::make_shared<LevelSceneBuilder>();
		EngineController::GetInstance()->SetCurrentLevel(1);
		auto level1 = EngineController::GetInstance()->GetSceneByName("level1");
		level1->SetName("level1-done");
		levelSceneBuilder->BuildLevel(1);
		auto level2 = EngineController::GetInstance()->GetSceneByName("level2");
		level2->SetName("level2-done");
		levelSceneBuilder->BuildLevel(2);
		auto level3 = EngineController::GetInstance()->GetSceneByName("level3");
		level3->SetName("level3-done");
		levelSceneBuilder->BuildLevel(3);
		EngineController::GetInstance()->SetCurrentLevel(1);
		EngineController::GetInstance()->SetGameOver(false);
	}

	if (!EngineController::GetInstance()->GetSceneByName(_scene)->GetGameObjectsByTag("music").empty()) {
		if (!EngineController::GetInstance()->GetActiveScene()->GetGameObjectsByTag("music").empty()) {
			EngineController::GetInstance()->GetActiveScene()->GetGameObjectsByTag("music")[0]->GetComponent <spic::AudioSource>()->Stop();
		}		
	}

	EngineController::GetInstance()->SetIsInLevelTransition(false);
	EngineController::GetInstance()->SetActiveScene(_scene);

	if (!EngineController::GetInstance()->GetActiveScene()->GetGameObjectsByTag("music").empty()) {
		EngineController::GetInstance()->GetActiveScene()->GetGameObjectsByTag("music")[0]->GetComponent <spic::AudioSource>()->Play(true);

	}
	auto a = EngineController::GetInstance()->GetActiveScene()->GetGameObjectsByName("Input"); 
	if (a.size() == 1) {
		a[0]->GetComponent<InputScript>()->UnPauseGame();
	}
	sleep_for(100ms);

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

void ChangeSceneBehaviour::OnTriggerEnter2D(const spic::Collider& collider)
{
}

void ChangeSceneBehaviour::OnTriggerExit2D(const spic::Collider& collider)
{
}

void ChangeSceneBehaviour::OnTriggerStay2D(const spic::Collider& collider)
{
}

void ChangeSceneBehaviour::sceneChange(const std::string& newScene)
{
	_scene = newScene;
}
