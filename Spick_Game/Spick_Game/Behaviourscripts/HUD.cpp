#include "HUD.hpp"
#include <API_Headers/AudioSource.hpp>

HUD::HUD() : fps(0)
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

	std::shared_ptr<spic::GameObject> healthObject = GetGameObject()->getScene()->GetGameObjectsByTag("hp")[0];
	std::shared_ptr<spic::Text> healthText = std::dynamic_pointer_cast<spic::Text>(healthObject);
	if (currentHealthPoints != healthpoints) {
		healthText->SetText("Health: " + std::to_string(this->healthpoints));
	}
	currentHealthPoints = this->healthpoints;

	std::shared_ptr<spic::GameObject> magazineObject = GetGameObject()->getScene()->GetGameObjectsByTag("Magazine")[0];
	std::shared_ptr<spic::Text> magazineText = std::dynamic_pointer_cast<spic::Text>(magazineObject);
	if (magazine == 0) {
		GetGameObject()->getScene()->GetGameObjectsByName("Player")[0]->GetComponent<spic::AudioSource>()->Play(true);
		magazineText->SetText("Magazine: reloading...");
	}
	else {
		magazineText->SetText("Magazine: " + std::to_string(this->magazine) + "/" + std::to_string(this->currentMagazine));
	}
	
	std::shared_ptr<spic::GameObject> fpsObject = GetGameObject()->getScene()->GetGameObjectsByTag("fps")[0];
	std::shared_ptr<spic::Text> fpsText = std::dynamic_pointer_cast<spic::Text>(fpsObject);
	if (InputComponent->GetLoadFps()) {
		fpsText->SetText("FPS: " + std::to_string(EngineController::GetInstance()->GetFPS()));
	}
	if (!InputComponent->GetLoadFps()) {
		fpsText->SetText("");
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