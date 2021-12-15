#include "Bullet.hpp"
#include <API_Headers/Collision.hpp>
#include <API_Headers/Animator.hpp>

Bullet::Bullet(spic::Point pos, spic::Point direction, double speed, int damage) : position(pos), direction(direction), speed(speed), damage(damage), hit(false), broken(true)
{
}

void Bullet::Update()
{
	if (!broken) {
		auto trans = *GetGameObject()->getTransform();
		spic::Time time;
		trans.position.x += amountToMoveX * speed;
		trans.position.y += amountToMoveY * speed;
		GetGameObject()->setTransform(&trans);
		if (Collision::AABB(GetGameObject(), "guard")) {
			auto enemy = Collision::AABB(GetGameObject(), "guard")->GetGameObject()->GetComponent<spic::BehaviourScript>();
			std::shared_ptr<Enemy> enemtObj = std::dynamic_pointer_cast<Enemy>(enemy);
			if (hit) {
				enemtObj->setHealthpoints(enemtObj->getHealthpoints() - damage);
				hit = false;
				broken = true;
				std::shared_ptr<spic::Animator> animatie = std::dynamic_pointer_cast<spic::Animator>(enemtObj->GetGameObject()->GetComponentByName("hitAnimation"));
				animatie->Play(false);
				/*enemtObj->setPath("assets/enemy_hit.png");*/
				
			}
		}
		if (Collision::AABB(GetGameObject(), "wall")) {
			broken = true;
		}
		else {
			hit = true;
		}
	}
	else {
		auto trans = *GetGameObject()->getTransform();
		trans.position.x = -50;
		trans.position.y = -10;
		GetGameObject()->setTransform(&trans);
	}
}

void Bullet::OnAwake()
{
}

void Bullet::OnStart()
{
}

void Bullet::OnUpdate()
{
	Update();
}

void Bullet::OnRender()
{
}

void Bullet::OnTriggerEnter2D(const spic::Collider& collider)
{
}

void Bullet::OnClick()
{
}

void Bullet::CalculateAmountToMove()
{
	float distance = (float)sqrt(pow(position.x - GetGameObject()->getScene()->GetActiveCamera()->getX() - direction.x, 2) + pow(position.y - GetGameObject()->getScene()->GetActiveCamera()->getY() - direction.y, 2));
	amountToMoveX = (((position.x - GetGameObject()->getScene()->GetActiveCamera()->getX()) - direction.x) * -1) / distance;
	amountToMoveY = (((position.y - GetGameObject()->getScene()->GetActiveCamera()->getY()) - direction.y) * -1) / distance;
}

void Bullet::OnTriggerExit2D(const spic::Collider& collider)
{
}

void Bullet::OnTriggerStay2D(const spic::Collider& collider)
{
}