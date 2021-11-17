// Spick_Game.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#define SDL_MAIN_HANDLED
#include "API_Headers/Scene.hpp"
#include "API_Headers/Sprite.hpp"
#include "API_Headers/Transform.hpp"
#include "Player.hpp"

int main()
{

    std::shared_ptr<spic::GameObject> playerObject = std::make_shared<spic::GameObject>("Player");
    std::shared_ptr<spic::Scene> scene = std::make_shared<spic::Scene>("lol");
    std::shared_ptr<spic::Sprite> sprite = std::make_shared<spic::Sprite>();

    scene->AddGameObject(playerObject);
    spic::Transform transfrom = *playerObject->getTransform();

    playerObject->AddComponent(sprite);
    sprite->SetSprite("assets/player_sub-machinegun.bmp");
    transfrom.position.x = 1;
    transfrom.position.y = 1;

    Player player;
    player.x = transfrom.position.x;
    player.y = transfrom.position.y;

    spic::Point point;

    while (true) {

        player.checkKeys();
        transfrom.position.x = player.x;
        transfrom.position.y = player.y;

        point = player.checkMousePosition();
        double Delta_x = transfrom.position.x - point.x;
        double Delta_y = transfrom.position.y - point.y;

        double Result = (atan2(Delta_y, Delta_x) * 180.0000) / 3.14159265;
        transfrom.rotation = Result;

        playerObject->setTransform(&transfrom);
        scene->Render();
    }

}
