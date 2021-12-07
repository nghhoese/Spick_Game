#include "CheatsMenuBuilder.hpp"

std::shared_ptr<spic::Scene> CheatsMenuBuilder::BuildScene() {
    std::shared_ptr<spic::Scene> scene = std::make_shared<spic::Scene>("CheatsMenu");

    buttonBackToLevel = std::make_shared<spic::Button>("button", 10,400, 75, 150, "StartGameScript");
    scene->AddGameObject(buttonBackToLevel);

    spic::Color textColor = spic::Color(1.0, 1.0, 1.0, 1.0);
    std::shared_ptr<spic::Text> HeaderText = std::make_shared<spic::Text>("Cheats Menu", "Capsmall", 60, textColor, 10, 50);
    scene->AddGameObject(HeaderText);

    std::shared_ptr<spic::Text> UpMovementSpeedText = std::make_shared<spic::Text>("Up Movement Speed:", "Capsmall", 40, textColor, 10, 150);
    scene->AddGameObject(UpMovementSpeedText);
    std::shared_ptr<spic::Text> MovementSpeedButtonText = std::make_shared<spic::Text>("Arrow Key Up", "Capsmall", 40, textColor, 500, 150);
    scene->AddGameObject(MovementSpeedButtonText);

    std::shared_ptr<spic::Text> LowerMovementSpeedText = std::make_shared<spic::Text>("Lower Movement Speed:", "Capsmall", 40, textColor, 10, 200);
    scene->AddGameObject(LowerMovementSpeedText);
    std::shared_ptr<spic::Text> LowerMovementSpeedButtonText = std::make_shared<spic::Text>("Arrow Key Down", "Capsmall", 40, textColor, 500, 200);
    scene->AddGameObject(LowerMovementSpeedButtonText);

    std::shared_ptr<spic::Text> DamagelessText = std::make_shared<spic::Text>("Enable Damageless:", "Capsmall", 40, textColor, 10, 250);
    scene->AddGameObject(DamagelessText);
    std::shared_ptr<spic::Text> DamagelessButtonText = std::make_shared<spic::Text>("L", "Capsmall", 40, textColor, 500, 250);
    scene->AddGameObject(DamagelessButtonText);

    std::shared_ptr<spic::Text> UndectabilityText = std::make_shared<spic::Text>("Enable Undetectability", "Capsmall", 40, textColor, 10, 300);
    scene->AddGameObject(UndectabilityText);
    std::shared_ptr<spic::Text> UndectabilityButtonText = std::make_shared<spic::Text>("U", "Capsmall", 40, textColor, 500, 300);
    scene->AddGameObject(UndectabilityButtonText);

    std::shared_ptr<spic::Text> InstakillText = std::make_shared<spic::Text>("Instakill the player:", "Capsmall", 40, textColor, 10, 350);
    scene->AddGameObject(InstakillText);
    std::shared_ptr<spic::Text> InstakillButtonText = std::make_shared<spic::Text>("Y", "Capsmall", 40, textColor, 500, 350);
    scene->AddGameObject(InstakillButtonText);

    return scene;
    
}

void CheatsMenuBuilder::BuildScript() {
    std::shared_ptr<LevelController> level = std::make_shared<LevelController>();
    std::string levelString = std::to_string(level->GetCurrentLevel());

    std::shared_ptr<ChangeSceneBehaviour> scriptBackToLevel = std::make_shared<ChangeSceneBehaviour>("StartGameScript", "level" + levelString);
    buttonBackToLevel->AddComponent(scriptBackToLevel);
}