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
#include "Scenes/CheatsMenuBuilder.hpp"
#include "Scenes/HelpSceneBuilder.hpp"
#include "Scenes/CreditsSceneBuilder.hpp"

namespace fs = std::filesystem;

int main() {

    spic::Engine* engine = new spic::Engine();

    engine->CreateNewWindow("Tactical Stealth");
  
    std::shared_ptr<MainMenuBuilder> mainMenuBuilder = std::make_shared<MainMenuBuilder>();
    std::shared_ptr<spic::Scene> mainMenu = mainMenuBuilder->BuildScene();

    engine->AddScene(mainMenu);
    mainMenuBuilder->BuildScript(engine);

    std::shared_ptr<HelpSceneBuilder> helpSceneBuilder = std::make_shared<HelpSceneBuilder>();
    std::shared_ptr<spic::Scene> helpScene = helpSceneBuilder->BuildScene();
    engine->AddScene(helpScene);
    helpSceneBuilder->BuildScript(engine);

    std::shared_ptr<CreditsSceneBuilder> creditsSceneBuilder = std::make_shared<CreditsSceneBuilder>();
    std::shared_ptr<spic::Scene> creditsScene = creditsSceneBuilder->BuildScene();
    engine->AddScene(creditsScene);
    creditsSceneBuilder->BuildScript(engine);

    std::shared_ptr<LevelSceneBuilder> levelSceneBuilder = std::make_shared<LevelSceneBuilder>();

    levelSceneBuilder->BuildLevel(engine, 1);
    levelSceneBuilder->BuildLevel(engine, 2);
    levelSceneBuilder->BuildLevel(engine, 3);

    std::shared_ptr<GameOverBuilder> gameOverSceneBuilder = std::make_shared<GameOverBuilder>();
    std::shared_ptr<spic::Scene> gameOverScene = gameOverSceneBuilder->BuildScene();
    engine->AddScene(gameOverScene);
    gameOverSceneBuilder->BuildScript(engine);

    std::shared_ptr<CheatsMenuBuilder> cheatsMenuBuilder = std::make_shared<CheatsMenuBuilder>();
    std::shared_ptr<spic::Scene> cheatsMenuScene = cheatsMenuBuilder->BuildScene(engine);
    engine->AddScene(cheatsMenuScene);
    cheatsMenuBuilder->BuildScript(engine);

    engine->SetActiveScene(mainMenu);
    engine->StartGameLoop();

    _CrtDumpMemoryLeaks();
}