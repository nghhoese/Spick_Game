#include "Player.hpp"
#include <API_Headers/Engine.hpp>

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

	if (currentHealthPoints == 0) {
		std::cout << currentHealthPoints;
		std::shared_ptr<spic::Component> script = GetGameObject()->GetComponentByName("GameOverScript");
		if (script != nullptr) {
			engine->setGameOver(true);
			script->OnClick();
		}
	}

	// nog weghalen is om te testen
	if (isDamageless) {
		if (this->healthpoints > 0) {
			this->healthpoints -= 1;
		}
	}

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

	// Update fps in HUD
	std::shared_ptr<spic::GameObject> fpsObject = GetGameObject()->getScene()->GetGameObjectsByTag("fps")[0];
	std::shared_ptr<spic::Text> fpsText = std::dynamic_pointer_cast<spic::Text>(fpsObject);
	if (InputComponent->loadFps) {
		fpsText->SetText("FPS: " + std::to_string(engine->GetFPS()));
	}
	if (!InputComponent->loadFps) {
		fpsText->SetText("");
	}
}

void Player::OnRender()
{
	InputObject = GetGameObject()->getScene()->GetGameObjectsByName("Input")[0];
	auto InputComponent = InputObject->GetComponent<InputScript>();
	InputComponent->CheckPause();
	// Update paused in HUD
	std::shared_ptr<spic::GameObject> pausedObject = GetGameObject()->getScene()->GetGameObjectsByTag("paused")[0];
	std::shared_ptr<spic::Text> pausedText = std::dynamic_pointer_cast<spic::Text>(pausedObject);
	if (InputComponent->paused) {
		pausedText->SetText("PAUSED");
	}
	if (!InputComponent->paused) {
		pausedText->SetText("");
	}
}

void Player::OnTriggerEnter2D(const Collider& collider)
{
}

Player::Player(spic::Engine* engine)
{
	this->engine = engine;
	sprite = std::make_shared<spic::Sprite>();
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

	bulletObject->AddComponent(sprite);
	sprite->SetSprite("assets/bullet.bmp");
	sprite->SetPlayerBool(true);

	transfrom.position.x = GetGameObject()->getTransform()->position.x + 20;
	transfrom.position.y = GetGameObject()->getTransform()->position.y + 32;
	transfrom.scale = 0.75;


	std::shared_ptr<Bullet> bullet = std::make_shared<Bullet>(transfrom.position, InputComponent->checkMousePosition(), 20);
	bulletObject->AddComponent(bullet);
	bulletObject->setTransform(&transfrom);
	bullet->CalculateAmountToMove();
}