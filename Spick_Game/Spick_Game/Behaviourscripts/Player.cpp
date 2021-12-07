#include "Player.hpp"
#include <API_Headers/BoxCollider.hpp>

Player::Player()
{
	this->healthpoints = 100;
	this->coins = 0;
	this->ammo = 0;
	this->bulletSpeed = 10;
	this->bulletDamage = 30;
	this->speed = 5;
	this->notClicked = true;
	this->isDamageless = false;
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

	InputObject = GetGameObject()->getScene()->GetGameObjectsByName("Input")[0];
	auto InputComponent = InputObject->GetComponent<InputScript>();

	InputComponent->checkKeys();
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

	point = InputComponent->checkMousePosition();
	double Delta_x = (transfrom.position.x - GetGameObject()->getScene()->GetActiveCamera()->getX()) - point.x;
	double Delta_y = (transfrom.position.y - GetGameObject()->getScene()->GetActiveCamera()->getY()) - point.y;

	double Result = (atan2(Delta_y, Delta_x) * 180.0000) / 3.14159265;
	transfrom.rotation = Result + 90;

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
	InputComponent->checkMouseButtons();

	if (healthpoints == 0) {
		std::cout << currentHealthPoints;
		std::shared_ptr<spic::Component> script = GetGameObject()->GetComponentByName("GameOverScript");
		if (script != nullptr) {
			EngineController::GetInstance()->SetGameOver(true);
			script->OnClick();
		}
	}

	// nog weghalen is om te testen
	if (isDamageless) {
		if (this->healthpoints > 0) {
			this->healthpoints -= 1;
		}
	}

	std::shared_ptr<spic::GameObject> HudObject = GetGameObject()->getScene()->GetGameObjectsByTag("hud")[0];
	auto HudComponent = HudObject->GetComponent<HUD>();
	HudComponent->SetHealthPoints(this->healthpoints);
	HudComponent->SetCoins(this->coins);	
}

void Player::OnRender()
{
	InputObject = GetGameObject()->getScene()->GetGameObjectsByName("Input")[0];
	auto InputComponent = InputObject->GetComponent<InputScript>();
	InputComponent->CheckPause();
	// Update paused in HUD
	std::shared_ptr<spic::GameObject> pausedObject = GetGameObject()->getScene()->GetGameObjectsByTag("paused")[0];
	std::shared_ptr<spic::Text> pausedText = std::dynamic_pointer_cast<spic::Text>(pausedObject);
	if (InputComponent->GetPaused()) {
		pausedText->SetText("PAUSED");
	}
	if (!InputComponent->GetPaused()) {
		pausedText->SetText("");
	}
}

void Player::OnTriggerEnter2D(const Collider& collider)
{
}

void Player::OnTriggerExit2D(const Collider& collider)
{
}

void Player::OnTriggerStay2D(const Collider& collider)
{
}

void Player::Shoot()
{
	auto InputComponent = InputObject->GetComponent<InputScript>();
	std::shared_ptr<spic::GameObject> bulletObject = std::make_shared<spic::GameObject>("Bullet");
	GetGameObject()->getScene()->AddGameObject(bulletObject);
	spic::Transform transfrom = *bulletObject->getTransform();

	sprite = std::make_shared<spic::Sprite>();
	bulletObject->AddComponent(sprite);
	sprite->SetSprite("assets/bullet.bmp");
	sprite->SetPlayerBool(true);
	bulletObject->AddTag("PlayerBullet");
	transfrom.position.x = GetGameObject()->getTransform()->position.x + 20;
	transfrom.position.y = GetGameObject()->getTransform()->position.y + 32;
	transfrom.scale = 0.75;

	std::shared_ptr<spic::BoxCollider> boxCollider = std::make_shared<spic::BoxCollider>();
	boxCollider->Height(10);
	boxCollider->Width(10);
	bulletObject->AddComponent(boxCollider);
	std::shared_ptr<Bullet> bullet = std::make_shared<Bullet>(transfrom.position, InputComponent->checkMousePosition(), 20, bulletDamage);
	bulletObject->AddComponent(bullet);
	bulletObject->setTransform(&transfrom);
	bullet->CalculateAmountToMove();
}