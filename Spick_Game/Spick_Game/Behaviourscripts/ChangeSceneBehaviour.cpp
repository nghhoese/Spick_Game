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
			_scene = "level" + std::to_string(EngineController::GetInstance()->GetCurrentLevel());
			std::string previousLevelString = "level" + std::to_string(EngineController::GetInstance()->GetCurrentLevel() - 1);
			std::shared_ptr<spic::GameObject> existingPlayerObject = EngineController::GetInstance()->GetSceneByName(previousLevelString)->GetGameObjectsByName("Player")[0];
			auto currentLevel = EngineController::GetInstance()->GetSceneByName(_scene);
			currentLevel->AddGameObject(existingPlayerObject);
			auto PlayerComponent = currentLevel->GetGameObjectsByName("Player")[0]->GetComponent<Player>();
			PlayerComponent->FillBucket();
			PlayerComponent->OnStart();
		}
	}

	if (EngineController::GetInstance()->GetGameOver() || alwaysReset) {
		EngineController::GetInstance()->ResetLevels();
		EngineController::GetInstance()->SetGameOver(false);
	}

	if (_scene == "MainMenu" || _scene == "level1") {
		if (!EngineController::GetInstance()->GetSceneByName(_scene)->GetGameObjectsByTag("music").empty()) {
			if (!EngineController::GetInstance()->GetActiveScene()->GetGameObjectsByTag("music").empty()) {
				if (!EngineController::GetInstance()->GetSceneByName(_scene)->GetGameObjectsByTag("music")[0]->GetComponent <spic::AudioSource>()->GetPlaying()) {
					EngineController::GetInstance()->GetActiveScene()->GetGameObjectsByTag("music")[0]->GetComponent <spic::AudioSource>()->Stop();

				}
			}
		}
		else {
			if (_scene == "MainMenu") {
				MusicController::GetInstance()->SetMainMenuMusic(EngineController::GetInstance()->GetSceneByName("MainMenu"));

			}
			else {
				MusicController::GetInstance()->SetLevelMusic();

			}
			if (!EngineController::GetInstance()->GetSceneByName(_scene)->GetGameObjectsByTag("music")[0]->GetComponent <spic::AudioSource>()->GetPlaying()) {
				EngineController::GetInstance()->GetActiveScene()->GetGameObjectsByTag("music")[0]->GetComponent <spic::AudioSource>()->Stop();
			}
		}
	}

	EngineController::GetInstance()->SetIsInLevelTransition(false);
	EngineController::GetInstance()->SetActiveScene(_scene);

	if (_scene == "MainMenu" || _scene == "level1") {
		if (!EngineController::GetInstance()->GetSceneByName(_scene)->GetGameObjectsByTag("music").empty()) {
			if (!EngineController::GetInstance()->GetSceneByName(_scene)->GetGameObjectsByTag("music")[0]->GetComponent <spic::AudioSource>()->GetPlaying()) {
				EngineController::GetInstance()->GetActiveScene()->GetGameObjectsByTag("music")[0]->GetComponent <spic::AudioSource>()->Play(true);
			}
		}
		else {
			if (!EngineController::GetInstance()->GetSceneByName(_scene)->GetGameObjectsByTag("music")[0]->GetComponent <spic::AudioSource>()->GetPlaying()) {
				if (_scene == "MainMenu") {
					MusicController::GetInstance()->SetMainMenuMusic(EngineController::GetInstance()->GetSceneByName("MainMenu"));
				}
				else {
					MusicController::GetInstance()->SetLevelMusic();

				}
			}
		}
	}

	auto a = EngineController::GetInstance()->GetActiveScene()->GetGameObjectsByName("Input"); 
	if (a.size() == 1) {
		a[0]->GetComponent<InputScript>()->UnPauseGame();
	}
	sleep_for(600ms);

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
