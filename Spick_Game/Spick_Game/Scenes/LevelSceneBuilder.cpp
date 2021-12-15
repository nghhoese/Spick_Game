#include "LevelSceneBuilder.hpp"
#include "../Behaviourscripts/ReturnToMainMenuBehaviour.hpp"

std::shared_ptr<spic::Scene> LevelSceneBuilder::BuildLevelScene(int levelNumber) {
   
    std::shared_ptr<LevelController> level = std::make_shared<LevelController>();
    std::string levelString = std::to_string(levelNumber);
    std::shared_ptr<spic::Scene> GameScene = std::make_shared<spic::Scene>("level" + levelString);

    std::string path = "assets/levels/level" + levelString + ".json";
    level->BuildLevel(GameScene, path);

    std::unique_ptr<spic::Camera> camera = std::make_unique<spic::Camera>("mainCamera");
    camera->setAspectWidth(1920);
    camera->setAspectHeight(1080);
    camera->setX(0);
    camera->setY(0);
    camera->CreateCamera();

    GameScene->AddCamera(*camera);
    GameScene->SetActiveCamera("mainCamera");

    spic::Color textColor = spic::Color(1.0, 1.0, 1.0, 1.0);
    std::shared_ptr<spic::Text> hp = std::make_shared<spic::Text>("", "Capsmall", 30, textColor, 0, 0);
    hp->AddTag("hp");
    std::shared_ptr<spic::Text> magazine = std::make_shared<spic::Text>("", "Capsmall", 30, textColor, 175, 0);
    magazine->AddTag("Magazine");
    std::shared_ptr<spic::Text> cheats = std::make_shared<spic::Text>("", "Capsmall", 30, textColor, 1000, 0);
    cheats->AddTag("cheats");
    std::shared_ptr<spic::Text> fps = std::make_shared<spic::Text>("", "Capsmall", 30, textColor, 1800, 0);
    fps->AddTag("fps");
    std::shared_ptr<spic::Text> paused = std::make_shared<spic::Text>("PAUSED", "Capsmall", 140, textColor, 700, 175);
    paused->AddTag("paused");
    paused->SetActive(false);
    std::shared_ptr<spic::Button> BackToMenu = std::make_shared<spic::Button>("mainmenubutton", 1500, 870, 367, 105, "BackToMenuScript");
    std::shared_ptr<ReturnToMainMenuBehaviour> BackToMenuScript = std::make_shared<ReturnToMainMenuBehaviour>("BackToMenuScript");
    BackToMenu->AddComponent(BackToMenuScript);
    BackToMenu->AddTag("paused");
    BackToMenu->SetActive(false);
    GameScene->AddGameObject(hp);
    GameScene->AddGameObject(magazine);
    GameScene->AddGameObject(cheats);
    GameScene->AddGameObject(fps);
    GameScene->AddGameObject(paused);
    GameScene->AddGameObject(BackToMenu);

    std::shared_ptr<HUD> Hud = std::make_shared<HUD>();
    std::shared_ptr<spic::GameObject> HudObject = std::make_shared<spic::GameObject>();
    HudObject->AddTag("hud");
    HudObject->AddComponent(Hud);
    GameScene->AddGameObject(HudObject);

    return GameScene;
}

void LevelSceneBuilder::BuildLevel(int levelNumber) {
    std::shared_ptr<spic::GameObject> InputObject = std::make_shared<spic::GameObject>("Input");
    std::shared_ptr<InputScript> inputScript = std::make_shared<InputScript>();
    InputObject->AddComponent(inputScript);

    std::shared_ptr<spic::Scene> levelScene = BuildLevelScene(levelNumber);
    levelScene->AddGameObject(InputObject);
    EngineController::GetInstance()->AddScene(levelScene);
}
