#include "CheatsMenuBuilder.hpp"

std::shared_ptr<spic::Scene> CheatsMenuBuilder::BuildScene() {
    std::shared_ptr<spic::Scene> scene = std::make_shared<spic::Scene>("CheatsMenu");

    buttonBackToLevel = std::make_shared<spic::Button>("back", 1600, 870, 219, 120, "BackToGameScript");
    buttonBackToLevel->SetName("BackToGameButton");
    scene->AddGameObject(buttonBackToLevel);

    spic::Color textColor = spic::Color(1.0, 1.0, 1.0, 1.0);
    std::shared_ptr<spic::Text> title = std::make_shared<spic::Text>("Cheats Menu", "Capsmall", 100, textColor, 60, 5);

    std::shared_ptr<spic::Text> head = std::make_shared<spic::Text>("Cheat Controls", "Capsmall", 60, textColor, 32, 120);
    std::shared_ptr<spic::Text> m1 = std::make_shared<spic::Text>("ONLY USABLE WHEN CHEATS ARE ENABLED", "Segment16CBold", 38, textColor, 38, 180);
    std::shared_ptr<spic::Text> m2 = std::make_shared<spic::Text>("DISABLING CHEATS RESETS ALL USED CHEATS", "Segment16CBold", 38, textColor, 38, 220);
    std::shared_ptr<spic::Text> c1 = std::make_shared<spic::Text>("ENABLE CHEATS          | C-KEY", "Segment16CBold", 38, textColor, 38, 300);
    std::shared_ptr<spic::Text> c3 = std::make_shared<spic::Text>("ENABLE DAMAGELESS      | L-KEY", "Segment16CBold", 38, textColor, 38, 340);
    std::shared_ptr<spic::Text> c4 = std::make_shared<spic::Text>("ENABLE OBJECTS HITBOX  | O-KEY", "Segment16CBold", 38, textColor, 38, 380);
    std::shared_ptr<spic::Text> c2 = std::make_shared<spic::Text>("DISABLE COLLISION      | Q-KEY", "Segment16CBold", 38, textColor, 38, 420);
    std::shared_ptr<spic::Text> c5 = std::make_shared<spic::Text>("SKIP LEVEL             | T-KEY", "Segment16CBold", 38, textColor, 38, 460);
    std::shared_ptr<spic::Text> c6 = std::make_shared<spic::Text>("ENABLE UNDETECTABILITY | U-KEY", "Segment16CBold", 38, textColor, 38, 500);
    std::shared_ptr<spic::Text> c7 = std::make_shared<spic::Text>("INSTAKILL PLAYER       | Y-KEY", "Segment16CBold", 38, textColor, 38, 540);
    std::shared_ptr<spic::Text> c8 = std::make_shared<spic::Text>("UP MOVEMENT SPEED      | ARROW-KEY-UP", "Segment16CBold", 38, textColor, 38, 580);
    std::shared_ptr<spic::Text> c9 = std::make_shared<spic::Text>("LOWER MOVEMENT SPEED   | ARROW-KEY-DOWN", "Segment16CBold", 38, textColor, 38, 620);

    scene->AddGameObject(title);
    scene->AddGameObject(head);
    scene->AddGameObject(m1);
    scene->AddGameObject(m2);
    scene->AddGameObject(c1);
    scene->AddGameObject(c2);
    scene->AddGameObject(c3);
    scene->AddGameObject(c4);
    scene->AddGameObject(c5);
    scene->AddGameObject(c6);
    scene->AddGameObject(c7);
    scene->AddGameObject(c8);
    scene->AddGameObject(c9);

    std::shared_ptr<LevelController> level = std::make_shared<LevelController>();
    std::string levelString = std::to_string(EngineController::GetInstance()->GetCurrentLevel());

    std::shared_ptr<ChangeSceneBehaviour> scriptBackToLevel = std::make_shared<ChangeSceneBehaviour>("BackToGameScript", "level" + levelString);
    buttonBackToLevel->AddComponent(scriptBackToLevel);
    
    return scene;
}