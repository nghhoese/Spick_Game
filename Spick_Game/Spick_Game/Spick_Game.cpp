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
#include "Scenes/PlaySceneBuilderr.hpp"

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

    //std::shared_ptr<HUD> hud = std::make_shared<HUD>(engine);

    spic::Color textColor = spic::Color(1.0, 1.0, 1.0, 1.0);
    std::shared_ptr<spic::Text> fps = std::make_shared<spic::Text>("FPS: " + std::to_string(engine->GetFPS()), "Capsmall", 30, textColor, 0, 0);
    fps->AddTag("fps");
    std::shared_ptr<spic::Text> hp = std::make_shared<spic::Text>("Health: 0", "Capsmall", 30, textColor, 150, 0);
    hp->AddTag("hp");
    std::shared_ptr<spic::Text> coins = std::make_shared<spic::Text>("Coins: 0", "Capsmall", 30, textColor, 350, 0);
    coins->AddTag("coins");

    GameScene->AddGameObject(fps);
    GameScene->AddGameObject(hp);
    GameScene->AddGameObject(coins);

    engine->CreateNewWindow("yolo");
    engine->AddScene(GameScene);
    engine->CreateNewWindow("yolo");
    
    //non game
    std::shared_ptr<MainMenuBuilder> mainMenuBUilder = std::make_shared<MainMenuBuilder>();
    std::shared_ptr<spic::Scene> mainMenu = mainMenuBUilder->BuildScene();

    engine->AddScene(mainMenu);
    mainMenuBUilder->BuildScript(engine);


    std::shared_ptr<PlaySceneBuilder> playSceneBuilder = std::make_shared<PlaySceneBuilder>();
    std::shared_ptr<spic::Scene> playScene = playSceneBuilder->BuildScene();
    engine->AddScene(playScene);

    engine->SetActiveScene(mainMenu);
    engine->StartGameLoop();

}