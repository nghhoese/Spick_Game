#include "CompletedSceneBuilder.hpp"

std::shared_ptr<spic::Scene> CompletedSceneBuilder::BuildScene()
{
    std::shared_ptr<spic::Scene> scene = std::make_shared<spic::Scene>("CompletedScene");

    int screenWidth = EngineController::GetInstance()->GetScreenWidth();
    int screenHeight = EngineController::GetInstance()->GetScreenHeight();

    buttonBackToMenu = std::make_shared<spic::Button>("mainmenubutton", (screenWidth / 2.5), (screenHeight - 500), 367, 105, "MainMenuScript");

    buttonBackToMenu->SetName("BackToMenuScript");
    scene->AddGameObject(buttonBackToMenu);

    spic::Color textColor = spic::Color(1.0, 1.0, 1.0, 1.0);
    std::shared_ptr<spic::Text> text = std::make_shared<spic::Text>("MISSION COMPLETE", "Capsmall", 140, textColor, ((screenWidth / 6)), ((screenHeight - screenHeight) + 100));


    scene->AddGameObject(text);
    std::shared_ptr<ChangeSceneBehaviour> scriptPlay = std::make_shared<ChangeSceneBehaviour>("MainMenuScript", "MainMenu");
    buttonBackToMenu->AddComponent(scriptPlay);
    return scene;
}


