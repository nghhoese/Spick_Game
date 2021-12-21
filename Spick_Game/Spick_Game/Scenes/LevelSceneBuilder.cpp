#include "LevelSceneBuilder.hpp"

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
    spic::Color cheatsColor = spic::Color(0.0, 1.0, 0.0, 1.0);
    std::shared_ptr<spic::GameObject> Health = std::make_shared<spic::GameObject>("healthanimation");
    std::shared_ptr<spic::Animator> HealthAnnimator = std::make_shared<spic::Animator>();
    Health->AddComponent(HealthAnnimator);
    std::vector<std::shared_ptr<spic::Sprite>> sprites = {};
    std::shared_ptr<spic::Sprite> Health1 = std::make_shared<spic::Sprite>();
    Health1->SetSprite("assets/health1.png");
    Health1->SetGameObject(Health.get());
    Health1->setStill(true);
    std::shared_ptr<spic::Sprite> Health2 = std::make_shared<spic::Sprite>();
    Health2->SetSprite("assets/health2.png");
    Health2->SetGameObject(Health.get());
    Health2->setStill(true);
    std::shared_ptr<spic::Sprite> Health3 = std::make_shared<spic::Sprite>();
    Health3->SetSprite("assets/health3.png");
    Health3->SetGameObject(Health.get());
    Health3->setStill(true);
    std::shared_ptr<spic::Sprite> Health4 = std::make_shared<spic::Sprite>();
    Health4->SetSprite("assets/health4.png");
    Health4->SetGameObject(Health.get());
    Health4->setStill(true);
    std::shared_ptr<spic::Sprite> Health5 = std::make_shared<spic::Sprite>();
    Health5->SetSprite("assets/health3.png");
    Health5->SetGameObject(Health.get());
    Health5->setStill(true);
    std::shared_ptr<spic::Sprite> Health6 = std::make_shared<spic::Sprite>();
    Health6->SetSprite("assets/health2.png");
    Health6->SetGameObject(Health.get());
    Health6->setStill(true);
    std::shared_ptr<spic::Sprite> Health7 = std::make_shared<spic::Sprite>();
    Health7->SetSprite("assets/health1.png");
    Health7->SetGameObject(Health.get());
    Health7->setStill(true);

    sprites.push_back(Health1);
    sprites.push_back(Health2);
    sprites.push_back(Health3);
    sprites.push_back(Health4);
    sprites.push_back(Health5);
    sprites.push_back(Health6);
    sprites.push_back(Health7);
    HealthAnnimator->SetSprites(sprites);
    HealthAnnimator->Play(true);
    HealthAnnimator->SetFps(5);

    spic::Transform transfrom = *Health->getTransform();
    transfrom.position.x = 1;
    transfrom.position.y = 1;
    transfrom.scale = 0.08;

    Health->setTransform(&transfrom);

    std::shared_ptr<spic::Text> hp = std::make_shared<spic::Text>("", "Capsmall", 30, textColor, (camera->getAspectWidth() - camera->getAspectWidth() + 50), 0);
    hp->SetName("hp");
    std::shared_ptr<spic::Text> magazine = std::make_shared<spic::Text>("", "Capsmall", 30, textColor, ((camera->getAspectWidth() - camera->getAspectWidth()) + 225), 0);
    magazine->SetName("Magazine");
    std::shared_ptr<spic::Text> cheats = std::make_shared<spic::Text>("", "Capsmall", 30, cheatsColor, (camera->getAspectWidth() - 600), 0);
    cheats->SetName("cheats");
    std::shared_ptr<spic::Text> fps = std::make_shared<spic::Text>("", "Capsmall", 30, textColor, (camera->getAspectWidth() - 125), 0);
    fps->SetName("fps");
    std::shared_ptr<spic::Text> paused = std::make_shared<spic::Text>("PAUSED", "Capsmall", 140, textColor, (camera->getAspectWidth() / 2.9), 175);
    paused->SetName("paused");
    paused->SetActive(false);
    std::shared_ptr<spic::Button> BackToMenu = std::make_shared<spic::Button>("mainmenubutton", (camera->getAspectWidth() - 500), (camera->getAspectHeight() - 200), 367, 105, "BackToMenuScript");
    std::shared_ptr<ChangeSceneBehaviour> BackToMenuScript = std::make_shared<ChangeSceneBehaviour>("BackToMenuScript", "MainMenu");
    BackToMenuScript->setAlwaysReset(true);
    BackToMenu->AddComponent(BackToMenuScript);
    BackToMenu->SetName("paused");
    BackToMenu->SetActive(false);
    GameScene->AddGameObject(hp);
    GameScene->AddGameObject(magazine);
    GameScene->AddGameObject(cheats);
    GameScene->AddGameObject(fps);
    GameScene->AddGameObject(paused);
    GameScene->AddGameObject(BackToMenu);
    GameScene->AddGameObject(Health);

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
