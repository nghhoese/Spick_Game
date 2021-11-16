// Spick_Game.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#define SDL_MAIN_HANDLED
#include "API_Headers/Scene.hpp"
#include "API_Headers/Sprite.hpp"
#include "Player.hpp"

int main()
{
    //spic::Scene* scene = new spic::Scene("test");
    std::unique_ptr<Player> player = std::make_unique<Player>();

    std::unique_ptr<spic::GameObject> gameObject = std::make_unique<spic::GameObject>("lol");

    std::shared_ptr<spic::Scene> scene = std::make_shared<spic::Scene>("lol");

    gameObject->SetScene(scene);

    spic::Sprite* sprite = new spic::Sprite();
    sprite->SetGameObject(gameObject.get());

    
    while (true) {
        player->checkKeys();
        player->checkMouseButtons();
        player->checkMousePosition();

    }
}
