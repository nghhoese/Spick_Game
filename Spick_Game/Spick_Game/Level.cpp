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
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "dark-vent", "");
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
    else {
        tileSprite->SetSprite("assets/images/foregrounds/error.png");
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

                    playerObject->AddComponent(sprite);
                    sprite->SetSprite("assets/player_pistol_silenced.png");
                    sprite->SetPlayerBool(true);

                    BuildLevelObjectPosition(playerObject, position);

                    std::shared_ptr<Player> player = std::make_shared<Player>(engine);
                    playerObject->AddComponent(player);

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
                    BuildLevelObjectPosition(endPointObject, position);
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
                    BuildLevelEnemy(scene, sprite, position, "enemy_green.bmp", "green", "guard", 100, 1.5, 40);
                }
            } 
        }
        if (get_value<std::string>("name", object) == "RedGuard") {
            for (std::pair<std::string, std::any> value : object) {
                if (value.first._Equal("position")) {
                    std::tuple<int, int> position = std::any_cast<std::tuple<int, int>>(value.second);
                    BuildLevelEnemy(scene, sprite, position, "enemy_red.bmp", "red", "guard", 75, 2.5, 50);
                }
            }
      }
        if (get_value<std::string>("name", object) == "BlueGuard") {
            for (std::pair<std::string, std::any> value : object) {
                if (value.first._Equal("position")) {
                    std::tuple<int, int> position = std::any_cast<std::tuple<int, int>>(value.second);
                    BuildLevelEnemy(scene, sprite, position, "enemy_blue.bmp", "blue", "guard", 150, 1.5, 50);
                }             
            }          
        }
    }

}

void Level::BuildLevelEnemy(std::shared_ptr<spic::Scene> scene, std::shared_ptr<spic::Sprite> sprite, std::tuple<int, int> position, const std::string& spriteName, const std::string& colourTag, const std::string& typeTag, int healthPoints, double speed, int damage) {
    std::shared_ptr<spic::GameObject> guardObject = std::make_shared<spic::GameObject>("Guard");
    guardObject->AddTag(colourTag);
    guardObject->AddTag(typeTag);
    scene->AddGameObject(guardObject);

    BuildLevelObjectPosition(guardObject, position);

    std::shared_ptr<Enemy> enemy = std::make_shared<Enemy>();
    enemy->setHealthpoints(healthPoints);
    enemy->setSpeed(speed);
    enemy->setDamagePerBullet(damage);
    guardObject->AddComponent(enemy);
    enemy->setPath("assets/" + spriteName);

    std::shared_ptr<spic::BoxCollider> boxCollider = std::make_shared<spic::BoxCollider>();
    boxCollider->Height(58);
    boxCollider->Width(50);
    boxCollider->ShowBoxBool(true);
    guardObject->AddComponent(boxCollider);
    guardObject->AddComponent(sprite);
    sprite->SetSprite(enemy->getPath());
    enemy->OnStart();
}

void Level::BuildLevelObjectPosition(std::shared_ptr<spic::GameObject> object, std::tuple<int, int> position) {
    spic::Transform transfrom = *object->getTransform();
    transfrom.position.x = std::get<0>(position);
    transfrom.position.y = std::get<1>(position);
    transfrom.scale = 0.65;
    object->setTransform(&transfrom);
}
