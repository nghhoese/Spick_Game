#include "InputScript.hpp"
#include "ChangeSceneBehaviour.hpp"
#include "../Collision.hpp"

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
spic::KeyCode UA = spic::KeyCode::UP_ARROW;
spic::KeyCode DA = spic::KeyCode::DOWN_ARROW;
spic::KeyCode L = spic::KeyCode::L;
spic::KeyCode U = spic::KeyCode::U;
spic::KeyCode Y = spic::KeyCode::Y;

spic::MouseButton LEFT = spic::MouseButton::LEFT;
spic::MouseButton MIDDLE = spic::MouseButton::MIDDLE;
spic::MouseButton RIGHT = spic::MouseButton::RIGHT;

InputScript::InputScript()
{
	this->input = new spic::Importation();
	this->time = new spic::Time();
	this->engine = new spic::Engine();
}

const void InputScript::checkMouseButtons()
{
	const spic::GameObject* playerObject = GetPlayer();
	auto PlayerComponent = playerObject->GetComponent<Player>();
	if (input->GetMouseButton(LEFT)) {
		// schieten
		if (PlayerComponent->notClicked)
		{
			PlayerComponent->Shoot();
			PlayerComponent->notClicked = false;
		}
	}
	else if (input->GetMouseButton(RIGHT)) {
		// reloaden
	}
	else {
		PlayerComponent->notClicked = true;
	}
}

const void InputScript::CheckPause() {
	if (input->GetKey(ESC)) {
	// pauze menu
		if (!pausing) {
			pausing = true;
			if (time->TimeScale() > 0.0) {
				time->TimeScale(0.0);
				std::cout << "paused";
				paused = true;
			}
			else if (time->TimeScale() == 0) {
				time->TimeScale(1.0);
				std::cout << "play";
				paused = false;
			}
		}
	}
	else {
		pausing = false;
	}
}

const void InputScript::checkKeys()
{
	const spic::GameObject* playerObject = GetPlayer();
	auto PlayerComponent = playerObject->GetComponent<Player>();
	auto objk1 = GetGameObject()->getScene()->GetGameObjectsByName("Player")[0];

	//waardes nog aanpassen
	if (input->GetKey(W)) {
		if (PlayerComponent != nullptr) {

			if (Collision::AABB(objk1.get(), "wall")) {
				if (Collision::AABB(objk1.get(), "wall")->GetGameObject()->getTransform()->position.y < PlayerComponent->yPlayer) {
					PlayerComponent->yPlayer += (PlayerComponent->speed);
				}
				else {
					PlayerComponent->yPlayer -= (PlayerComponent->speed);
				}
			}
			else {
				PlayerComponent->yPlayer -= (PlayerComponent->speed);
			}

		}
	}
	else if (input->GetKey(A)) {
		if (PlayerComponent != nullptr) {
			if (Collision::AABB(objk1.get(), "wall")) {
				if (Collision::AABB(objk1.get(), "wall")->GetGameObject()->getTransform()->position.x < PlayerComponent->xPlayer) {
					PlayerComponent->xPlayer += (PlayerComponent->speed);
				}
				else {
					PlayerComponent->xPlayer -= (PlayerComponent->speed);

				}
			}
			else {
				PlayerComponent->xPlayer -= (PlayerComponent->speed);

			}
		}
	}
	else if (input->GetKey(S)) {
		if (PlayerComponent != nullptr) {
			if (Collision::AABB(objk1.get(), "wall")) {
				if (Collision::AABB(objk1.get(), "wall")->GetGameObject()->getTransform()->position.y > PlayerComponent->yPlayer) {
					PlayerComponent->yPlayer -= (PlayerComponent->speed);
				}
				else {
					PlayerComponent->yPlayer += (PlayerComponent->speed);

				}
			}
			else {
				PlayerComponent->yPlayer += (PlayerComponent->speed);

			}
		}
	}
	else if (input->GetKey(D)) {
		if (PlayerComponent != nullptr) {
			if (Collision::AABB(objk1.get(), "wall")) {
				if (Collision::AABB(objk1.get(), "wall")->GetGameObject()->getTransform()->position.x > PlayerComponent->xPlayer) {
					PlayerComponent->xPlayer -= (PlayerComponent->speed);
				}
				else {
					PlayerComponent->xPlayer += (PlayerComponent->speed);

				}
			}
			else {
				PlayerComponent->xPlayer += (PlayerComponent->speed);

			}
		}
	}
	else if (input->GetKey(E)) {
		// interactie
	}
	/*else if (input->GetKey(ESC)) {
		// pauze menu
		if (!pausing) {
			pausing = true;
			if (time->TimeScale() > 0.0) {
				time->TimeScale(0.0);
				std::cout << "paused";
			}
			else if (time->TimeScale() == 0) {
				time->TimeScale(1.0);
				std::cout << "play";
			}
		}

	}*/
	else if (input->GetKey(H)) {
		// gameplay snelheid resetten
	}
	else if (input->GetKey(PU)) {
		// gameplay snelheid versnellen
		if (!speedup) {
			std::cout << "speedup: ";
			speedup = true;
			if (time->TimeScale() == 0.5) {
				time->TimeScale(1.0);
				std::cout << time->TimeScale();
			}
			else if (time->TimeScale() == 1.0) {
				time->TimeScale(1.9);
				std::cout << time->TimeScale();
			}
		}
		

	}
	else if (input->GetKey(PD)) {
		
		if (!speeddown) {
			std::cout << "slowdown: ";
			speeddown = true;
			if (time->TimeScale() == 1.9) {
				time->TimeScale(1.0);
				std::cout << time->TimeScale();
			}
			else if (time->TimeScale() == 1.0) {
				time->TimeScale(0.5);
				std::cout << time->TimeScale();
			}
		}
		
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
	else if (input->GetKey(Y)) {
		// instakill the player
		PlayerComponent->currentHealthPoints = 0;
		engine->setGameOver(true);
	}
	else if (input->GetKey(UA)) {
		// movement speed up
		PlayerComponent->speed += 1;
	}
	else if (input->GetKey(DA)) {
		// movement speed down
		if (PlayerComponent->speed > 0) {
			PlayerComponent->speed -= 1;
		}
	}
	else if (input->GetKey(L)) {
		// enable/disable damageless
		if (clicked) {
			if (PlayerComponent->isDamageless) {
				PlayerComponent->isDamageless = false;
			}
			else {
				PlayerComponent->isDamageless = true;
			}
			clicked = false;
		}
	}

	//else if (input->GetKey(U)) {
	//	// make player undedectable
	//}

	else if (input->GetKey(F)) {
		if (clicked) {
			if (loadFps) {
				loadFps = false;
			}
			else {
				loadFps = true;
			}
			clicked = false;
		}
	}
	else {
		speedup = false;
		speeddown = false;
		clicked = true;
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
