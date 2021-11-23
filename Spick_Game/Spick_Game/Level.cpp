#include "Level.hpp"
#include "Player.hpp"

Level::Level()
{
    engine = new spic::Engine();
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
                if (x == level_height) {
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

                // red wall
                case 34:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "red-wall");
                    break;

                // red wall
                case 36:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "red-nazi-wall");
                    break;

                // left half red wall
                case 115:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "half_1");
                    break;

                // top red half wall
                case 116:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "half_2");
                    break;

                // right half red wall
                case 117:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "half_3");
                    break;

                // bottom half red wall
                case 118:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "half_4");
                    break;

                // top left corner red half wall
                case 119:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "inside_1");
                    break;

                // bottom left corner red half wall
                case 120:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "inside_2");
                    break;

                // top right red wall
                case 121:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "inside_3");
                    break;

                // bottom right corner red half wall
                case 122:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "inside_4");
                    break;

                // top right angled red half wall
                case 123:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "outside_1");
                    break;

                    // top right angled red half wall
                case 124:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "outside_2");
                    break;

                // top right angled red half wall
                case 125:
                    BuildLevelTile(scene, tileObject, tileSprite, transform, x, y, "outside_3");
                    break;

                    // top right angled red half wall
                case 126:
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

    if (std::filesystem::exists(basePath + bmpFileString)) {
        tileSprite->SetSprite(basePath + bmpFileString);
    }
    else if (std::filesystem::exists(basePath + pngFileString)){
        tileSprite->SetSprite(basePath + pngFileString);
    }

    transform.position.x = (double)x * xTilesize;
    transform.position.y = (double)y * yTilesize;
    transform.scale = 1;
    tileObject->setTransform(&transform);
}

void Level::BuildLevelObjects(std::shared_ptr<spic::Scene> scene, std::vector<std::pair<std::string, std::any>> object){

    if (get_value<std::string>("type", object) == "Waypoint") {

        if (get_value<std::string>("name", object) == "StartPoint") {

            for (std::pair<std::string, std::any> value : object) {
                if (value.first._Equal("position")) {
                    std::tuple<int, int> position = std::any_cast<std::tuple<int, int>>(value.second);

                    std::shared_ptr<spic::GameObject> playerObject = std::make_shared<spic::GameObject>("Player");
                    std::shared_ptr<spic::Sprite> sprite = std::make_shared<spic::Sprite>();

                    scene->AddGameObject(playerObject);
                    spic::Transform transfrom = *playerObject->getTransform();
                    playerObject->AddComponent(sprite);
                    sprite->SetSprite("assets/player_sub-machinegun.bmp");
                    transfrom.position.x = std::get<0>(position);
                    transfrom.position.y = std::get<1>(position);
                    transfrom.scale = 0.75;
                    std::shared_ptr<Player> player = std::make_shared<Player>();
                    playerObject->AddComponent(player);
                    playerObject->setTransform(&transfrom);
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
                }
            }
        }
    }

    if (get_value<std::string>("type", object) == "Enemy") {

        if (get_value<std::string>("name", object) == "GreenGuard") {

            for (std::pair<std::string, std::any> value : object) {

                if (value.first._Equal("position")) {
                    std::tuple<int, int> position = std::any_cast<std::tuple<int, int>>(value.second);
                }
            }

        }

        if (get_value<std::string>("name", object) == "RedGuard") {

            for (std::pair<std::string, std::any> value : object) {

                if (value.first._Equal("position")) {
                    std::tuple<int, int> position = std::any_cast<std::tuple<int, int>>(value.second);
                }
            }

        }

        if (get_value<std::string>("name", object) == "BlueGuard") {

            for (std::pair<std::string, std::any> value : object) {

                if (value.first._Equal("position")) {
                    std::tuple<int, int> position = std::any_cast<std::tuple<int, int>>(value.second);
                }
            }

        }
    }

}
