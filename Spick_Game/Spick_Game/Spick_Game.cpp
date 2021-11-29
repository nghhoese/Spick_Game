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
#include "Scenes/MainMenuBuilder.hpp"
#include "Scenes/LevelSceneBuilder.hpp"

namespace fs = std::filesystem;

int main()
{
    std::shared_ptr<spic::Scene> GameScene = std::make_shared<spic::Scene>("GameScene");

    const std::string& path = "assets/levels/level1.json";
    std::shared_ptr<Level> level = std::make_shared<Level>();
    level->BuildLevel(GameScene, path);
    
    spic::Camera* camera = new spic::Camera("mainCamera");
    camera->setAspectWidth(1536);
    camera->setAspectHeight(1536);
    camera->setX(0);
    camera->setY(0);
    camera->CreateCamera();

    GameScene->AddCamera(*camera);
    GameScene->SetActiveCamera("mainCamera");

    spic::Engine* engine = new spic::Engine();

    engine->CreateNewWindow("yolo");
  
    //non game
    std::shared_ptr<MainMenuBuilder> mainMenuBuilder = std::make_shared<MainMenuBuilder>();
    std::shared_ptr<spic::Scene> mainMenu = mainMenuBuilder->BuildScene();

    engine->AddScene(mainMenu);
    mainMenuBuilder->BuildScript(engine);

    std::shared_ptr<LevelSceneBuilder> levelSceneBuilder = std::make_shared<LevelSceneBuilder>();

    std::shared_ptr<spic::Scene> level1Scene = levelSceneBuilder->BuildLevelScene(engine, 1);
    engine->AddScene(level1Scene);

    std::shared_ptr<spic::Scene> level2Scene = levelSceneBuilder->BuildLevelScene(engine, 2);
    engine->AddScene(level2Scene);

    std::shared_ptr<spic::Scene> level3Scene = levelSceneBuilder->BuildLevelScene(engine, 3);
    engine->AddScene(level3Scene);

    engine->SetActiveScene(mainMenu);
    engine->StartGameLoop();
}