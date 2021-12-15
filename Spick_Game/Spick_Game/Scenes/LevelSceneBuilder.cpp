#include "LevelSceneBuilder.hpp"
#include "../Behaviourscripts/ReturnToMainMenuBehaviour.hpp"

std::shared_ptr<spic::Scene> LevelSceneBuilder::BuildLevelScene(int levelNumber) {
   
    std::shared_ptr<LevelController> level = std::make_shared<LevelController>();
    std::string levelString = std::to_string(levelNumber);
    std::shared_ptr<spic::Scene> GameScene = std::make_shared<spic::Scene>("level" + levelString);

    std::string path = "assets/levels/level" + levelString + ".json";
    level->BuildLevel(GameScene, path);

    std::unique_ptr<spic::Camera> camera = std::make_unique<spic::Camera>("mainCamera");
    camera->setAspectWidth(EngineController::GetInstance()->GetScreenWidth());
    camera->setAspectHeight(EngineController::GetInstance()->GetScreenHeight());
    camera->setX(0);
    camera->setY(0);
    camera->CreateCamera();

    GameScene->AddCamera(*camera);
    GameScene->SetActiveCamera("mainCamera");

    spic::Color textColor = spic::Color(1.0, 1.0, 1.0, 1.0);
    std::shared_ptr<spic::Text> hp = std::make_shared<spic::Text>("", "Capsmall", 30, textColor, (camera->getAspectWidth() - camera->getAspectWidth()), 0);
    hp->SetName("hp");
    std::shared_ptr<spic::Text> magazine = std::make_shared<spic::Text>("", "Capsmall", 30, textColor, ((camera->getAspectWidth() - camera->getAspectWidth()) + 175), 0);
    magazine->SetName("Magazine");
    std::shared_ptr<spic::Text> cheats = std::make_shared<spic::Text>("", "Capsmall", 30, textColor, (camera->getAspectWidth() - 600), 0);
    cheats->SetName("cheats");
    std::shared_ptr<spic::Text> fps = std::make_shared<spic::Text>("", "Capsmall", 30, textColor, (camera->getAspectWidth() - 125), 0);
    fps->SetName("fps");
    std::shared_ptr<spic::Text> paused = std::make_shared<spic::Text>("PAUSED", "Capsmall", 140, textColor, (camera->getAspectWidth() / 2.9), 175);
    paused->SetName("paused");
    paused->SetActive(false);
    std::shared_ptr<spic::Button> BackToMenu = std::make_shared<spic::Button>("mainmenubutton", (camera->getAspectWidth() - 500), (camera->getAspectHeight() - 200), 367, 105, "BackToMenuScript");
    std::shared_ptr<ReturnToMainMenuBehaviour> BackToMenuScript = std::make_shared<ReturnToMainMenuBehaviour>("BackToMenuScript");
    BackToMenu->AddComponent(BackToMenuScript);
    BackToMenu->SetName("paused");
    BackToMenu->SetActive(false);
    GameScene->AddGameObject(hp);
    GameScene->AddGameObject(magazine);
    GameScene->AddGameObject(cheats);
    GameScene->AddGameObject(fps);
    GameScene->AddGameObject(paused);
    GameScene->AddGameObject(BackToMenu);

    std::shared_ptr<HUD> Hud = std::make_shared<HUD>();
    std::shared_ptr<spic::GameObject> HudObject = std::make_shared<spic::GameObject>();
    HudObject->SetName("hud");
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
