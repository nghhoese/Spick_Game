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
		yPlayer -= speed;
	}
	else if (input->GetKey(A)) {
		xPlayer -= speed;
	}
	else if (input->GetKey(S)) {
		yPlayer += speed;
	}
	else if (input->GetKey(D)) {
		xPlayer += speed;
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

void Player::OnClick()
{
}

void Player::OnUpdate()
{
	spic::Transform transfrom = *GetGameObject()->getTransform();
	xPlayer = transfrom.position.x;
	yPlayer = transfrom.position.y;
	spic::Point point;
	checkKeys();
	transfrom.position.x = xPlayer;
	transfrom.position.y = yPlayer;

	GetGameObject()->getScene()->GetActiveCamera()->setX(xPlayer - 768);
	GetGameObject()->getScene()->GetActiveCamera()->setY(yPlayer - 768);
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
	if ((xPlayer > endPointPosition->position.x && yPlayer > endPointPosition->position.y)) {
		if (xPlayer < endBottomRight.x && yPlayer < endBottomRight.y) {
			std::shared_ptr<spic::Component> script = endPoint->GetComponentByName("EndLevelScript");
			if (script != nullptr) {
				script->OnClick();
			}
		}
	}

	GetGameObject()->setTransform(&transfrom);

	// Test
	//if (this->healthpoints > 70) {
	//	this->healthpoints -= 1;
	//}

	//// Test
	//if (this->coins < 20) {
	//	this->coins += 1;
	//}

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