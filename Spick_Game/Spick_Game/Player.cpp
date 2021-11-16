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
		std::cout << "links" << std::endl;
	}
	else if (input->GetMouseButton(RIGHT)) {
		// reloaden
		std::cout << "rechts" << std::endl;
	}
	else {
		
	}
}

const void Player::checkKeys()
{
	//waardes nog aanpassen
	if (input->GetKey(W)) {
		y += 5;
		std::cout << "w" << std::endl;
	}
	else if (input->GetKey(A)) {
		x -= 5;
		std::cout << "a" << std::endl;
	}
	else if (input->GetKey(S)) {
		y -= 5;
		std::cout << "s" << std::endl;
	}
	else if (input->GetKey(D)) {
		x += 5;
		std::cout << "d" << std::endl;
	}
	else if (input->GetKey(E)) {
		// interactie
		std::cout << "e" << std::endl;
	}
	else if (input->GetKey(ESC)) {
		// pauze menu
		std::cout << "esc" << std::endl;
	}
	else if (input->GetKey(H)) {
		// gameplay snelheid resetten
		std::cout << "home" << std::endl;
	}
	else if (input->GetKey(PU)) {
		// gameplay snelheid versnellen
		std::cout << "page up" << std::endl;
	}
	else if (input->GetKey(PD)) {
		// gameplay snelheid vertragen
		std::cout << "page down" << std::endl;
	}
	else if (input->GetKey(P)) {
		// dpauze knop
		std::cout << "p" << std::endl;
	}
	else if (input->GetKey(EP)) {
		// opent een cheats menu
		std::cout << "=" << std::endl;
	}
	else {
		
	}
}

const spic::Point Player::checkMousePosition()
{
	spic::Point point = input->MousePosition();
	return point;
}
