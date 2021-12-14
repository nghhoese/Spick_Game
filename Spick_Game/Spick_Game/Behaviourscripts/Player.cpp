#include "Player.hpp"
#include <API_Headers/BoxCollider.hpp>

Player::Player() : healthpoints(100), coins(0), ammo(0), bulletSpeed(10), bulletDamage(30), speed(5), notClicked(true), isDamageless(false), magazine(50), currentMagazine(magazine), coolDown(50)
{
}

void Player::OnAwake()
{
}

void Player::OnStart()
{
	if (GetGameObject()->getScene()->GetGameObjectsByName("Endpoint")[0] != nullptr) {
		endPointObject = GetGameObject()->getScene()->GetGameObjectsByName("Endpoint")[0];
		auto endPointPosition = endPointObject->getTransform();
		endPointTopLeft.x = endPointPosition->position.x;
		endPointTopLeft.y = endPointPosition->position.y;
		endPointBottomRight.x = endPointPosition->position.x + 64;
		endPointBottomRight.y = endPointPosition->position.y + 64;
	}
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
	GetGameObject()->getScene()->GetActiveCamera()->setX(xPlayer - (GetGameObject()->getScene()->GetActiveCamera()->getAspectWidth() / 2));
	GetGameObject()->getScene()->GetActiveCamera()->setY(yPlayer - (GetGameObject()->getScene()->GetActiveCamera()->getAspectHeight() / 2));
	GetGameObject()->getScene()->GetActiveCamera()->UpdateCamera();
	this->CameraFixture();

	point = InputComponent->checkMousePosition();
	double Delta_x = (transfrom.position.x - GetGameObject()->getScene()->GetActiveCamera()->getX()) - point.x;
	double Delta_y = (transfrom.position.y - GetGameObject()->getScene()->GetActiveCamera()->getY()) - point.y;
	double Result = (atan2(Delta_y, Delta_x) * 180.0000) / 3.14159265;
	transfrom.rotation = Result + 90;

	if (endPointObject != nullptr) {
		CheckEndPoint();
	}

	GetGameObject()->setTransform(&transfrom);
	InputComponent->checkMouseButtons();

	this->CheckGameOver();

	std::shared_ptr<spic::GameObject> HudObject = GetGameObject()->getScene()->GetGameObjectsByTag("hud")[0];
	auto HudComponent = HudObject->GetComponent<HUD>();
	HudComponent->SetHealthPoints(this->healthpoints);
	HudComponent->SetCoins(this->coins);
	HudComponent->SetMagazine(this->magazine);
	HudComponent->SetCurrentMagazine(this->currentMagazine);
	if (magazine == 0) {
		coolDown -= 1;
		if (coolDown == 0) {
			magazine = magazine + currentMagazine;
			coolDown = 50;
		}
	}	
}

void Player::OnRender()
{
	InputObject = GetGameObject()->getScene()->GetGameObjectsByName("Input")[0];
	auto InputComponent = InputObject->GetComponent<InputScript>();
	InputComponent->CheckPause();

	std::shared_ptr<spic::GameObject> pausedTextObject = GetGameObject()->getScene()->GetGameObjectsByTag("paused")[0];
	std::shared_ptr<spic::GameObject> pausedButtonObject = GetGameObject()->getScene()->GetGameObjectsByTag("paused")[1];

	if (InputComponent->GetPaused()) {
		pausedTextObject->SetActive(true);
		pausedButtonObject->SetActive(true);
	}
	if (!InputComponent->GetPaused()) {
		pausedTextObject->SetActive(false);
		pausedButtonObject->SetActive(false);
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
	if (magazine > 0) {
		magazine = magazine - 1;
		for (std::shared_ptr<Bullet> b : bullets) {
			if (b->GetBroken()) {
				b->SetBroken(false);
				auto InputComponent = InputObject->GetComponent<InputScript>();
				spic::Transform transfrom = *b->GetGameObject()->getTransform();
				transfrom.position.x = GetGameObject()->getTransform()->position.x + 20;
				transfrom.position.y = GetGameObject()->getTransform()->position.y + 32;
				b->SetDirection(InputComponent->checkMousePosition());
				b->SetPosition(transfrom.position);
				b->GetGameObject()->setTransform(&transfrom);
				b->CalculateAmountToMove();
				return;
			}
		}
	}
}

void Player::CheckGameOver()
{
	if (healthpoints == 0) {
		std::cout << currentHealthPoints;
		std::shared_ptr<spic::Component> script = GetGameObject()->GetComponentByName("GameOverScript");
		if (script != nullptr) {
			EngineController::GetInstance()->SetGameOver(true);
			script->OnClick();
		}
	}
}

void Player::CheckEndPoint()
{
	if ((xPlayer > endPointTopLeft.x && yPlayer > endPointTopLeft.y)) {
		if (xPlayer < endPointBottomRight.x && yPlayer < endPointBottomRight.y) {
			std::shared_ptr<spic::Component> script = endPointObject->GetComponentByName("EndLevelScript");
			if (script != nullptr) {
				script->OnClick();
			}
		}

	}
}

void Player::CameraFixture()
{
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
}

void Player::FillBucket()
{
	int index = 0;
	while (index < 20) {

		std::shared_ptr<spic::GameObject> bulletObject = std::make_shared<spic::GameObject>("Bullet");
		GetGameObject()->getScene()->AddGameObject(bulletObject);
		spic::Transform transfrom = *bulletObject->getTransform();
		sprite = std::make_shared<spic::Sprite>();
		bulletObject->AddComponent(sprite);
		sprite->SetSprite("assets/bullet.bmp");
		sprite->SetPlayerBool(true);
		bulletObject->AddTag("PlayerBullet");
		transfrom.position.x = 0;
		transfrom.position.y = 0;
		transfrom.scale = 0.55;
		std::shared_ptr<spic::BoxCollider> boxCollider = std::make_shared<spic::BoxCollider>();
		boxCollider->Height(7);
		boxCollider->Width(7);
		bulletObject->AddComponent(boxCollider);
		std::shared_ptr<Bullet> bullet = std::make_shared<Bullet>(transfrom.position, transfrom.position, 20, bulletDamage);
		bulletObject->AddComponent(bullet);
		bulletObject->setTransform(&transfrom);
		bullets.push_back(bullet);
		index++;
	}
}