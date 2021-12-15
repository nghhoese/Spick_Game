#include "ReturnToMainMenuBehaviour.hpp"
#include <API_Headers/AudioSource.hpp>
#include <chrono>
#include <thread>
using namespace std::this_thread;
using namespace std::chrono_literals;
ReturnToMainMenuBehaviour::ReturnToMainMenuBehaviour(const std::string& name) {
	Name(name);
	_scene = "MainMenu";
}

void ReturnToMainMenuBehaviour::OnClick()
{
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

void ReturnToMainMenuBehaviour::OnUpdate() {
}

void ReturnToMainMenuBehaviour::OnAwake()
{
}

void ReturnToMainMenuBehaviour::OnStart()
{
}

void ReturnToMainMenuBehaviour::OnRender()
{
}

void ReturnToMainMenuBehaviour::OnTriggerEnter2D(const spic::Collider& collider)
{
}

void ReturnToMainMenuBehaviour::OnTriggerExit2D(const spic::Collider& collider)
{
}

void ReturnToMainMenuBehaviour::OnTriggerStay2D(const spic::Collider& collider)
{
}

void ReturnToMainMenuBehaviour::sceneChange(const std::string& newScene)
{
	_scene = newScene;
}
