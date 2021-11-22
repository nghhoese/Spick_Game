// Spick_Game.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#define SDL_MAIN_HANDLED
#include "API_Headers/Scene.hpp"
#include "API_Headers/Engine.hpp"
#include "API_Headers/Camera.hpp"
#include "API_Headers/Sprite.hpp"
#include "API_Headers/Transform.hpp"
#include "Player.hpp"
#include "Level.hpp"
#include "API_Headers/Rectangle.hpp"

namespace fs = std::filesystem;

int main()
{
    std::shared_ptr<spic::Scene> scene = std::make_shared<spic::Scene>("test");

    const std::string& path = "assets/levels/level1.json";
    std::shared_ptr<Level> level = std::make_shared<Level>();
    level->BuildLevel(scene, path);

    spic::Camera* camera = new spic::Camera("mainCamera");
    camera->setAspectWidth(800);
    camera->setAspectHeight(640);
    camera->setX(0);
    camera->setY(0);
    camera->createRectangle();
    spic::Rectangle rectangle = camera->getRectangle();


    spic::Engine* engine = new spic::Engine();
    engine->AddScene(scene);
    engine->SetActiveScene(scene);
    engine->StartGameLoop();

}
