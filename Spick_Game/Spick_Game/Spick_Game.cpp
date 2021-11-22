// Spick_Game.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#define SDL_MAIN_HANDLED
#include "API_Headers/Scene.hpp"
#include "API_Headers/Engine.hpp"
#include "API_Headers/Sprite.hpp"
#include "API_Headers/Transform.hpp"
#include "Player.hpp"
#include "Level.hpp"

namespace fs = std::filesystem;

int main()
{
    std::shared_ptr<spic::GameObject> playerObject = std::make_shared<spic::GameObject>("Player");
    std::shared_ptr<spic::Scene> scene = std::make_shared<spic::Scene>("test");
    std::shared_ptr<spic::Sprite> sprite = std::make_shared<spic::Sprite>();

    const std::string& path = "assets/levels/level1.json";
    std::shared_ptr<Level> level = std::make_shared<Level>();
    level->BuildLevel(scene, path);

    scene->AddGameObject(playerObject);
    spic::Transform transfrom = *playerObject->getTransform();
    playerObject->AddComponent(sprite);
    sprite->SetSprite("assets/player_sub-machinegun.bmp");
    transfrom.position.x = 1;
    transfrom.position.y = 1;
    transfrom.scale = 0.75;
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
