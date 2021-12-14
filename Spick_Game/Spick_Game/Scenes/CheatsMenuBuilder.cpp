#include "CheatsMenuBuilder.hpp"

std::shared_ptr<spic::Scene> CheatsMenuBuilder::BuildScene() {
    std::shared_ptr<spic::Scene> scene = std::make_shared<spic::Scene>("CheatsMenu");

    buttonBackToLevel = std::make_shared<spic::Button>("back", 1600, 870, 219, 120, "BackToGameScript");
    buttonBackToLevel->SetName("BackToGameButton");
    scene->AddGameObject(buttonBackToLevel);

    spic::Color textColor = spic::Color(1.0, 1.0, 1.0, 1.0);
    std::shared_ptr<spic::Text> HeaderText = std::make_shared<spic::Text>("Cheats Menu", "Capsmall", 60, textColor, 10, 50);
    scene->AddGameObject(HeaderText);

    std::shared_ptr<spic::Text> EnableCheatsText = std::make_shared<spic::Text>("Enable Cheats:", "Capsmall", 40, textColor, 10, 150);
    scene->AddGameObject(EnableCheatsText);
    std::shared_ptr<spic::Text> EnableCheatsButtonText = std::make_shared<spic::Text>("C", "Capsmall", 40, textColor, 500, 150);
    scene->AddGameObject(EnableCheatsButtonText);

    std::shared_ptr<spic::Text> UpMovementSpeedText = std::make_shared<spic::Text>("Up Movement Speed:", "Capsmall", 40, textColor, 10, 200);
    scene->AddGameObject(UpMovementSpeedText);
    std::shared_ptr<spic::Text> MovementSpeedButtonText = std::make_shared<spic::Text>("Arrow Key Up", "Capsmall", 40, textColor, 500, 200);
    scene->AddGameObject(MovementSpeedButtonText);

    std::shared_ptr<spic::Text> LowerMovementSpeedText = std::make_shared<spic::Text>("Lower Movement Speed:", "Capsmall", 40, textColor, 10, 250);
    scene->AddGameObject(LowerMovementSpeedText);
    std::shared_ptr<spic::Text> LowerMovementSpeedButtonText = std::make_shared<spic::Text>("Arrow Key Down", "Capsmall", 40, textColor, 500, 250);
    scene->AddGameObject(LowerMovementSpeedButtonText);

    std::shared_ptr<spic::Text> DamagelessText = std::make_shared<spic::Text>("Damageless:", "Capsmall", 40, textColor, 10, 300);
    scene->AddGameObject(DamagelessText);
    std::shared_ptr<spic::Text> DamagelessButtonText = std::make_shared<spic::Text>("L", "Capsmall", 40, textColor, 500, 300);
    scene->AddGameObject(DamagelessButtonText);

    std::shared_ptr<spic::Text> UndectabilityText = std::make_shared<spic::Text>("Undetectability", "Capsmall", 40, textColor, 10, 350);
    scene->AddGameObject(UndectabilityText);
    std::shared_ptr<spic::Text> UndectabilityButtonText = std::make_shared<spic::Text>("U", "Capsmall", 40, textColor, 500, 350);
    scene->AddGameObject(UndectabilityButtonText);

    std::shared_ptr<spic::Text> InstakillText = std::make_shared<spic::Text>("Instakill the player:", "Capsmall", 40, textColor, 10, 400);
    scene->AddGameObject(InstakillText);
    std::shared_ptr<spic::Text> InstakillButtonText = std::make_shared<spic::Text>("Y", "Capsmall", 40, textColor, 500, 400);
    scene->AddGameObject(InstakillButtonText);

    std::shared_ptr<spic::Text> SkipLevelText = std::make_shared<spic::Text>("Skip Level:", "Capsmall", 40, textColor, 10, 450);
    scene->AddGameObject(SkipLevelText);
    std::shared_ptr<spic::Text> SkipLevelButtonText = std::make_shared<spic::Text>("T", "Capsmall", 40, textColor, 500, 450);
    scene->AddGameObject(SkipLevelButtonText);

    std::shared_ptr<spic::Text> WallsCheatText = std::make_shared<spic::Text>("Walls Collision:", "Capsmall", 40, textColor, 10, 500);
    scene->AddGameObject(WallsCheatText);
    std::shared_ptr<spic::Text> WallsCheatButtonText = std::make_shared<spic::Text>("Q", "Capsmall", 40, textColor, 500, 500);
    scene->AddGameObject(WallsCheatButtonText);

    std::shared_ptr<spic::Text> HitboxText = std::make_shared<spic::Text>("See Objects Hitbox:", "Capsmall", 40, textColor, 10, 550);
    scene->AddGameObject(HitboxText);
    std::shared_ptr<spic::Text> HitboxButtonText = std::make_shared<spic::Text>("O", "Capsmall", 40, textColor, 500, 550);
    scene->AddGameObject(HitboxButtonText);

    std::shared_ptr<LevelController> level = std::make_shared<LevelController>();
    std::string levelString = std::to_string(EngineController::GetInstance()->GetCurrentLevel());

    std::shared_ptr<ChangeSceneBehaviour> scriptBackToLevel = std::make_shared<ChangeSceneBehaviour>("BackToGameScript", "level" + levelString);
    buttonBackToLevel->AddComponent(scriptBackToLevel);
    
    return scene;
}