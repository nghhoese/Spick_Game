#include "Boss.hpp"
#include "API_Headers/Scene.hpp"
#include <API_Headers/Sprite.hpp>
#include <API_Headers/BoxCollider.hpp>
#include <API_Headers/Collision.hpp>
#include "../Scenes/LevelSceneBuilder.hpp"

Boss::Boss() : burstCooldown(0), bulletCounter(0), isAlive(true), notInitialized(true), magazine(20), bulletDamage(10), coolDown(90), currentMagazine(magazine), bulletSpeed(20), burstSpeed(3), healthpoints(1000), maxhealthpoints(1000)
{
}

void Boss::CalculateRotation(spic::Point object, spic::Point target) 
{
    double Delta_x = (object.x - target.x);
    double Delta_y = (object.y - target.y);
    double Result = (atan2(Delta_y, Delta_x) * 180.0000) / 3.14159265;
    trans.rotation = Result + 90;
    GetGameObject()->setTransform(&trans);
}

void Boss::DoBossThings() 
{
    if (isAlive)
    {
        if (GetGameObject()->getScene()->GetGameObjectsByName("Player").size() > 0) {
            if (notInitialized)
            {
                notInitialized = false;
                player = GetGameObject()->getScene()->GetGameObjectsByName("Player")[0];
            }
            CalculateRotation(trans.position, player->getTransform()->position);
            Shoot();
        }
    }
}

void Boss::BulletHandling()
{
    if (this->healthpoints <= 0) {
        EngineController::GetInstance()->SetActiveScene("CompletedScene");
    }

    if (!Collision::AABB(GetGameObject(), "PlayerBullet").empty()) {
        auto bullet = Collision::AABB(GetGameObject(), "PlayerBullet")[0]->GetGameObject()->GetComponent<spic::BehaviourScript>();
        std::shared_ptr<Bullet> bulletObj = std::dynamic_pointer_cast<Bullet>(bullet);
        setHealthpoints(getHealthpoints() - bulletObj->GetDamage());
        bulletObj->SetBroken(true);
        std::shared_ptr<spic::GameObject> bossHpObject = EngineController::GetInstance()->GetActiveScene()->GetGameObjectsByName("bosshp")[0];
        std::shared_ptr<spic::Text> bossHpText = std::dynamic_pointer_cast<spic::Text>(bossHpObject);
        int percentage = 100 + ((this->healthpoints - this->maxhealthpoints) * 100) / maxhealthpoints;
        bossHpText->SetText("BOSS: " + std::to_string(percentage) + "%");
    }
}

void Boss::OnAwake()
{
}

void Boss::OnStart()
{
    trans = *GetGameObject()->getTransform();
    double Result = (atan2(trans.position.y, trans.position.x) * 180.0000) / 3.14159265;
    trans.rotation = Result + (rand() % 180 + 90);
    GetGameObject()->setTransform(&trans);
}

void Boss::OnUpdate()
{
    BulletHandling();
    DoBossThings();
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
                //b->GetGameObject()->GetComponent<spic::AudioSource>()->Play(true);

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
        std::shared_ptr<spic::AudioSource> biem = std::make_shared<spic::AudioSource>();
        biem->SetAudioClip("assets/biem.mp3");
        biem->SetIsMusic(false);
        bulletObject->AddComponent(biem);
        bulletObject->AddComponent(sprite);
        sprite->SetSprite("assets/bullet.bmp");
        sprite->SetPlayerBool(true);
        bulletObject->AddTag("EnemyBullet");
        transfrom.position.x = 0;
        transfrom.position.y = 0;
        transfrom.scale = 1;
        std::shared_ptr<spic::BoxCollider> boxCollider = std::make_shared<spic::BoxCollider>();
        boxCollider->Height(13);
        boxCollider->Width(13);
        bulletObject->AddComponent(boxCollider);
        std::shared_ptr<Bullet> bullet = std::make_shared<Bullet>(transfrom.position, transfrom.position, 20, bulletDamage);
        bulletObject->AddComponent(bullet);
        bulletObject->setTransform(&transfrom);
        bullets.push_back(bullet);
        index++;
    }
}
