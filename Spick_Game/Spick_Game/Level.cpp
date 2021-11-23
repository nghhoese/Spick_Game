#include "Level.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

void Level::BuildLevel(std::shared_ptr<spic::Scene> scene, fs::path filePath) {
    auto level_layers = this->Read(filePath);

    std::vector<std::pair<int, std::vector<std::vector<int>>>> tiles = level_layers.first;
    std::vector<std::vector<std::pair<std::string, std::any>>> objects = level_layers.second;

    xTilesize = 64;
    yTilesize = 64;
    level_height = (tiles.at(0).second.size());
    level_width = (tiles.at(0).second.at(0).size());

    // Tile layers
    for (std::pair<int, std::vector<std::vector<int>>> tileset : tiles) {
        BuildLevelLayers(scene, tileset);
    }

    // Object layer
    for (std::vector<std::pair<std::string, std::any>> object : objects) {
        BuildLevelObjects(scene, object);
    }

}

void Level::BuildLevelLayers(std::shared_ptr<spic::Scene> scene, std::pair<int, std::vector<std::vector<int>>> tileset) {
    // background
    if (tileset.first == 1) {
        int x = 0;
        int y = 0;
        for (std::vector<int> vector : tileset.second) {
            for (int object : vector) {
                std::shared_ptr<spic::GameObject> backgroundObject = std::make_shared<spic::GameObject>("background-tile");
                std::shared_ptr<spic::Sprite> backgroundSprite = std::make_shared<spic::Sprite>();
                spic::Transform transform = *backgroundObject->getTransform();
                switch (object + 1) {
                    // background black stars 
                case 0:
                    scene->AddGameObject(backgroundObject);

                    backgroundObject->AddComponent(backgroundSprite);
                    backgroundSprite->SetSprite("assets/images/foregrounds/dark-wood-statue-floor.bmp");
                    transform.position.x = (double)x * xTilesize;
                    transform.position.y = (double)y * yTilesize;
                    transform.scale = 1;
                    backgroundObject->setTransform(&transform);
                    break;
                }

                x++;
                if (x == level_height - 1) {
                    y++;
                    x = 0;
                }
            }
        }
    }
    // foreground (tileset.first == 4)
    else {
        int x = 0;
        int y = 0;
        for (std::vector<int> vector : tileset.second) {
            for (int object : vector) {
                std::shared_ptr<spic::GameObject> tileObject = std::make_shared<spic::GameObject>("foreground-tile");
                std::shared_ptr<spic::Sprite> tileSprite = std::make_shared<spic::Sprite>();
                spic::Transform transform = *tileObject->getTransform();
                switch (object + 1) {

                // bright wood statue floor
                case 19:
                    scene->AddGameObject(tileObject);

                    tileObject->AddComponent(tileSprite);
                    tileSprite->SetSprite("assets/images/foregrounds/bright-wood-statue-floor.bmp");
                    transform.position.x = (double)x * xTilesize;
                    transform.position.y = (double)y * yTilesize;
                    transform.scale = 1;
                    tileObject->setTransform(&transform);
                    break;

                    break;

                // bright wood hitler floor
                case 21:
                    scene->AddGameObject(tileObject);

                    tileObject->AddComponent(tileSprite);
                    tileSprite->SetSprite("assets/images/foregrounds/bright-wood-hitler-floor.bmp");
                    transform.position.x = (double)x * xTilesize;
                    transform.position.y = (double)y * yTilesize;
                    transform.scale = 1;
                    tileObject->setTransform(&transform);
                    break;

                // bright wood floor
                case 23:
                    scene->AddGameObject(tileObject);

                    tileObject->AddComponent(tileSprite);
                    tileSprite->SetSprite("assets/images/foregrounds/bright-wood-floor.bmp");
                    transform.position.x = (double)x * xTilesize;
                    transform.position.y = (double)y * yTilesize;
                    transform.scale = 1;
                    tileObject->setTransform(&transform);
                    break;

                // red wall
                case 34:
                    scene->AddGameObject(tileObject);

                    tileObject->AddComponent(tileSprite);
                    tileSprite->SetSprite("assets/images/foregrounds/red-wall.bmp");
                    transform.position.x = (double)x * xTilesize;
                    transform.position.y = (double)y * yTilesize;
                    transform.scale = 1;
                    tileObject->setTransform(&transform);
                    break;

                // red wall
                case 36:
                    scene->AddGameObject(tileObject);

                    tileObject->AddComponent(tileSprite);
                    tileSprite->SetSprite("assets/images/foregrounds/red-nazi-wall.bmp");
                    transform.position.x = (double)x * xTilesize;
                    transform.position.y = (double)y * yTilesize;
                    transform.scale = 1;
                    tileObject->setTransform(&transform);
                    break;

                // left half red wall
                case 115:
                    scene->AddGameObject(tileObject);

                    tileObject->AddComponent(tileSprite);
                    tileSprite->SetSprite("assets/images/foregrounds/half_1.png");
                    transform.position.x = (double)x * xTilesize;
                    transform.position.y = (double)y * yTilesize;
                    transform.scale = 1;
                    tileObject->setTransform(&transform);
                    break;

                // top red half wall
                case 116:
                    scene->AddGameObject(tileObject);

                    tileObject->AddComponent(tileSprite);
                    tileSprite->SetSprite("assets/images/foregrounds/half_2.png");
                    transform.position.x = (double)x * xTilesize;
                    transform.position.y = (double)y * yTilesize;
                    transform.scale = 1;
                    tileObject->setTransform(&transform);
                    break;

                // right half red wall
                case 117:
                    scene->AddGameObject(tileObject);

                    tileObject->AddComponent(tileSprite);
                    tileSprite->SetSprite("assets/images/foregrounds/half_3.png");
                    transform.position.x = (double)x * xTilesize;
                    transform.position.y = (double)y * yTilesize;
                    transform.scale = 1;
                    tileObject->setTransform(&transform);
                    break;

                // bottom half red wall
                case 118:
                    scene->AddGameObject(tileObject);

                    tileObject->AddComponent(tileSprite);
                    tileSprite->SetSprite("assets/images/foregrounds/half_4.png");
                    transform.position.x = (double)x * xTilesize;
                    transform.position.y = (double)y * yTilesize;
                    transform.scale = 1;
                    tileObject->setTransform(&transform);
                    break;

                // top left corner red half wall
                case 119:
                    scene->AddGameObject(tileObject);

                    tileObject->AddComponent(tileSprite);
                    tileSprite->SetSprite("assets/images/foregrounds/inside_1.png");
                    transform.position.x = (double)x * xTilesize;
                    transform.position.y = (double)y * yTilesize;
                    transform.scale = 1;
                    tileObject->setTransform(&transform);
                    break;

                // bottom left corner red half wall
                case 120:
                    scene->AddGameObject(tileObject);

                    tileObject->AddComponent(tileSprite);
                    tileSprite->SetSprite("assets/images/foregrounds/inside_2.png");
                    transform.position.x = (double)x * xTilesize;
                    transform.position.y = (double)y * yTilesize;
                    transform.scale = 1;
                    tileObject->setTransform(&transform);
                    break;

                // top right red wall
                case 121:
                    scene->AddGameObject(tileObject);

                    tileObject->AddComponent(tileSprite);
                    tileSprite->SetSprite("assets/images/foregrounds/inside_3.png");
                    transform.position.x = (double)x * xTilesize;
                    transform.position.y = (double)y * yTilesize;
                    transform.scale = 1;
                    tileObject->setTransform(&transform);
                    break;

                // bottom right corner red half wall
                case 122:
                    scene->AddGameObject(tileObject);

                    tileObject->AddComponent(tileSprite);
                    tileSprite->SetSprite("assets/images/foregrounds/inside_4.png");
                    transform.position.x = (double)x * xTilesize;
                    transform.position.y = (double)y * yTilesize;
                    transform.scale = 1;
                    tileObject->setTransform(&transform);
                    break;

                // top right angled red half wall
                case 123:
                    scene->AddGameObject(tileObject);

                    tileObject->AddComponent(tileSprite);
                    tileSprite->SetSprite("assets/images/foregrounds/outside_1.png");
                    transform.position.x = (double)x * xTilesize;
                    transform.position.y = (double)y * yTilesize;
                    transform.scale = 1;
                    tileObject->setTransform(&transform);
                    break;

                    // top right angled red half wall
                case 124:
                    scene->AddGameObject(tileObject);

                    tileObject->AddComponent(tileSprite);
                    tileSprite->SetSprite("assets/images/foregrounds/outside_2.png");
                    transform.position.x = (double)x * xTilesize;
                    transform.position.y = (double)y * yTilesize;
                    transform.scale = 1;
                    tileObject->setTransform(&transform);
                    break;

                // top right angled red half wall
                case 125:
                    scene->AddGameObject(tileObject);

                    tileObject->AddComponent(tileSprite);
                    tileSprite->SetSprite("assets/images/foregrounds/outside_3.png");
                    transform.position.x = (double)x * xTilesize;
                    transform.position.y = (double)y * yTilesize;
                    transform.scale = 1;
                    tileObject->setTransform(&transform);
                    break;

                    // top right angled red half wall
                case 126:
                    scene->AddGameObject(tileObject);

                    tileObject->AddComponent(tileSprite);
                    tileSprite->SetSprite("assets/images/foregrounds/outside_4.png");
                    transform.position.x = (double)x * xTilesize;
                    transform.position.y = (double)y * yTilesize;
                    transform.scale = 1;
                    tileObject->setTransform(&transform);
                    break;

                }              

                x++;
                if (x == level_width) {
                    y++;
                    x = 0;
                }
            }
        }
    }
}

void Level::BuildLevelObjects(std::shared_ptr<spic::Scene> scene, std::vector<std::pair<std::string, std::any>> object){
    std::shared_ptr<spic::Sprite> sprite = std::make_shared<spic::Sprite>();

    if (get_value<std::string>("type", object) == "Waypoint") {

        if (get_value<std::string>("name", object) == "StartPoint") {

            for (std::pair<std::string, std::any> value : object) {
                if (value.first._Equal("position")) {
                    std::tuple<int, int> position = std::any_cast<std::tuple<int, int>>(value.second);

                    std::shared_ptr<spic::GameObject> playerObject = std::make_shared<spic::GameObject>("Player");

                    scene->AddGameObject(playerObject);
                    spic::Transform transfrom = *playerObject->getTransform();
                    playerObject->AddComponent(sprite);
                    sprite->SetSprite("assets/player_sub-machinegun.bmp");
                    sprite->SetPlayerBool(true);
                    transfrom.position.x = std::get<0>(position);
                    transfrom.position.y = std::get<1>(position);
                    transfrom.scale = 0.75;
                    std::shared_ptr<Player> player = std::make_shared<Player>();
                    playerObject->AddComponent(player);
                    playerObject->setTransform(&transfrom);
                }
            }
        }
    }

    if (get_value<std::string>("type", object) == "Enemy") {

        if (get_value<std::string>("name", object) == "GreenGuard") {

            for (std::pair<std::string, std::any> value : object) {

                if (value.first._Equal("position")) {
                    std::tuple<int, int> position = std::any_cast<std::tuple<int, int>>(value.second);

                    std::shared_ptr<spic::GameObject> GreenGuardObject = std::make_shared<spic::GameObject>("GreenGuard");

                    scene->AddGameObject(GreenGuardObject);
                    spic::Transform transfrom = *GreenGuardObject->getTransform();

                    transfrom.position.x = std::get<0>(position);
                    transfrom.position.y = std::get<1>(position);
                    transfrom.scale = 0.75;

                    std::shared_ptr<Enemy> enemy = std::make_shared<Enemy>();
                    enemy->setHealthpoints(100);
                    enemy->setDamagePerBullet(40);
                    enemy->setPath("assets/enemy_green.bmp");

                    GreenGuardObject->AddComponent(sprite);
                    sprite->SetSprite(enemy->getPath());
                    GreenGuardObject->AddComponent(enemy);
                    GreenGuardObject->setTransform(&transfrom);
                }
            }

        }

        if (get_value<std::string>("name", object) == "RedGuard") {

            for (std::pair<std::string, std::any> value : object) {

                if (value.first._Equal("position")) {
                    std::tuple<int, int> position = std::any_cast<std::tuple<int, int>>(value.second);

                    std::shared_ptr<spic::GameObject> RedGuardObject = std::make_shared<spic::GameObject>("GreenGuard");

                    scene->AddGameObject(RedGuardObject);
                    spic::Transform transfrom = *RedGuardObject->getTransform();

                    transfrom.position.x = std::get<0>(position);
                    transfrom.position.y = std::get<1>(position);
                    transfrom.scale = 0.75;

                    std::shared_ptr<Enemy> enemy = std::make_shared<Enemy>();
                    enemy->setHealthpoints(75);
                    enemy->setDamagePerBullet(50);
                    enemy->setPath("assets/enemy_red.bmp");

                    RedGuardObject->AddComponent(sprite);
                    sprite->SetSprite(enemy->getPath());
                    RedGuardObject->AddComponent(enemy);
                    RedGuardObject->setTransform(&transfrom);
                }
            }

        }

        if (get_value<std::string>("name", object) == "BlueGuard") {

            for (std::pair<std::string, std::any> value : object) {

                if (value.first._Equal("position")) {
                    std::tuple<int, int> position = std::any_cast<std::tuple<int, int>>(value.second);

                    std::shared_ptr<spic::GameObject> BlueGuardObject = std::make_shared<spic::GameObject>("GreenGuard");

                    scene->AddGameObject(BlueGuardObject);
                    spic::Transform transfrom = *BlueGuardObject->getTransform();

                    transfrom.position.x = std::get<0>(position);
                    transfrom.position.y = std::get<1>(position);
                    transfrom.scale = 0.75;

                    std::shared_ptr<Enemy> enemy = std::make_shared<Enemy>();
                    enemy->setHealthpoints(150);
                    enemy->setDamagePerBullet(50);
                    enemy->setPath("assets/enemy_blue.bmp");

                    BlueGuardObject->AddComponent(sprite);
                    sprite->SetSprite(enemy->getPath());
                    BlueGuardObject->AddComponent(enemy);
                    BlueGuardObject->setTransform(&transfrom);
                }
            }

        }
    }

    //for (std::pair<std::string, std::any> value : object) {
    //    if (value.first._Equal("type")) {
    //        auto test = get_value(value.second,);
    //        auto tes2 = "jeoma";
    //    }

    //    if (value.first._Equal("position")) {
    //        std::tuple<int, int> position = std::any_cast<std::tuple<int, int>>(value.second);
    //    }
    //}
}
