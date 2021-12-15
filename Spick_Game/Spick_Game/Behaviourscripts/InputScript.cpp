#include "InputScript.hpp"
#include "ChangeSceneBehaviour.hpp"
#include <API_Headers/Collision.hpp>

spic::KeyCode W = spic::KeyCode::W;
spic::KeyCode A = spic::KeyCode::A;
spic::KeyCode S = spic::KeyCode::S;
spic::KeyCode D = spic::KeyCode::D;
spic::KeyCode E = spic::KeyCode::E;
spic::KeyCode F = spic::KeyCode::F;
spic::KeyCode ESC = spic::KeyCode::ESCAPE;
spic::KeyCode H = spic::KeyCode::HOME;
spic::KeyCode PU = spic::KeyCode::PAGE_UP;
spic::KeyCode PD = spic::KeyCode::PAGE_DOWN;
spic::KeyCode EP = spic::KeyCode::EQUAL_AND_PLUS;
spic::KeyCode UA = spic::KeyCode::UP_ARROW;
spic::KeyCode DA = spic::KeyCode::DOWN_ARROW;
spic::KeyCode L = spic::KeyCode::L;
spic::KeyCode U = spic::KeyCode::U;
spic::KeyCode Y = spic::KeyCode::Y;
spic::KeyCode C = spic::KeyCode::C;
spic::KeyCode T = spic::KeyCode::T;
spic::KeyCode Q = spic::KeyCode::Q;
spic::KeyCode O = spic::KeyCode::O;

spic::MouseButton LEFT = spic::MouseButton::LEFT;
spic::MouseButton MIDDLE = spic::MouseButton::MIDDLE;
spic::MouseButton RIGHT = spic::MouseButton::RIGHT;

InputScript::InputScript() : input(std::make_unique<spic::Importation>()), time(std::make_unique<spic::Time>()), speedup(false), speeddown(false), pausing(false), clicked(true), paused(false), loadFps(false)
{
}

const void InputScript::checkMouseButtons()
{
	const spic::GameObject playerObject = *GetPlayer();
	auto PlayerComponent = playerObject.GetComponent<Player>();
	if (input->GetMouseButton(LEFT)) {
		if (PlayerComponent->GetNotClicked())
		{
			PlayerComponent->Shoot();
			PlayerComponent->SetNotClicked(false);
		}
	}
	else if (input->GetMouseButton(RIGHT)) {

	}
	else {
		PlayerComponent->SetNotClicked(true);
	}
}

const void InputScript::CheckPause() {
	if (input->GetKey(ESC)) {
		if (!GetPausing()) {
			SetPausing(true);
			if (time->TimeScale() > 0.0) {
				PauseGame();
			}
			else if (time->TimeScale() == 0) {
				UnPauseGame();
			}
		}
	}
	else {
		SetPausing(false);
	}
}

void InputScript::PauseGame() {
	time->TimeScale(0.0);
	SetPaused(true);
}

void InputScript::UnPauseGame() {
	time->TimeScale(1.0);
	SetPaused(false);
}

const void InputScript::checkKeys()
{
	const spic::GameObject playerObject = *GetPlayer();
	auto PlayerComponent = playerObject.GetComponent<Player>();
	auto objk1 = GetGameObject()->getScene()->GetGameObjectsByName("Player")[0];

	if (input->GetKey(W)) {
		if (PlayerComponent != nullptr) {
			if (PlayerComponent->GetHasCollision()) {
				if (Collision::AABB(objk1.get(), "wall")) {
					if (Collision::AABB(objk1.get(), "wall")->GetGameObject()->getTransform()->position.y < PlayerComponent->GetYPlayer()) {

					}
					else {
						PlayerComponent->SetYPlayer(PlayerComponent->GetYPlayer() - (PlayerComponent->GetSpeed()));
					}
				}
				else if (Collision::AABB(objk1.get(), "guard")) {
					PlayerComponent->SetYPlayer(PlayerComponent->GetYPlayer() + (PlayerComponent->GetSpeed()));
				}
				else {
					PlayerComponent->SetYPlayer(PlayerComponent->GetYPlayer() - (PlayerComponent->GetSpeed()));
				}
			}
			else {
				PlayerComponent->SetYPlayer(PlayerComponent->GetYPlayer() - (PlayerComponent->GetSpeed()));
			}
		}
	}
	if (input->GetKey(A)) {
		if (PlayerComponent != nullptr) {
			if (PlayerComponent->GetHasCollision()) {
				if (Collision::AABB(objk1.get(), "wall")) {
					if (Collision::AABB(objk1.get(), "wall")->GetGameObject()->getTransform()->position.x < PlayerComponent->GetXPlayer()) {
	
					}
					else {
						PlayerComponent->SetXPlayer(PlayerComponent->GetXPlayer() - (PlayerComponent->GetSpeed()));
					}
				}
				else if (Collision::AABB(objk1.get(), "guard")) {
					PlayerComponent->SetXPlayer(PlayerComponent->GetXPlayer() + (PlayerComponent->GetSpeed()));
				}
				else {
					PlayerComponent->SetXPlayer(PlayerComponent->GetXPlayer() - (PlayerComponent->GetSpeed()));
				}
			}
			else {
				PlayerComponent->SetXPlayer(PlayerComponent->GetXPlayer() - (PlayerComponent->GetSpeed()));
			}
		}
	}
	if (input->GetKey(S)) {
		if (PlayerComponent != nullptr) {
			if (PlayerComponent->GetHasCollision()) {
				if (Collision::AABB(objk1.get(), "wall")) {
					if (Collision::AABB(objk1.get(), "wall")->GetGameObject()->getTransform()->position.y > PlayerComponent->GetYPlayer()) {

					}
					else {
						PlayerComponent->SetYPlayer(PlayerComponent->GetYPlayer() + (PlayerComponent->GetSpeed()));
					}
				}
				else if (Collision::AABB(objk1.get(), "guard")) {
					PlayerComponent->SetYPlayer(PlayerComponent->GetYPlayer() - (PlayerComponent->GetSpeed()));
				}
				else {
					PlayerComponent->SetYPlayer(PlayerComponent->GetYPlayer() + (PlayerComponent->GetSpeed()));
				}
			}
			else {
				PlayerComponent->SetYPlayer(PlayerComponent->GetYPlayer() + (PlayerComponent->GetSpeed()));
			}
		}
	}
	if (input->GetKey(D)) {
		if (PlayerComponent != nullptr) {
			if (PlayerComponent->GetHasCollision()) {
				if (Collision::AABB(objk1.get(), "wall")) {
					if (Collision::AABB(objk1.get(), "wall")->GetGameObject()->getTransform()->position.x > PlayerComponent->GetXPlayer()) {

					}
					else {
						PlayerComponent->SetXPlayer(PlayerComponent->GetXPlayer() + (PlayerComponent->GetSpeed()));
					}
				}
				else if (Collision::AABB(objk1.get(), "guard")) {
					PlayerComponent->SetXPlayer(PlayerComponent->GetXPlayer() - (PlayerComponent->GetSpeed()));
				}
				else {
					PlayerComponent->SetXPlayer(PlayerComponent->GetXPlayer() + (PlayerComponent->GetSpeed()));
				}
			}
			else {
				PlayerComponent->SetXPlayer(PlayerComponent->GetXPlayer() + (PlayerComponent->GetSpeed()));
			}
		}
	}
	else if (input->GetKey(H)) {;
		time->TimeScale(1.0);
	}
	else if (input->GetKey(PU)) {
		if (!GetSpeedUp()) {
			SetSpeedUp(true);
			if (time->TimeScale() == 0.5) {
				time->TimeScale(1.0);
			}
			else if (time->TimeScale() == 1.0) {
				time->TimeScale(1.9);
			}
		}
	}
	else if (input->GetKey(PD)) {
		if (!GetSpeedDown()) {
			SetSpeedDown(true);
			if (time->TimeScale() == 1.9) {
				time->TimeScale(1.0);
			}
			else if (time->TimeScale() == 1.0) {
				time->TimeScale(0.5);
			}
		}
		
	}
	else if (input->GetKey(F)) {
		if (GetClicked()) {
			if (GetLoadFps()) {
				SetLoadFps(false);
			}
			else {
				SetLoadFps(true);
			}
			SetClicked(false);
		}
	}
	else if (input->GetKey(EP)) {
		std::shared_ptr<spic::Component> script = GetGameObject()->getScene()->GetGameObjectsByName("Player")[0]->GetComponentByName("CheatsMenuScript");

		if (script != nullptr) {
			std::string levelString = std::to_string(EngineController::GetInstance()->GetCurrentLevel());
			script->OnClick();
			auto backToGameButton = EngineController::GetInstance()->GetActiveScene()->GetGameObjectsByName("BackToGameButton")[0]->GetComponent<ChangeSceneBehaviour>();
			backToGameButton->sceneChange("level" + levelString);
		}
	}
	else if (input->GetKey(C)) {
		if (GetClicked()) {
			if (EngineController::GetInstance()->GetCheatsEnabled()) {
				EngineController::GetInstance()->SetCheatsEnabled(false);
				ResetCheats(playerObject);
			}
			else {
				EngineController::GetInstance()->SetCheatsEnabled(true);
			}
			SetClicked(false);
		}
	}
	else if (input->GetKey(Y)) {
		if (GetClicked()) {
			if (EngineController::GetInstance()->GetCheatsEnabled()) {
				PlayerComponent->SetHealthpoints(0);
				SetLoadFps(false);
				EngineController::GetInstance()->SetCheatsEnabled(false);
				EngineController::GetInstance()->SetGameOver(true);
				SetClicked(false);
			}
		}
	}
	else if (input->GetKey(UA)) {
		if (GetClicked()) {
			if (EngineController::GetInstance()->GetCheatsEnabled()) {
				PlayerComponent->SetSpeed(PlayerComponent->GetSpeed() + 1);
			}
			SetClicked(false);
		}
	}
	else if (input->GetKey(DA)) {
		if (GetClicked()) {
			if (EngineController::GetInstance()->GetCheatsEnabled()) {
				if (PlayerComponent->GetSpeed() > 0) {
					PlayerComponent->SetSpeed(PlayerComponent->GetSpeed() - 1);
				}
			}
			SetClicked(false);
		}
	}
	else if (input->GetKey(L)) {
		if (GetClicked()) {
			if (EngineController::GetInstance()->GetCheatsEnabled()) {
				if (PlayerComponent->GetIsDamageLess()) {
					PlayerComponent->SetIsDamageless(false);
				}
				else {
					PlayerComponent->SetIsDamageless(true);
				}
			}
			SetClicked(false);
		}
	}
	else if (input->GetKey(T)) {
		if (GetClicked()) {
			if (EngineController::GetInstance()->GetCheatsEnabled()) {
				auto endPointObject = EngineController::GetInstance()->GetActiveScene()->GetGameObjectsByName("Endpoint")[0];
				std::shared_ptr<spic::Component> script = endPointObject->GetComponentByName("EndLevelScript");
				if (script != nullptr) {
					EngineController::GetInstance()->SetIsInLevelTransition(true);
					EngineController::GetInstance()->SetCurrentLevel(EngineController::GetInstance()->GetCurrentLevel() + 1);
					script->OnClick();
				}
			}
			SetClicked(false);
		}
	}
	else if (input->GetKey(Q)) {
		if (GetClicked()) {
			if (EngineController::GetInstance()->GetCheatsEnabled()) {
				auto PlayerBoxColliderComponent = playerObject.GetComponent<BoxCollider>();
				if (PlayerComponent->GetHasCollision()) {
					PlayerComponent->SetHasCollision(false);
				}
				else {
					PlayerComponent->SetHasCollision(true);
				}
			}
			SetClicked(false);
		}
	}
	else if (input->GetKey(O)) {
		if (GetClicked()) {
			if (EngineController::GetInstance()->GetCheatsEnabled()) {
				SetObjectsHitBox(playerObject);
			}
			SetClicked(false);
		}
	}
	else {
		SetSpeedUp(false);
		SetSpeedDown(false);
		SetClicked(true);
	}

}

const spic::Point InputScript::checkMousePosition()
{
	spic::Point point = input->MousePosition();
	return point;
}

const spic::GameObject* InputScript::GetPlayer()
{
	auto PlayerObject = GetGameObject()->getScene()->GetGameObjectsByName("Player")[0];
	return PlayerObject.get();
}

void InputScript::OnAwake()
{
}

void InputScript::OnStart()
{
}

void InputScript::OnUpdate()
{
	SetDeltaTime(time->CalculateDeltaTime() / 10);
}

void InputScript::OnRender()
{
}

void InputScript::OnTriggerEnter2D(const spic::Collider& collider)
{
}

void InputScript::OnClick()
{
}

void InputScript::OnTriggerExit2D(const spic::Collider& collider)
{
}

void InputScript::OnTriggerStay2D(const spic::Collider& collider)
{
}

void InputScript::SetObjectsHitBox(spic::GameObject playerObject) {
	auto PlayerBoxColliderComponent = playerObject.GetComponent<BoxCollider>();
	auto guards = EngineController::GetInstance()->GetActiveScene()->GetGameObjectsByName("Guard");
	if (this->GetHitbox()) {
		PlayerBoxColliderComponent->ShowBoxBool(true);
		for (std::shared_ptr<spic::GameObject> g : guards) {

			g->GetComponent<BoxCollider>()->ShowBoxBool(true);
		}
		this->SetHitbox(false);
	}
	else {
		PlayerBoxColliderComponent->ShowBoxBool(false);
		for (std::shared_ptr<spic::GameObject> g : guards) {
			g->GetComponent<BoxCollider>()->ShowBoxBool(false);
		}
		this->SetHitbox(true);
	}
}

void InputScript::ResetCheats(spic::GameObject playerObject) {
	auto PlayerComponent = playerObject.GetComponent<Player>();
	PlayerComponent->SetSpeed(5);
	PlayerComponent->SetIsDamageless(false);
	PlayerComponent->SetHasCollision(true);
	this->SetHitbox(false);
	this->SetObjectsHitBox(playerObject);
}
