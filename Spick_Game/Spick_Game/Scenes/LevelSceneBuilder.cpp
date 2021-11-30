#include "LevelSceneBuilder.hpp"

std::shared_ptr<spic::Scene> LevelSceneBuilder::BuildLevelScene(spic::Engine* engine, int levelNumber) {
   
    std::shared_ptr<Level> level = std::make_shared<Level>(engine);
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
    std::shared_ptr<spic::Text> hp = std::make_shared<spic::Text>("Health: 0", "Capsmall", 30, textColor, 0, 0);
    hp->AddTag("hp");
    std::shared_ptr<spic::Text> coins = std::make_shared<spic::Text>("Coins: 0", "Capsmall", 30, textColor, 175, 0);
    coins->AddTag("coins");
    std::shared_ptr<spic::Text> fps = std::make_shared<spic::Text>("", "Capsmall", 30, textColor, 870, 0);
    fps->AddTag("fps");

    GameScene->AddGameObject(hp);
    GameScene->AddGameObject(coins);
    GameScene->AddGameObject(fps);

    return GameScene;
}