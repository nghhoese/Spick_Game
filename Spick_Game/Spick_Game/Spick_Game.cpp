// Spick_Game.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "API_Headers/Scene.hpp"
#include "Player.hpp"

int main()
{
    spic::Scene* scene = new spic::Scene("test");

    std::unique_ptr<Player> player = std::make_unique<Player>();
    
    while (true) {
        player->checkKeys();
        player->checkMouseButtons();
        player->checkMousePosition();
    }
}
