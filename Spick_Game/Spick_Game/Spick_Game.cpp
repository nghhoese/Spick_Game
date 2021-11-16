// Spick_Game.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#define SDL_MAIN_HANDLED
#include "API_Headers/Scene.hpp"
#include "API_Headers/Sprite.hpp"
#include "Player.hpp"

int main()
{
    //spic::Scene* scene = new spic::Scene("test");


  

    std::shared_ptr<spic::GameObject> gameObject = std::make_shared<spic::GameObject>("lol");

    std::shared_ptr<spic::Scene> scene = std::make_shared<spic::Scene>("lol");
    scene->AddGameObject(gameObject);
    gameObject->SetScene(scene);
    std::shared_ptr < spic::Sprite> sprite = std::make_shared<spic::Sprite>();
    gameObject->AddComponent(sprite);
    sprite->SetGameObject(gameObject.get());
    sprite->SetSprite("C:\\Users\\Gebruiker\\Downloads\\player_sub-machinegun.bmp");
    scene->Render();
    

    



   
    while (true) {
        
    }







}
