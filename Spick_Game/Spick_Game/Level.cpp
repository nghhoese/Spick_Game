#include "Level.hpp"
#include <API_Headers/BoxCollider.hpp>

Level::Level(spic::Engine* engine)
{
    this->engine = engine;
}

void Level::BuildLevel(std::shared_ptr<spic::Scene> scene, std::filesystem::path filePath) {
    auto level_layers = engine->GetLevel(filePath);

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
    // foreground
    if(tileset.first == 4) {
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
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "bright-wood-statue-floor");
                    break;

                // bright wood hitler floor
                case 21:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "bright-wood-hitler-floor");
                    break;

                // bright wood floor
                case 23:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "bright-wood-floor");
                    break;

                // dark wood floor
                case 24:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "dark-wood-floor");
                    break;

                // red wall
                case 34:
                    tileObject->AddTag("wall");
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "red-wall");
                    break;

                // red wall
                case 36:
                    tileObject->AddTag("wall");
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "red-nazi-wall");
                    break;

                // dark blue skull stone wall
                case 68:
                    tileObject->AddTag("wall");
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "dark-blue-skull-stone-wall");
                    break;

                // dark stone wall
                case 70:
                    tileObject->AddTag("wall");
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "dark-stone-wall");
                    break;

                // dark blue nazi stone wall
                case 72:
                    tileObject->AddTag("wall");
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "dark-blue-nazi-stone-wall");
                    break;

                // dark blue nazi stone wall
                case 80:
                    tileObject->AddTag("wall");
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "dark-blue-stone-wall");
                    break;

                // bright vent
                case 105:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "bright-vent");
                    break;

                // stone floor
                case 109:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "stone-floor");
                    break;

                // left half red wall
                case 115:
                    tileObject->AddTag("wall");
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "half_1");
                    break;

                // top red half wall
                case 116:
                    tileObject->AddTag("wall");
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "half_2");
                    break;

                // right half red wall
                case 117:
                    tileObject->AddTag("wall");
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "half_3");
                    break;

                // bottom half red wall
                case 118:
                    tileObject->AddTag("wall");
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "half_4");
                    break;

                // top left corner red half wall
                case 119:
                    tileObject->AddTag("wall");
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "inside_1");
                    break;

                // bottom left corner red half wall
                case 120:
                    tileObject->AddTag("wall");
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "inside_2");
                    break;

                // top right red wall
                case 121:
                    tileObject->AddTag("wall");
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "inside_3");
                    break;

                // bottom right corner red half wall
                case 122:
                    tileObject->AddTag("wall");
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "inside_4");
                    break;

                // top right angled red half wall
                case 123:
                    tileObject->AddTag("wall");
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "outside_1");
                    break;

                // top right angled red half wall
                case 124:
                    tileObject->AddTag("wall");
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "outside_2");
                    break;

                // top right angled red half wall
                case 125:
                    tileObject->AddTag("wall");
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "outside_3");
                    break;

                // top right angled red half wall
                case 126:
                    tileObject->AddTag("wall");
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "outside_4");
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

void Level::BuildLevelTile(std::shared_ptr<spic::Scene> scene, std::shared_ptr<spic::GameObject> tileObject, std::shared_ptr<spic::Sprite> tileSprite, spic::Transform transform, int x, int y, const std::string& spriteName) {

    std::string basePath = "assets/images/foregrounds/" + spriteName;

    scene->AddGameObject(tileObject);
    tileObject->AddComponent(tileSprite);
        std::shared_ptr<spic::BoxCollider> boxCollider = std::make_shared<spic::BoxCollider>();
    boxCollider->Height(55);
    boxCollider->Width(55);
    tileObject->AddComponent(boxCollider);
    if (std::filesystem::exists(basePath + bmpFileString)) {
        tileSprite->SetSprite(basePath + bmpFileString);
    }
    else if (std::filesystem::exists(basePath + pngFileString)) {
        tileSprite->SetSprite(basePath + pngFileString);
    }

    transform.position.x = (double)x * xTilesize;
    transform.position.y = (double)y * yTilesize;
    transform.scale = 1;
    tileObject->setTransform(&transform);
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
                    std::shared_ptr<Player> player = std::make_shared<Player>(engine);
                    playerObject->AddComponent(player);
                    playerObject->setTransform(&transfrom);

                    std::shared_ptr<ChangeSceneBehaviour> gameOverScript = std::make_shared<ChangeSceneBehaviour>("GameOverScript", "GameOverMenu", engine);
                    playerObject->AddComponent(gameOverScript);
                    std::shared_ptr<spic::BoxCollider> boxCollider = std::make_shared<spic::BoxCollider>();
                    boxCollider->Height(55);
                    boxCollider->Width(55);
                    playerObject->AddComponent(boxCollider);
                }
            }
        }

        if (get_value<std::string>("name", object) == "EndPoint") {
            for (std::pair<std::string, std::any> value : object) {
                if (value.first._Equal("position")) {
                    std::tuple<int, int> position = std::any_cast<std::tuple<int, int>>(value.second);

                    std::shared_ptr<spic::GameObject> endPointObject = std::make_shared<spic::GameObject>("Endpoint");

                    scene->AddGameObject(endPointObject);
                    spic::Transform transfrom = *endPointObject->getTransform();
                    transfrom.position.x = std::get<0>(position);
                    transfrom.position.y = std::get<1>(position);
                    endPointObject->setTransform(&transfrom);

                    std::string counterString = std::to_string(currentLevel + 1);
                    std::string levelString = "level" + counterString;
                    std::shared_ptr<ChangeSceneBehaviour> scriptPlay = std::make_shared<ChangeSceneBehaviour>("EndLevelScript", levelString, engine);
                    endPointObject->AddComponent(scriptPlay);
                    currentLevel + 1;
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
                    GreenGuardObject->AddTag("guard");

                    scene->AddGameObject(GreenGuardObject);
                    spic::Transform transfrom = *GreenGuardObject->getTransform();

                    transfrom.position.x = std::get<0>(position);
                    transfrom.position.y = std::get<1>(position);
                    transfrom.scale = 0.75;

                    std::shared_ptr<Enemy> enemy = std::make_shared<Enemy>();
                    enemy->setHealthpoints(100);
                    enemy->setDamagePerBullet(40);
                    enemy->setPath("assets/enemy_green.bmp");
                    std::shared_ptr<spic::BoxCollider> boxCollider = std::make_shared<spic::BoxCollider>();
                    boxCollider->Height(45);
                    boxCollider->Width(45);
                    GreenGuardObject->AddComponent(boxCollider);
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
                    RedGuardObject->AddTag("guard");
                    scene->AddGameObject(RedGuardObject);
                    spic::Transform transfrom = *RedGuardObject->getTransform();

                    transfrom.position.x = std::get<0>(position);
                    transfrom.position.y = std::get<1>(position);
                    transfrom.scale = 0.75;

                    std::shared_ptr<Enemy> enemy = std::make_shared<Enemy>();
                    enemy->setHealthpoints(75);
                    enemy->setDamagePerBullet(50);
                    enemy->setPath("assets/enemy_red.bmp");
                    std::shared_ptr<spic::BoxCollider> boxCollider = std::make_shared<spic::BoxCollider>();
                    boxCollider->Height(45);
                    boxCollider->Width(45);
                    RedGuardObject->AddComponent(boxCollider);
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

}
