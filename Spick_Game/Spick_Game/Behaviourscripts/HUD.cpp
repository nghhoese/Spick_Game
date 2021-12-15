#include "HUD.hpp"
#include <API_Headers/AudioSource.hpp>

HUD::HUD() : fps(0), accumelatedDeltaTime(0), sec(1000)
{
}

void HUD::OnAwake()
{
}

void HUD::OnStart()
{
}

void HUD::OnUpdate()
{
	InputObject = GetGameObject()->getScene()->GetGameObjectsByName("Input")[0];
	auto InputComponent = InputObject->GetComponent<InputScript>();

	std::shared_ptr<spic::GameObject> healthObject = GetGameObject()->getScene()->GetGameObjectsByName("hp")[0];
	std::shared_ptr<spic::Text> healthText = std::dynamic_pointer_cast<spic::Text>(healthObject);
	if (currentHealthPoints != healthpoints) {
		healthText->SetText("Health: " + std::to_string(this->healthpoints));
	}
	currentHealthPoints = this->healthpoints;

	std::shared_ptr<spic::GameObject> magazineObject = GetGameObject()->getScene()->GetGameObjectsByName("Magazine")[0];
	std::shared_ptr<spic::Text> magazineText = std::dynamic_pointer_cast<spic::Text>(magazineObject);
	if (magazine == 0) {
		GetGameObject()->getScene()->GetGameObjectsByName("Player")[0]->GetComponent<spic::AudioSource>()->Play(true);
		magazineText->SetText("Magazine: reloading...");
	}
	else {
		magazineText->SetText("Magazine: " + std::to_string(this->magazine) + "/" + std::to_string(this->currentMagazine));
	}
	
	std::shared_ptr<spic::GameObject> fpsObject = GetGameObject()->getScene()->GetGameObjectsByName("fps")[0];
	std::shared_ptr<spic::Text> fpsText = std::dynamic_pointer_cast<spic::Text>(fpsObject);
	if (InputComponent->GetLoadFps()) {
		accumelatedDeltaTime += EngineController::GetInstance()->GetTime();
		if (accumelatedDeltaTime >= (sec * 4)) {
			accumelatedDeltaTime = sec;
		}
		if (accumelatedDeltaTime >= sec) {
			fpsText->SetText("FPS: " + std::to_string(EngineController::GetInstance()->GetFPS()));
			accumelatedDeltaTime -= sec;
		}
	}
	if (!InputComponent->GetLoadFps()) {
		fpsText->SetText("");
	}

	std::shared_ptr<spic::GameObject> cheatsObject = GetGameObject()->getScene()->GetGameObjectsByName("cheats")[0];
	std::shared_ptr<spic::Text> cheatsText = std::dynamic_pointer_cast<spic::Text>(cheatsObject);
	if (EngineController::GetInstance()->GetCheatsEnabled()) {
		if (cheatsText->GetText() != "Cheats Enabled") {
			cheatsText->SetText("Cheats Enabled");
		}
	}
	if (!EngineController::GetInstance()->GetCheatsEnabled()) {
		if (cheatsText->GetText() != "") {
			cheatsText->SetText("");
		}
	}
}

void HUD::OnRender()
{
}

void HUD::OnClick()
{
}

void HUD::OnTriggerEnter2D(const spic::Collider& collider)
{
}

void HUD::OnTriggerExit2D(const spic::Collider& collider)
{
}

void HUD::OnTriggerStay2D(const spic::Collider& collider)
{
}