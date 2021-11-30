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
#include "Scenes/GameOverSceneBuilder.hpp"
#include "Behaviourscript/InputScript.hpp"

namespace fs = std::filesystem;

int main() {

    spic::Engine* engine = new spic::Engine();

    engine->CreateNewWindow("Tactical Stealth");
  
    std::shared_ptr<MainMenuBuilder> mainMenuBuilder = std::make_shared<MainMenuBuilder>();
    std::shared_ptr<spic::Scene> mainMenu = mainMenuBuilder->BuildScene();

    engine->AddScene(mainMenu);
    mainMenuBuilder->BuildScript(engine);

    std::shared_ptr<LevelSceneBuilder> levelSceneBuilder = std::make_shared<LevelSceneBuilder>();

    std::shared_ptr<spic::GameObject> InputObject1 = std::make_shared<spic::GameObject>("Input");
    std::shared_ptr<InputScript> inputScript1 = std::make_shared<InputScript>();
    InputObject1->AddComponent(inputScript1);

    std::shared_ptr<spic::Scene> level1Scene = levelSceneBuilder->BuildLevelScene(engine, 1);
    level1Scene->AddGameObject(InputObject1);
    engine->AddScene(level1Scene);

    std::shared_ptr<spic::GameObject> InputObject2 = std::make_shared<spic::GameObject>("Input");
    std::shared_ptr<InputScript> inputScript2 = std::make_shared<InputScript>();
    InputObject2->AddComponent(inputScript2);

    std::shared_ptr<spic::Scene> level2Scene = levelSceneBuilder->BuildLevelScene(engine, 2);
    level2Scene->AddGameObject(InputObject2);
    engine->AddScene(level2Scene);

    std::shared_ptr<spic::GameObject> InputObject3 = std::make_shared<spic::GameObject>("Input");
    std::shared_ptr<InputScript> inputScript3 = std::make_shared<InputScript>();
    InputObject3->AddComponent(inputScript3);

    std::shared_ptr<spic::Scene> level3Scene = levelSceneBuilder->BuildLevelScene(engine, 3);
    level3Scene->AddGameObject(InputObject3);
    engine->AddScene(level3Scene);

    std::shared_ptr<GameOverBuilder> gameOverSceneBuilder = std::make_shared<GameOverBuilder>();
    std::shared_ptr<spic::Scene> gameOverScene = gameOverSceneBuilder->BuildScene();
    engine->AddScene(gameOverScene);
    gameOverSceneBuilder->BuildScript(engine);

    engine->SetActiveScene(mainMenu);
    engine->SetGameLoopTimeScale(0);
    engine->StartGameLoop();

    //_CrtDumpMemoryLeaks();
}