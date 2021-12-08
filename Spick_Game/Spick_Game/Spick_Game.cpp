#define SDL_MAIN_HANDLED

#include <crtdbg.h>
#include <iostream>
#include "API_Headers/Scene.hpp"
#include "API_Headers/Engine.hpp"
#include "API_Headers/Camera.hpp"
#include "API_Headers/Sprite.hpp"
#include "API_Headers/AudioSource.hpp"
#include "API_Headers/Transform.hpp"
#include "Controllers/LevelController.hpp"
#include "API_Headers/Rectangle.hpp"
#include "API_Headers/Text.hpp"
#include "Behaviourscripts/HUD.hpp"
#include "Scenes/MainMenuBuilder.hpp"
#include "Scenes/LevelSceneBuilder.hpp"
#include "Scenes/GameOverSceneBuilder.hpp"
#include "Behaviourscripts/InputScript.hpp"
#include "Scenes/CheatsMenuBuilder.hpp"
#include "Scenes/HelpSceneBuilder.hpp"
#include "Scenes/CreditsSceneBuilder.hpp"

int main(char* argv[]) {
    try{
        EngineController::GetInstance()->CreateNewWindow("Tactical Stealth");

        std::shared_ptr<MainMenuBuilder> mainMenuBuilder = std::make_shared<MainMenuBuilder>();
        std::shared_ptr<spic::Scene> mainMenu = mainMenuBuilder->BuildScene();
        EngineController::GetInstance()->AddScene(mainMenu);

        std::shared_ptr<LevelSceneBuilder> levelSceneBuilder = std::make_shared<LevelSceneBuilder>();
        levelSceneBuilder->BuildLevel(1);
        levelSceneBuilder->BuildLevel(2);
        levelSceneBuilder->BuildLevel(3);
        std::shared_ptr<spic::GameObject> liedjevanMainMenu1 = std::make_shared<spic::GameObject>();
        EngineController::GetInstance()->GetSceneByName("level1")->AddGameObject(liedjevanMainMenu1);
        liedjevanMainMenu1->AddTag("music");
        std::shared_ptr<spic::AudioSource> liedje1 = std::make_shared<spic::AudioSource>();
        liedjevanMainMenu1->AddComponent(liedje1);
        liedje1->SetAudioClip("assets/bgmusic1.mp3");
        liedje1->SetIsMusic(true);
        std::shared_ptr<GameOverBuilder> gameOverSceneBuilder = std::make_shared<GameOverBuilder>();
        std::shared_ptr<spic::Scene> gameOverScene = gameOverSceneBuilder->BuildScene();
        EngineController::GetInstance()->AddScene(gameOverScene);
        gameOverSceneBuilder->BuildScript();

        std::shared_ptr<CheatsMenuBuilder> cheatsMenuBuilder = std::make_shared<CheatsMenuBuilder>();
        std::shared_ptr<spic::Scene> cheatsMenuScene = cheatsMenuBuilder->BuildScene();
        EngineController::GetInstance()->AddScene(cheatsMenuScene);

        std::shared_ptr<HelpSceneBuilder> helpSceneBuilder = std::make_shared<HelpSceneBuilder>();
        std::shared_ptr<spic::Scene> helpScene = helpSceneBuilder->BuildScene();
        EngineController::GetInstance()->AddScene(helpScene);

        std::shared_ptr<CreditsSceneBuilder> creditsSceneBuilder = std::make_shared<CreditsSceneBuilder>();
        std::shared_ptr<spic::Scene> creditsScene = creditsSceneBuilder->BuildScene();
        EngineController::GetInstance()->AddScene(creditsScene);

        EngineController::GetInstance()->SetActiveScene(mainMenu);
        std::shared_ptr<spic::GameObject> liedjevanMainMenu = std::make_shared<spic::GameObject>();
        mainMenu->AddGameObject(liedjevanMainMenu);
        liedjevanMainMenu->AddTag("music");
        std::shared_ptr<spic::AudioSource> liedje = std::make_shared<spic::AudioSource>();
        liedjevanMainMenu->AddComponent(liedje);
        liedje->SetAudioClip("assets/dimmadome.mp3");
        liedje->SetIsMusic(true);
        liedje->Play(true);
        EngineController::GetInstance()->StartGameLoop();
    }
    catch (const std::exception& ex) {
        std::cerr << argv[0] << ": " << ex.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...) {
        std::cerr << argv[0] << ": unknown error\n";
        return EXIT_FAILURE;
    }
    int* q = new int;
    _CrtDumpMemoryLeaks();
    return EXIT_SUCCESS;
}