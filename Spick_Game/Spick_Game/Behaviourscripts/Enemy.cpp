#include "Enemy.hpp"

Enemy::Enemy() : hit(false), speed(1.5), isAlive(true), notInitialized(true), magazine(1), bulletDamage(30), coolDown(50), currentMagazine(magazine), bulletSpeed(10), triggerSpace(300), shootingSpace(175)
{
}

bool Enemy::IfPlayerNearby()
{
    auto enemyPos = GetGameObject()->getTransform()->position;
    auto playerPos = GetGameObject()->getScene()->GetGameObjectsByName("Player")[0]->getTransform()->position;
    auto enemyDirection = GetGameObject()->getTransform()->rotation;
    double Delta_x = (enemyPos.x - playerPos.x);
    double Delta_y = (enemyPos.y - playerPos.y);
    double enemyToPlayerDir = ((atan2(Delta_y, Delta_x) * 180.0000) / 3.14159265) + 90;
    auto radians = 45;
    if (enemyDirection - radians <= enemyToPlayerDir &&
        enemyDirection + radians >= enemyToPlayerDir)
    {
        return (enemyPos.x + triggerSpace >= playerPos.x &&
        enemyPos.x - triggerSpace <= playerPos.x &&
        enemyPos.y + triggerSpace >= playerPos.y &&
        enemyPos.y - triggerSpace <= playerPos.y);
    }
    return false;
}

bool Enemy::InShootingRange()
{
    auto enemyPos = GetGameObject()->getTransform()->position;
    auto playerPos = GetGameObject()->getScene()->GetGameObjectsByName("Player")[0]->getTransform()->position;

    return (enemyPos.x + shootingSpace >= playerPos.x &&
        enemyPos.x - shootingSpace <= playerPos.x &&
        enemyPos.y + shootingSpace >= playerPos.y &&
        enemyPos.y - shootingSpace <= playerPos.y);
}

void Enemy::UpdateAIBehaviour(spic::Point steering)
{
    trans.position.Add(steering);
    GetGameObject()->setTransform(&trans);
}

void Enemy::CalculateRotation(spic::Point object, spic::Point target)
{
    double Delta_x = (object.x - target.x);
    double Delta_y = (object.y - target.y);
    double Result = (atan2(Delta_y, Delta_x) * 180.0000) / 3.14159265;
    trans.rotation = Result + 90;
    GetGameObject()->setTransform(&trans);
}

void Enemy::Attack() 
{
    CalculateRotation(trans.position, player->getTransform()->position);

    if (!InShootingRange())
    {
        UpdateAIBehaviour(AI->Persue());
    }
    else {
        Shoot();
    }
}

void Enemy::BulletHandling() 
{
    if (!Collision::AABB(GetGameObject(), "PlayerBullet").empty()) {
        auto bullet = Collision::AABB(GetGameObject(), "PlayerBullet")[0]->GetGameObject()->GetComponent<spic::BehaviourScript>();
        std::shared_ptr<Bullet> bulletObj = std::dynamic_pointer_cast<Bullet>(bullet);

        setHealthpoints(getHealthpoints() - bulletObj->GetDamage());
        bulletObj->SetBroken(true);
        setPath("assets/enemy_hit.png");

        hit = true;
    }
}

void Enemy::DoEnemyThings()
{
    if (isAlive)
    {
        BulletHandling();

        if (GetGameObject()->getScene()->GetGameObjectsByName("Player").size() > 0) {
            if (notInitialized)
            {
                notInitialized = false;
                player = GetGameObject()->getScene()->GetGameObjectsByName("Player")[0];
                AI = std::make_unique<spic::AI>(*GetGameObject(), *player, speed, true);
                AI->SetCollisionObjectName("wall");
            }

            AI->Update(*GetGameObject(), *player);

            if (IfPlayerNearby() || hit)
            {
                Attack();
            }
            else {
                UpdateAIBehaviour(AI->Wander());
                CalculateRotation(trans.position, AI->GetSight());
            }
        }
    }
}

void Enemy::HandleHealth() 
{
    if (this->healthpoints < 0) {
        if (isAlive) {
            isAlive = false;

            GetGameObject()->SetName("");
            GetGameObject()->GetComponent<spic::Animator>()->Play(false);
        }
        if (!GetGameObject()->GetComponent<spic::Animator>()->GetRunning()) {
            setPath("assets/bloodsplatter.png");
            isAlive = false;
            hit = false;
            trans.scale = 0.01;
            trans.position.x = -50;
            trans.position.y = -10;
            GetGameObject()->setTransform(&trans);
            GetGameObject()->GetComponent<spic::Sprite>()->OnRender();
           
        }


        
       
    }
}

void Enemy::OnAwake()
{
}

void Enemy::OnStart()
{
    trans = *GetGameObject()->getTransform();
    double Result = (atan2(trans.position.y, trans.position.x) * 180.0000) / 3.14159265;
    trans.rotation = Result + (rand() % 180 + 90);
    GetGameObject()->setTransform(&trans);
}

void Enemy::OnUpdate()
{
    HandleHealth();
    DoEnemyThings();
}


void Enemy::OnRender()
{
}

void Enemy::OnTriggerEnter2D(const spic::Collider& collider)
{
}

void Enemy::OnTriggerExit2D(const spic::Collider& collider)
{
}

void Enemy::OnTriggerStay2D(const spic::Collider& collider)
{
}

void Enemy::setPath(const std::string& path)
{
	this->path = path;
    auto sprite = GetGameObject()->GetComponent<spic::Sprite>();
    if (sprite != nullptr)
    {
        sprite->SetSprite(path);
    }
}

const std::string& Enemy::getPath()
{
	return this->path;
}

void Enemy::OnClick()
{
}

void Enemy::Shoot()
{
    if (magazine == 0) {
        coolDown -= 1;
        if (coolDown == 0) {
            magazine = magazine + currentMagazine;
            coolDown = 50;
        }
    } else if (magazine > 0) {
        magazine = magazine - 1;
        for (std::shared_ptr<Bullet> b : bullets) {
            if (b->GetBroken()) {
                b->SetBroken(false);
                spic::Transform transfrom = *b->GetGameObject()->getTransform();
                transfrom.position.x = GetGameObject()->getTransform()->position.x + 32;
                transfrom.position.y = GetGameObject()->getTransform()->position.y + 20;
                b->SetDirection(player->getTransform()->position.x + 32, player->getTransform()->position.y + 32);
                b->SetPosition(transfrom.position);
                b->GetGameObject()->setTransform(&transfrom);
                b->CalculateAmountToMove();
                return;
            }
        }
    }
}

void Enemy::FillBucket()
{
    bullets.clear();
    int index = 0;
    while (index < 5) {
        std::shared_ptr<spic::GameObject> bulletObject = std::make_shared<spic::GameObject>("EnemyBullet");
        GetGameObject()->getScene()->AddGameObject(bulletObject);
        spic::Transform transfrom = *bulletObject->getTransform();
        sprite = std::make_shared<spic::Sprite>();
        bulletObject->AddComponent(sprite);
        sprite->SetSprite("assets/bullet.bmp");
        sprite->SetPlayerBool(true);
        transfrom.position.Set(0);
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
