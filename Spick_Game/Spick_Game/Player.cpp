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
		y -= 0.5;
	}
	else if (input->GetKey(A)) {
		x -= 0.5;
	}
	else if (input->GetKey(S)) {
		y += 0.5;
	}
	else if (input->GetKey(D)) {
		x += 0.5;
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
