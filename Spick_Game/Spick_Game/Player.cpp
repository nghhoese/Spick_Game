#include "Player.hpp"
#include <API_Headers/Sprite.hpp>
#include <API_Headers/Text.hpp>


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

	GetGameObject()->getScene()->GetActiveCamera()->setX(x - 768);
	GetGameObject()->getScene()->GetActiveCamera()->setY(y - 768);
	GetGameObject()->getScene()->GetActiveCamera()->UpdateCamera();

	int x, y, w, h;
	x = GetGameObject()->getScene()->GetActiveCamera()->getX();
	y = GetGameObject()->getScene()->GetActiveCamera()->getY();
	w = GetGameObject()->getScene()->GetActiveCamera()->getAspectWidth();
	h = GetGameObject()->getScene()->GetActiveCamera()->getAspectHeight();

	if (x < 0) {
		GetGameObject()->getScene()->GetActiveCamera()->setX(0);
	}
	if (y < 0) {
		GetGameObject()->getScene()->GetActiveCamera()->setY(0);
	}
	if (x > w) {
		GetGameObject()->getScene()->GetActiveCamera()->setX(w);
	}
	if (y > h) {
		GetGameObject()->getScene()->GetActiveCamera()->setY(h);
	}

	point = checkMousePosition();
	double Delta_x = (transfrom.position.x - GetGameObject()->getScene()->GetActiveCamera()->getX()) - point.x;
	double Delta_y = (transfrom.position.y - GetGameObject()->getScene()->GetActiveCamera()->getY()) - point.y;

	double Result = (atan2(Delta_y, Delta_x) * 180.0000) / 3.14159265;
	transfrom.rotation = Result + 95;

	auto endPoint = GetGameObject()->getScene()->GetGameObjectsByName("Endpoint")[0];
	auto endPointPosition = endPoint->getTransform();
	spic::Point endBottomRight;
	endBottomRight.x = endPointPosition->position.x + 64;
	endBottomRight.y = endPointPosition->position.y + 64;
	if ((x > endPointPosition->position.x && y > endPointPosition->position.y) ) {
		if (x < endBottomRight.x && y < endBottomRight.y) {
			std::cout << "Level behaald" << std::endl;
		}
	}

	GetGameObject()->setTransform(&transfrom);

	//std::shared_ptr<spic::Text> object = GetGameObject()->FindWithTag("hp");

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
