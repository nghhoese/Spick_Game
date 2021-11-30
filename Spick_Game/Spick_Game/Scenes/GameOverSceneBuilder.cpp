#include "GameOverSceneBuilder.hpp"

std::shared_ptr<spic::Scene> GameOverBuilder::BuildScene()
{
    std::shared_ptr<spic::Scene> scene = std::make_shared<spic::Scene>("GameOverMenu");

    buttonBackToMenu = std::make_shared<spic::Button>("button", 314, 165, 72, 134, "MainMenuScript");
    scene->AddGameObject(buttonBackToMenu);

    spic::Color textColor = spic::Color(1.0, 1.0, 1.0, 1.0);
    std::shared_ptr<spic::Text> text = std::make_shared<spic::Text>("Game Over", "Capsmall", 60, textColor, 10, 50);

    scene->AddGameObject(text);

    return scene;
}

void GameOverBuilder::BuildScript(spic::Engine* engine){
	std::shared_ptr<ChangeSceneBehaviour> scriptPlay = std::make_shared<ChangeSceneBehaviour>("MainMenuScript", "MainMenu", engine);
    buttonBackToMenu->AddComponent(scriptPlay);
}
