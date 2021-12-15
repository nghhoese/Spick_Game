#include "GameOverSceneBuilder.hpp"

std::shared_ptr<spic::Scene> GameOverBuilder::BuildScene()
{
    std::shared_ptr<spic::Scene> scene = std::make_shared<spic::Scene>("GameOverMenu");

    buttonBackToMenu = std::make_shared<spic::Button>("mainmenubutton", 770, 670, 367, 105, "MainMenuScript");
    buttonBackToMenu->SetName("BackToMenuScript");
    scene->AddGameObject(buttonBackToMenu);

    spic::Color textColor = spic::Color(1.0, 1.0, 1.0, 1.0);
    std::shared_ptr<spic::Text> text = std::make_shared<spic::Text>("Game Over", "Capsmall", 140, textColor, 600, 50);

    scene->AddGameObject(text);

    return scene;
}

void GameOverBuilder::BuildScript(){
	std::shared_ptr<ChangeSceneBehaviour> scriptPlay = std::make_shared<ChangeSceneBehaviour>("MainMenuScript", "MainMenu");
    buttonBackToMenu->AddComponent(scriptPlay);
}
