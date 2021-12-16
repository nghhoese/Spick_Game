#include "Boss.hpp"
#include "API_Headers/Scene.hpp"
#include <API_Headers/Sprite.hpp>
#include <API_Headers/BoxCollider.hpp>
#include <API_Headers/Collision.hpp>
#include "../Scenes/LevelSceneBuilder.hpp"


bool Boss::IfPlayerNearby()
{
    return true;
}

bool Boss::InShootingRange()
{
    return true;
}

Boss::Boss() : speed(0), turnCount(0), isTurned(false), isAlive(true), notInitialized(true), magazine(20), bulletDamage(10), coolDown(90), currentMagazine(magazine), bulletSpeed(20), burstSpeed(3)
{
}

void Boss::OnAwake()
{
}

void Boss::OnStart()
{
    auto trans = *GetGameObject()->getTransform();
    double Delta_x = (trans.position.x);
    double Delta_y = (trans.position.y);

    double Result = (atan2(Delta_y, Delta_x) * 180.0000) / 3.14159265;
    trans.rotation = Result + (rand() % 180 + 90);
    GetGameObject()->setTransform(&trans);
    vel.x = 0;
    vel.y = 0;
    acc.x = 0;
    acc.y = 0;
}

void Boss::OnUpdate()
{
    if (this->healthpoints <= 0) {
        EngineController::GetInstance()->SetActiveScene("CompletedScene");
    }

    if (isAlive)
    {
        if (GetGameObject()->getScene()->GetGameObjectsByName("Player").size() > 0) {
            if (notInitialized)
            {
                notInitialized = false;
                player = GetGameObject()->getScene()->GetGameObjectsByName("Player")[0];
                AI = std::make_unique<AIController>(*GetGameObject(), vel, *player, speed);
            }

            auto trans = *GetGameObject()->getTransform();
            auto player = GetGameObject()->getScene()->GetGameObjectsByName("Player")[0];
            
            AI->Update(*GetGameObject(), vel, *player);

            double Delta_x = (trans.position.x - player->getTransform()->position.x);
            double Delta_y = (trans.position.y - player->getTransform()->position.y);

            double Result = (atan2(Delta_y, Delta_x) * 180.0000) / 3.14159265;
            trans.rotation = Result + 90;    

            GetGameObject()->setTransform(&trans);
            
            Shoot();
        }
    }
}


void Boss::OnRender()
{
}

void Boss::OnTriggerEnter2D(const spic::Collider& collider)
{
}

void Boss::OnTriggerExit2D(const spic::Collider& collider)
{
}

void Boss::OnTriggerStay2D(const spic::Collider& collider)
{
}

void Boss::setPath(const std::string& path)
{
    this->path = path;
    auto sprite = GetGameObject()->GetComponent<spic::Sprite>();
    if (sprite != nullptr)
    {
        sprite->SetSprite(path);
    }
}

const std::string& Boss::getPath()
{
    return this->path;
}

void Boss::OnClick()
{
}

void Boss::Shoot()
{
    if (magazine > 0) {
       
        if (burstCooldown == 0) {
            magazine = magazine - 1;
            std::shared_ptr<Bullet> b = bullets[bulletCounter];
            if (b->GetBroken()) {
                b->SetBroken(false);
                //auto InputComponent = InputObject->GetComponent<InputScript>();
                int randomSpreadX = rand() % 181 + (-90);
                int randomSpreadY = rand() % 181 + (-90);
                spic::Transform transfrom = *b->GetGameObject()->getTransform();
                transfrom.position.x = GetGameObject()->getTransform()->position.x + 72;
                transfrom.position.y = GetGameObject()->getTransform()->position.y + 72;
                b->SetDirection(player->getTransform()->position.x + 32 + randomSpreadX, player->getTransform()->position.y + 32 + randomSpreadY);
                b->SetPosition(transfrom.position);
                b->GetGameObject()->setTransform(&transfrom);
                b->CalculateAmountToMove();
            }
            burstCooldown = burstSpeed;
            bulletCounter += 1;
            if (magazine == 0) {
                bulletCounter = 0;
            }
        }
        else {
            burstCooldown -= 1;
        }
       
    }else if (magazine == 0) {
        coolDown -= 1;
        if (coolDown == 0) {
            magazine = magazine + currentMagazine;
            coolDown = 100;
        }
    }
}

void Boss::FillBucket()
{
    bullets.clear();
    int index = 0;
    while (index < magazine) {

        std::shared_ptr<spic::GameObject> bulletObject = std::make_shared<spic::GameObject>("EnemyBullet");
        GetGameObject()->getScene()->AddGameObject(bulletObject);
        spic::Transform transfrom = *bulletObject->getTransform();
        sprite = std::make_shared<spic::Sprite>();
        bulletObject->AddComponent(sprite);
        sprite->SetSprite("assets/bullet.bmp");
        sprite->SetPlayerBool(true);
        bulletObject->AddTag("EnemyBullet");
        transfrom.position.x = 0;
        transfrom.position.y = 0;
        transfrom.scale = 1;
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
