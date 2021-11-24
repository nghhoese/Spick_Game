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
#include "API_Headers/Text.hpp"
#include "HUD.hpp"

namespace fs = std::filesystem;

int main()
{
    std::shared_ptr<spic::Scene> scene = std::make_shared<spic::Scene>("test");

    const std::string& path = "assets/levels/level1.json";
    std::shared_ptr<Level> level = std::make_shared<Level>();
    level->BuildLevel(scene, path);

    spic::Camera* camera = new spic::Camera("mainCamera");
    camera->setAspectWidth(1536);
    camera->setAspectHeight(1536);
    camera->setX(0);
    camera->setY(0);
    camera->CreateCamera();

    scene->AddCamera(*camera);
    scene->SetActiveCamera("mainCamera");

    spic::Engine* engine = new spic::Engine();

    //std::shared_ptr<HUD> hud = std::make_shared<HUD>(engine);

    spic::Color textColor = spic::Color(1.0, 1.0, 1.0, 1.0);
    std::shared_ptr<spic::Text> fps = std::make_shared<spic::Text>("FPS: " + std::to_string(engine->GetFPS()), "Capsmall", 30, textColor, 0, 0);
    fps->AddTag("fps");
    std::shared_ptr<spic::Text> hp = std::make_shared<spic::Text>("Health: 0", "Capsmall", 30, textColor, 150, 0);
    hp->AddTag("hp");
    std::shared_ptr<spic::Text> coins = std::make_shared<spic::Text>("Coins: 0", "Capsmall", 30, textColor, 350, 0);
    coins->AddTag("coins");

    scene->AddGameObject(fps);
    scene->AddGameObject(hp);
    scene->AddGameObject(coins);

    engine->CreateNewWindow("yolo");
    engine->AddScene(scene);
    engine->SetActiveScene(scene);
    engine->StartGameLoop();

}
