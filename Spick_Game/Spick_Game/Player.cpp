#include "Player.hpp"


spic::KeyCode W = spic::KeyCode::W;
spic::KeyCode A = spic::KeyCode::A;
spic::KeyCode S = spic::KeyCode::S;
spic::KeyCode D = spic::KeyCode::D;
spic::KeyCode E = spic::KeyCode::E;
spic::KeyCode ESC = spic::KeyCode::ESCAPE;
spic::KeyCode H = spic::KeyCode::HOME;
spic::KeyCode PU = spic::KeyCode::PAGE_UP;
spic::KeyCode PD = spic::KeyCode::PAGE_DOWN;
spic::KeyCode P = spic::KeyCode::P;
spic::KeyCode EP = spic::KeyCode::EQUAL_AND_PLUS;

spic::MouseButton LEFT = spic::MouseButton::LEFT;
spic::MouseButton MIDDLE = spic::MouseButton::MIDDLE;
spic::MouseButton RIGHT = spic::MouseButton::RIGHT;

spic::Importation* input = new spic::Importation();

const void Player::checkMouseButtons()
{
	if (input->GetMouseButton(LEFT)) {
		// schieten
	}
	else if (input->GetMouseButton(RIGHT)) {
		// reloaden
	}
	else {
		
	}
}

const void Player::checkKeys()
{
	//waardes nog aanpassen
	if (input->GetKey(W)) {
		y -= 1;
	}
	else if (input->GetKey(A)) {
		x -= 1;
	}
	else if (input->GetKey(S)) {
		y += 1;
	}
	else if (input->GetKey(D)) {
		x += 1;
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
		// dpauze knop
	}
	else if (input->GetKey(EP)) {
		// opent een cheats menu
	}
	else {
		
	}
}

	
const spic::Point Player::checkMousePosition()
{
	spic::Point point = input->MousePosition();
	return point;
}

void Player::OnAwake()
{
}

void Player::OnStart()
{
}

void Player::OnUpdate()
{
	spic::Transform transfrom = *GetGameObject()->getTransform();
	x = transfrom.position.x;
	y = transfrom.position.y;
	spic::Point point;
	checkKeys();
	transfrom.position.x = x;
	transfrom.position.y = y;

	point = checkMousePosition();
	double Delta_x = transfrom.position.x - point.x;
	double Delta_y = transfrom.position.y - point.y;

	double Result = (atan2(Delta_y, Delta_x) * 180.0000) / 3.14159265;
	transfrom.rotation = Result + 95;

	GetGameObject()->setTransform(&transfrom);
}

void Player::OnRender()
{
}

void Player::OnTriggerEnter2D(const Collider& collider)
{
}

Player::Player()
{
}

void Player::OnTriggerExit2D(const Collider& collider)
{
}

void Player::OnTriggerStay2D(const Collider& collider)
{
}
