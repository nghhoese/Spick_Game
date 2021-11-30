#include "InputScript.hpp"
#include "ChangeSceneBehaviour.hpp"

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
spic::KeyCode P = spic::KeyCode::P;
spic::KeyCode EP = spic::KeyCode::EQUAL_AND_PLUS;

spic::MouseButton LEFT1 = spic::MouseButton::LEFT;
spic::MouseButton MIDDLE1 = spic::MouseButton::MIDDLE;
spic::MouseButton RIGHT1 = spic::MouseButton::RIGHT;

InputScript::InputScript()
{
	this->input = new spic::Importation();
	this->time = new spic::Time();
}

const void InputScript::checkMouseButtons()
{
	//GetPlayer();
	if (input->GetMouseButton(LEFT1)) {
		// schieten
	}
	else if (input->GetMouseButton(RIGHT1)) {
		// reloaden
	}
	else {

	}
}

const void InputScript::checkKeys()
{
	const spic::GameObject* playerObject = GetPlayer();
	auto PlayerComponent = playerObject->GetComponent<Player>();

	//waardes nog aanpassen
	if (input->GetKey(W)) {
		if (PlayerComponent != nullptr) {
			PlayerComponent->yPlayer -= (PlayerComponent->speed * deltaTime);
		}
	}
	else if (input->GetKey(A)) {
		if (PlayerComponent != nullptr) {
			PlayerComponent->xPlayer -= (PlayerComponent->speed * deltaTime);
		}
	}
	else if (input->GetKey(S)) {
		if (PlayerComponent != nullptr) {
			PlayerComponent->yPlayer += (PlayerComponent->speed * deltaTime);
		}
	}
	else if (input->GetKey(D)) {
		if (PlayerComponent != nullptr) {
			PlayerComponent->xPlayer += (PlayerComponent->speed * deltaTime);
		}
	}
	else if (input->GetKey(E)) {
		// interactie
	}
	else if (input->GetKey(ESC)) {
		// pauze menu
	}
	else if (input->GetKey(H)) {
		// gameplay snelheid resetten
	}
	else if (input->GetKey(PU)) {
		// gameplay snelheid versnellen
	}
	else if (input->GetKey(PD)) {
		// gameplay snelheid vertragen
	}
	else if (input->GetKey(P)) {
		// pauze knop
	}
	else if (input->GetKey(EP)) {
		// opent een cheats menu
		std::shared_ptr<spic::Component> script = GetGameObject()->getScene()->GetGameObjectsByName("Player")[0]->GetComponentByName("CheatsMenuScript");

		if (script != nullptr) {
			script->OnClick();
		}
	}
	else if (input->GetKey(F)) {
		// toggle fps
	}
	else {

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
	deltaTime = (time->CalculateDeltaTime() / 10);
}

void InputScript::OnRender()
{
}

void InputScript::OnTriggerEnter2D(const Collider& collider)
{
}

void InputScript::OnClick()
{
}

void InputScript::OnTriggerExit2D(const Collider& collider)
{
}

void InputScript::OnTriggerStay2D(const Collider& collider)
{
}
