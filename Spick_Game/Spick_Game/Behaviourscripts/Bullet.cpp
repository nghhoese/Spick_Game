#include "Bullet.hpp"
#include <API_Headers/Collision.hpp>

Bullet::Bullet(spic::Point pos, spic::Point direction, double speed, int damage) : position(pos), direction(direction), speed(speed), damage(damage), hit(false), broken(false)
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
				enemtObj->setPath("assets/enemy_hit.png");
				
			}
			/*else
			{	
				auto tag = enemtObj->GetGameObject()->GetTags();
				for (auto t : tag) {
					if (t == "red")
					{
						enemtObj->setPath("assets/enemy_red.bmp");
					} else if(t == "blue") 
					{
						enemtObj->setPath("assets/enemy_blue.bmp");

					}
					else if (t == "green") 
					{
						enemtObj->setPath("assets/enemy_green.bmp");

					}
				}
			}*/
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
		trans.scale = 0.01;
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

void Bullet::OnTriggerEnter2D(const Collider& collider)
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

void Bullet::OnTriggerExit2D(const Collider& collider)
{
}

void Bullet::OnTriggerStay2D(const Collider& collider)
{
}