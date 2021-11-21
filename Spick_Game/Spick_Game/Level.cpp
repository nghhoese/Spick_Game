#include "Level.hpp"

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
                    transform.position.y = (double)y * 64;
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
    for (std::pair<std::string, std::any> value : object) {

    }
}
