#include "LevelSceneBuilder.hpp"

std::shared_ptr<spic::Scene> LevelSceneBuilder::BuildLevelScene(int levelNumber) {
   
    std::shared_ptr<LevelController> level = std::make_shared<LevelController>();
    level->currentLevel = levelNumber;
    std::string levelString = std::to_string(levelNumber);
    std::shared_ptr<spic::Scene> GameScene = std::make_shared<spic::Scene>("level" + levelString);

    std::string path = "assets/levels/level" + levelString + ".json";
    level->BuildLevel(GameScene, path);

    spic::Camera* camera = new spic::Camera("mainCamera");
    camera->setAspectWidth(1536);
    camera->setAspectHeight(1536);
    camera->setX(0);
    camera->setY(0);
    camera->CreateCamera();

    GameScene->AddCamera(*camera);
    GameScene->SetActiveCamera("mainCamera");

    spic::Color textColor = spic::Color(1.0, 1.0, 1.0, 1.0);
    std::shared_ptr<spic::Text> hp = std::make_shared<spic::Text>("", "Capsmall", 30, textColor, 0, 0);
    hp->AddTag("hp");
    std::shared_ptr<spic::Text> coins = std::make_shared<spic::Text>("", "Capsmall", 30, textColor, 175, 0);
    coins->AddTag("coins");
    std::shared_ptr<spic::Text> fps = std::make_shared<spic::Text>("", "Capsmall", 30, textColor, 870, 0);
    fps->AddTag("fps");
    std::shared_ptr<spic::Text> paused = std::make_shared<spic::Text>("", "Capsmall", 140, textColor, 250, 175);
    paused->AddTag("paused");
    GameScene->AddGameObject(hp);
    GameScene->AddGameObject(coins);
    GameScene->AddGameObject(fps);
    GameScene->AddGameObject(paused);

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
