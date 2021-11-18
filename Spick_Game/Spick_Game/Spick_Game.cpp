// Spick_Game.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#define SDL_MAIN_HANDLED
#include "API_Headers/Scene.hpp"
#include "API_Headers/Engine.hpp"
#include "API_Headers/Sprite.hpp"
#include "API_Headers/Transform.hpp"
#include "Player.hpp"
#include "Facade_Headers/TiledFacade.hpp"

namespace fs = std::filesystem;

int main()
{
    std::shared_ptr<spic::GameObject> playerObject = std::make_shared<spic::GameObject>("Player");
    std::shared_ptr<spic::Scene> scene = std::make_shared<spic::Scene>("test");
    std::shared_ptr<spic::Sprite> sprite = std::make_shared<spic::Sprite>();


    std::shared_ptr<spic::TiledFacade> tiledFacade = std::make_shared<spic::TiledFacade>();

    //const std::string& path = "assets/levels/level1.json";
    const std::string& path = "assets/levels/testlevel.json";
    fs::path filePath = path;

    auto level_layers = tiledFacade->Read(filePath);

    std::vector<std::pair<int, std::vector<std::vector<int>>>> tiles = level_layers.first;
    std::vector<std::vector<std::pair<std::string, std::any>>> objects = level_layers.second;

    int level_height = (tiles.at(0).second.size());
    int level_width = (tiles.at(0).second.at(0).size());


    // Tile layers
    for (std::pair<int, std::vector<std::vector<int>>> tileset : tiles) {
        // background
        if (tileset.first == 2) {
            int x = 0;
            int y = 0;
            for (std::vector<int> vector : tileset.second) {
                for (int object : vector) {

                    switch (object + 1) {
                        // background black stars 
                    case 123:
                        std::shared_ptr<spic::GameObject> backgroundObject = std::make_shared<spic::GameObject>("Background");
                        std::shared_ptr<spic::Sprite> backgroundSprite = std::make_shared<spic::Sprite>();
                        scene->AddGameObject(backgroundObject);
                        spic::Transform transform = *backgroundObject->getTransform();
                        backgroundObject->AddComponent(backgroundSprite);
                        backgroundSprite->SetSprite("assets/images/backgrounds/background.bmp");
                        transform.position.x = (double)x * 32;
                        transform.position.y = (double)y * 32;
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
        // foreground (tileset.first == 5)
        else {
            int x = 0;
            int y = 0;
            for (std::vector<int> vector : tileset.second) {
                for (int object : vector) {
                    std::shared_ptr<spic::GameObject> tileObject = std::make_shared<spic::GameObject>("tile");
                    std::shared_ptr<spic::Sprite> tileSprite = std::make_shared<spic::Sprite>();
                    spic::Transform transform = *tileObject->getTransform();
                    switch (object + 1) {
                    // bottom right corner red half wall
                    case 8:
                        scene->AddGameObject(tileObject);

                        tileObject->AddComponent(tileSprite);
                        tileSprite->SetSprite("assets/images/foregrounds/inside_4.png");
                        transform.position.x = (double)x * 64;
                        transform.position.y = (double)y * 63;
                        transform.scale = 1;
                        tileObject->setTransform(&transform);
                        break;
                    // bottom half red wall
                    case 1:
                        scene->AddGameObject(tileObject);

                        tileObject->AddComponent(tileSprite);
                        tileSprite->SetSprite("assets/images/foregrounds/half_4.png");
                        transform.position.x = (double)x * 64;
                        transform.position.y = (double)y * 63;
                        transform.scale = 1;
                        tileObject->setTransform(&transform);
                        break;
                    // bottom left corner red half wall
                    case 6:
                        scene->AddGameObject(tileObject);

                        tileObject->AddComponent(tileSprite);
                        tileSprite->SetSprite("assets/images/foregrounds/inside_2.png");
                        transform.position.x = (double)x * 64;
                        transform.position.y = (double)y * 63;
                        transform.scale = 1;
                        tileObject->setTransform(&transform);
                        break;
                    // right half red wall
                    case 4:
                        scene->AddGameObject(tileObject);

                        tileObject->AddComponent(tileSprite);
                        tileSprite->SetSprite("assets/images/foregrounds/half_3.png");
                        transform.position.x = (double)x * 64;
                        transform.position.y = (double)y * 63;
                        transform.scale = 1;
                        tileObject->setTransform(&transform);
                        break;
                    // bright wood floor
                    case 31:
                        scene->AddGameObject(tileObject);

                        tileObject->AddComponent(tileSprite);
                        tileSprite->SetSprite("assets/images/foregrounds/bright-wood-floor.bmp");
                        transform.position.x = (double)x * 64;
                        transform.position.y = (double)y * 63;
                        transform.scale = 1;
                        tileObject->setTransform(&transform);
                        break;
                    // left half red wall
                    case 2:
                        scene->AddGameObject(tileObject);

                        tileObject->AddComponent(tileSprite);
                        tileSprite->SetSprite("assets/images/foregrounds/half_1.png");
                        transform.position.x = (double)x * 64;
                        transform.position.y = (double)y * 63;
                        transform.scale = 1;
                        tileObject->setTransform(&transform);
                        break;

                    // bright wood floor
                    case 29:
                        scene->AddGameObject(tileObject);

                        tileObject->AddComponent(tileSprite);
                        tileSprite->SetSprite("assets/images/foregrounds/bright-wood-hitler-floor.bmp");
                        transform.position.x = (double)x * 64;
                        transform.position.y = (double)y * 63;
                        transform.scale = 1;
                        tileObject->setTransform(&transform);
                        break;

                    // red wall
                    case 42:
                        scene->AddGameObject(tileObject);

                        tileObject->AddComponent(tileSprite);
                        tileSprite->SetSprite("assets/images/foregrounds/red-wall.bmp");
                        transform.position.x = (double)x * 64;
                        transform.position.y = (double)y * 63;
                        transform.scale = 1;
                        tileObject->setTransform(&transform);
                        break;

                    // red nazi wall
                    case 44:
                        scene->AddGameObject(tileObject);

                        tileObject->AddComponent(tileSprite);
                        tileSprite->SetSprite("assets/images/foregrounds/red-nazi-wall.bmp");
                        transform.position.x = (double)x * 64;
                        transform.position.y = (double)y * 63;
                        transform.scale = 1;
                        tileObject->setTransform(&transform);
                        break;


                    // bright wood statue floor
                    case 28:
                        scene->AddGameObject(tileObject);

                        tileObject->AddComponent(tileSprite);
                        tileSprite->SetSprite("assets/images/foregrounds/bright-wood-statue-floor.bmp");
                        transform.position.x = (double)x * 64;
                        transform.position.y = (double)y * 63;
                        transform.scale = 1;
                        tileObject->setTransform(&transform);
                        break;

                    // top right corner red half wall
                    case 7:
                        scene->AddGameObject(tileObject);

                        tileObject->AddComponent(tileSprite);
                        tileSprite->SetSprite("assets/images/foregrounds/inside_3.png");
                        transform.position.x = (double)x * 64;
                        transform.position.y = (double)y * 63;
                        transform.scale = 1;
                        tileObject->setTransform(&transform);
                        break;

                    // top red half wall
                    case 3:
                        scene->AddGameObject(tileObject);

                        tileObject->AddComponent(tileSprite);
                        tileSprite->SetSprite("assets/images/foregrounds/half_2.png");
                        transform.position.x = (double)x * 64;
                        transform.position.y = (double)y * 63;
                        transform.scale = 1;
                        tileObject->setTransform(&transform);
                        break;

                    // top left corner red half wall
                    case 5:
                        scene->AddGameObject(tileObject);

                        tileObject->AddComponent(tileSprite);
                        tileSprite->SetSprite("assets/images/foregrounds/inside_1.png");
                        transform.position.x = (double)x * 64;
                        transform.position.y = (double)y * 63;
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

    // Object layer
    for (std::vector<std::pair<std::string, std::any>> object : objects) {
        for (std::pair<std::string, std::any> value : object) {

        }
    }


    scene->AddGameObject(playerObject);
    spic::Transform transfrom = *playerObject->getTransform();
    playerObject->AddComponent(sprite);
    sprite->SetSprite("assets/player_sub-machinegun.bmp");
    transfrom.position.x = 1;
    transfrom.position.y = 1;
    transfrom.scale = 1;
    std::shared_ptr<Player> player = std::make_shared<Player>(); 
    playerObject->AddComponent(player);
    playerObject->setTransform(&transfrom);
    spic::Engine* engine = new spic::Engine();
    engine->AddScene(scene);
    engine->SetActiveScene(scene);
    engine->StartGameLoop();

    //while (true) {

    //    
    //   scene->Render(); 

    //    std::cout << scene->CalculateFPS() << "   \r";
    //}

}
