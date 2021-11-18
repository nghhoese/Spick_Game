// Spick_Game.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#define SDL_MAIN_HANDLED
#include "API_Headers/Scene.hpp"
#include "API_Headers/Engine.hpp"
#include "API_Headers/Sprite.hpp"
#include "API_Headers/Transform.hpp"
#include "Player.hpp"
#include <API_Headers/Text.hpp>
#include <API_Headers/Button.hpp>

int main()
{
    /*std::shared_ptr<spic::GameObject> playerObject = std::make_shared<spic::GameObject>("Player");
    std::shared_ptr<spic::Scene> scene = std::make_shared<spic::Scene>("test");
    std::shared_ptr<spic::Sprite> sprite = std::make_shared<spic::Sprite>();

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

    //addText

    spic::Color textColor = spic::Color(0.0, 0.0, 0.0, 1.0);
    std::shared_ptr<spic::Text> text = std::make_shared<spic::Text>("Advanced Stealth", "TopSecret", 30, textColor, 10, 50);

    scene->AddGameObject(text);*/

    std::shared_ptr<spic::Scene> scene = std::make_shared<spic::Scene>("test");

    //std::shared_ptr<spic::Button> button = std::make_shared<spic::Button>("button", 40, 40, 50, 50);*/
    //scene->AddGameObject(button);


    std::shared_ptr<spic::GameObject> background = std::make_shared<spic::GameObject>("Background");
    std::shared_ptr<spic::Sprite> sprite = std::make_shared<spic::Sprite>();
    scene->AddGameObject(background);
    spic::Transform transfrom = *background->getTransform();
    background->AddComponent(sprite);
    sprite->SetSprite("assets/menu.png");

    transfrom.position.x = 0;
    transfrom.position.y = 0;
    transfrom.scale = 1;

    background->setTransform(&transfrom);

    std::shared_ptr<spic::Button> buttonPlay = std::make_shared<spic::Button>("button", 314, 165, 72, 134);
    scene->AddGameObject(buttonPlay);

    
    spic::Engine* engine = new spic::Engine();
    engine->AddScene(scene);
    engine->SetActiveScene(scene);
    engine->StartGameLoop();


}
