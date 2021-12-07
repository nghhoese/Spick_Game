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
                // bright wood floor
                case 23:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "bright-wood-floor", "");
                    break;
                // dark wood floor
                case 24:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "dark-wood-floor", "");
                    break;
                // elevator
                case 26:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "elevator", "");
                    break;
                // red wall
                case 34:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "red-wall", "wall");
                    break;
                // dark blue skull stone wall
                case 68:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "dark-blue-skull-stone-wall", "wall");
                    break;
                // dark stone wall
                case 70:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "dark-stone-wall", "wall");
                    break;
                // red-grey-brown-wall
                case 76:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "red-grey-brown-wall", "wall");
                    break;
                // dark blue nazi stone wall
                case 80:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "dark-blue-stone-wall", "wall");
                    break;
                // dark vent
                case 106:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "bright-vent", "");
                    break;
                // stone floor
                case 109:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "stone-floor", "");
                    break;
                // left half red wall
                case 115:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "half_1", "wall");
                    break;
                // top red half wall
                case 116:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "half_2", "wall");
                    break;
                // right half red wall
                case 117:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "half_3", "wall");
                    break;
                // bottom half red wall
                case 118:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "half_4", "wall");
                    break;
                // top left corner red half wall
                case 119:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "inside_1", "wall");
                    break;
                // bottom left corner red half wall
                case 120:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "inside_2", "wall");
                    break;
                // top right red wall
                case 121:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "inside_3", "wall");
                    break;
                // bottom right corner red half wall
                case 122:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "inside_4", "wall");
                    break;
                // top left angled red half wall
                case 123:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "outside_1", "wall");
                    break;
                // top right angled red half wall
                case 124:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "outside_2", "wall");
                    break;
                // bottom left angled red half wall
                case 125:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "outside_3", "wall");
                    break;
                // bottom right angled red half wall
                case 126:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "outside_4", "wall");
                    break;
                // bottom right angled stone half wall
                case 127:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "stone_half_wall_bottom-right-corner", "wall");
                    break;
                // top right angled stone half wall
                case 128:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "stone_half_wall_top-right-corner", "wall");
                    break; 
                // top left angled stone half wall
                case 129:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "stone_half_wall_top-left-corner", "wall");
                    break; 
                // bottom left angled stone half wall
                case 130:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "stone_half_wall_bottom-left-corner", "wall");
                    break;
                // top half stone wall
                case 131:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "stone_half_wall_top", "wall");
                    break;
                // left half stone wall
                case 132:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "stone_half_wall_left", "wall");
                    break;
                // bottom half stone wall
                case 133:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "stone_half_wall_bottom", "wall");
                    break;
                // right half stone wall
                case 134:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "stone_half_wall_right", "wall");
                    break;
                // top left angled red stone wall
                case 135:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "stone_half_wall_top-left", "wall");
                    break;
                // top right angled red stone wall
                case 136:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "stone_half_wall_top-right", "wall");
                    break;
                // bottom left angled red stone wall
                case 137:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "stone_half_wall_bottom-left", "wall");
                    break;
                // bottom right angled red stone wall
                case 138:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "stone_half_wall_bottom-right", "wall");
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

void Level::BuildLevelTile(std::shared_ptr<spic::Scene> scene, std::shared_ptr<spic::GameObject> tileObject, std::shared_ptr<spic::Sprite> tileSprite, spic::Transform transform, int x, int y, const std::string& spriteName, const std::string& tag) {
    std::string basePath = "assets/images/foregrounds/" + spriteName;
    if (tag != "") {
        tileObject->AddTag(tag);
    }
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
                    sprite->SetSprite("assets/player_pistol_silenced.png");
                    sprite->SetPlayerBool(true);

                    transfrom.position.x = std::get<0>(position);
                    transfrom.position.y = std::get<1>(position);
                    transfrom.scale = 0.65;
                    std::shared_ptr<Player> player = std::make_shared<Player>(engine);
                    playerObject->AddComponent(player);
                    playerObject->setTransform(&transfrom);

                    std::shared_ptr<ChangeSceneBehaviour> gameOverScript = std::make_shared<ChangeSceneBehaviour>("GameOverScript", "GameOverMenu", engine);
                    playerObject->AddComponent(gameOverScript);

                    std::shared_ptr<ChangeSceneBehaviour> cheatsMenuScript = std::make_shared<ChangeSceneBehaviour>("CheatsMenuScript", "CheatsMenu", engine);
                    playerObject->AddComponent(cheatsMenuScript);

                    std::shared_ptr<spic::BoxCollider> boxCollider = std::make_shared<spic::BoxCollider>();
                    boxCollider->Height(55);
                    boxCollider->ShowBoxBool(true);
                    boxCollider->SetPlayerBool(true);

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
                    GreenGuardObject->AddTag("green");
                    GreenGuardObject->AddTag("guard");


                    scene->AddGameObject(GreenGuardObject);
                    spic::Transform transfrom = *GreenGuardObject->getTransform();

                    transfrom.position.x = std::get<0>(position);
                    transfrom.position.y = std::get<1>(position);
                    transfrom.scale = 0.65;

                    std::shared_ptr<Enemy> enemy = std::make_shared<Enemy>();
                    enemy->setHealthpoints(100);
                    enemy->setSpeed(1.5);
                    enemy->setDamagePerBullet(40);
                    GreenGuardObject->AddComponent(enemy);
                    enemy->setPath("assets/enemy_green.bmp");
                    std::shared_ptr<spic::BoxCollider> boxCollider = std::make_shared<spic::BoxCollider>();
                    boxCollider->Height(58);
                    boxCollider->Width(50);
                    boxCollider->ShowBoxBool(true);

                    GreenGuardObject->AddComponent(boxCollider);
                    GreenGuardObject->AddComponent(sprite);
                    sprite->SetSprite(enemy->getPath());
                    
                    GreenGuardObject->setTransform(&transfrom);
                    enemy->OnStart();

                }
            } 

        }

        if (get_value<std::string>("name", object) == "RedGuard") {

            for (std::pair<std::string, std::any> value : object) {

                if (value.first._Equal("position")) {
                    std::tuple<int, int> position = std::any_cast<std::tuple<int, int>>(value.second);

                    std::shared_ptr<spic::GameObject> RedGuardObject = std::make_shared<spic::GameObject>("GreenGuard");
                    RedGuardObject->AddTag("red");
                    RedGuardObject->AddTag("guard");

                    scene->AddGameObject(RedGuardObject);
                    spic::Transform transfrom = *RedGuardObject->getTransform();

                    transfrom.position.x = std::get<0>(position);
                    transfrom.position.y = std::get<1>(position);
                    transfrom.scale = 0.65;

                    std::shared_ptr<Enemy> enemy = std::make_shared<Enemy>();
                    enemy->setHealthpoints(75);
                    enemy->setSpeed(2.5);
                    enemy->setDamagePerBullet(50);
                    RedGuardObject->AddComponent(enemy);
                    enemy->setPath("assets/enemy_red.bmp");

                    std::shared_ptr<spic::BoxCollider> boxCollider = std::make_shared<spic::BoxCollider>();
                    boxCollider->Height(58);
                    boxCollider->Width(50);
                    boxCollider->ShowBoxBool(true);
                    RedGuardObject->AddComponent(boxCollider);
                    RedGuardObject->AddComponent(sprite);
                    sprite->SetSprite(enemy->getPath());
                    RedGuardObject->setTransform(&transfrom);
                    enemy->OnStart();
                }
            }

        }

        if (get_value<std::string>("name", object) == "BlueGuard") {

            for (std::pair<std::string, std::any> value : object) {

                if (value.first._Equal("position")) {
                    std::tuple<int, int> position = std::any_cast<std::tuple<int, int>>(value.second);

                    std::shared_ptr<spic::GameObject> BlueGuardObject = std::make_shared<spic::GameObject>("GreenGuard");
                    BlueGuardObject->AddTag("blue");
                    BlueGuardObject->AddTag("guard");

                    scene->AddGameObject(BlueGuardObject);
                    spic::Transform transfrom = *BlueGuardObject->getTransform();

                    transfrom.position.x = std::get<0>(position);
                    transfrom.position.y = std::get<1>(position);
                    transfrom.scale = 0.65;

                    std::shared_ptr<Enemy> enemy = std::make_shared<Enemy>();
                    enemy->setHealthpoints(150);
                    enemy->setSpeed(1.5);
                    enemy->setDamagePerBullet(50);
                    BlueGuardObject->AddComponent(enemy);
                    enemy->setPath("assets/enemy_blue.bmp");

                    BlueGuardObject->AddComponent(sprite);
                    sprite->SetSprite(enemy->getPath());
                    BlueGuardObject->setTransform(&transfrom);
                    enemy->OnStart();
                }
                
            }
            
        }
    }

}
