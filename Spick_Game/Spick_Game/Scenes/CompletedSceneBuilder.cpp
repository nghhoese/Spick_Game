#include "CompletedSceneBuilder.hpp"

std::shared_ptr<spic::Scene> CompletedSceneBuilder::BuildScene()
{
    std::shared_ptr<spic::Scene> scene = std::make_shared<spic::Scene>("CompletedScene");

    buttonBackToMenu = std::make_shared<spic::Button>("mainmenubutton", 770, 670, 367, 105, "MainMenuScript");

    buttonBackToMenu->SetName("BackToMenuScript");
    scene->AddGameObject(buttonBackToMenu);

    spic::Color textColor = spic::Color(1.0, 1.0, 1.0, 1.0);
    std::shared_ptr<spic::Text> text = std::make_shared<spic::Text>("MISSION COMPLETE", "Capsmall", 140, textColor, 600, 50);


    scene->AddGameObject(text);
    std::shared_ptr<ChangeSceneBehaviour> scriptPlay = std::make_shared<ChangeSceneBehaviour>("MainMenuScript", "MainMenu");
    buttonBackToMenu->AddComponent(scriptPlay);
    return scene;
}


