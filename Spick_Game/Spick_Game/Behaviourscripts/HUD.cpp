#include "HUD.hpp"

HUD::HUD()
{
	this->fps = 0;
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

	// Update Healthpoints in HUD
	std::shared_ptr<spic::GameObject> healthObject = GetGameObject()->getScene()->GetGameObjectsByTag("hp")[0];
	std::shared_ptr<spic::Text> healthText = std::dynamic_pointer_cast<spic::Text>(healthObject);
	if (currentHealthPoints != healthpoints) {
		healthText->SetText("Health: " + std::to_string(this->healthpoints));
	}
	currentHealthPoints = this->healthpoints;

	// Update Coins in HUD
	std::shared_ptr<spic::GameObject> coinsObject = GetGameObject()->getScene()->GetGameObjectsByTag("coins")[0];
	std::shared_ptr<spic::Text> CoinsText = std::dynamic_pointer_cast<spic::Text>(coinsObject);
	if (currentCoins != coins) {
		CoinsText->SetText("Coins: " + std::to_string(this->coins));
	}
	currentCoins = this->coins;

	// Update fps in HUD
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

void HUD::OnTriggerEnter2D(const Collider& collider)
{
}

void HUD::OnTriggerExit2D(const Collider& collider)
{
}

void HUD::OnTriggerStay2D(const Collider& collider)
{
}