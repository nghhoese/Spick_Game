#include "MainMenuBuilder.hpp"
#include <windows.h>

std::shared_ptr<spic::Scene> MainMenuBuilder::BuildScene() {
    std::shared_ptr<spic::Scene> scene = std::make_shared<spic::Scene>("MainMenu");

    std::shared_ptr<spic::GameObject> background = std::make_shared<spic::GameObject>("Background");
    std::shared_ptr<spic::Sprite> sprite = std::make_shared<spic::Sprite>();
    scene->AddGameObject(background);
    spic::Transform transfrom = *background->getTransform();
    background->AddComponent(sprite);
    sprite->SetSprite("assets/menu.png");
    int x = GetSystemMetrics(SM_CXSCREEN);
    int y = GetSystemMetrics(SM_CYSCREEN);
    if (x < 1920) {
        transfrom.position.x = 200;
        transfrom.position.y = 20;
        transfrom.scale = 0.75;
    }
    else {
        transfrom.position.x = 400;
        transfrom.position.y = 40;
        transfrom.scale = 1.5;
    }



    background->setTransform(&transfrom);

    if (x < 1920) {
        buttonPlay = std::make_shared<spic::Button>("", 420, 130, 130, 50, "StartGameScript");
        buttonPlay->SetName("StartGameButton");
        scene->AddGameObject(buttonPlay);
        std::shared_ptr<ChangeSceneBehaviour> scriptPlay = std::make_shared<ChangeSceneBehaviour>("StartGameScript", "level1");
        buttonPlay->AddComponent(scriptPlay);

        buttonHelp = std::make_shared<spic::Button>("", 420, 205, 130, 50, "OpenHelpScript");
        buttonHelp->SetName("HelpButton");
        scene->AddGameObject(buttonHelp);
        std::shared_ptr<ChangeSceneBehaviour> scriptHelp = std::make_shared<ChangeSceneBehaviour>("OpenHelpScript", "HelpScene");
        buttonHelp->AddComponent(scriptHelp);

        buttonCredits = std::make_shared<spic::Button>("", 420, 260, 130, 50, "OpenCreditsScript");
        buttonCredits->SetName("CreditsButton");
        scene->AddGameObject(buttonCredits);
        std::shared_ptr<ChangeSceneBehaviour> scriptCredits = std::make_shared<ChangeSceneBehaviour>("OpenCreditsScript", "CreditsScene");
        buttonCredits->AddComponent(scriptCredits);

        buttonQuit = std::make_shared<spic::Button>("", 420, 330, 130, 50, "QuitScript");
        buttonQuit->SetName("QuitButton");
        scene->AddGameObject(buttonQuit);
    }
    else {
        buttonPlay = std::make_shared<spic::Button>("", 840, 288, 270, 108, "StartGameScript");
        buttonPlay->SetName("StartGameButton");
        scene->AddGameObject(buttonPlay);
        std::shared_ptr<ChangeSceneBehaviour> scriptPlay = std::make_shared<ChangeSceneBehaviour>("StartGameScript", "level1");
        buttonPlay->AddComponent(scriptPlay);

        buttonHelp = std::make_shared<spic::Button>("", 840, 413, 270, 108, "OpenHelpScript");
        buttonHelp->SetName("HelpButton");
        scene->AddGameObject(buttonHelp);
        std::shared_ptr<ChangeSceneBehaviour> scriptHelp = std::make_shared<ChangeSceneBehaviour>("OpenHelpScript", "HelpScene");
        buttonHelp->AddComponent(scriptHelp);

        buttonCredits = std::make_shared<spic::Button>("", 840, 538, 270, 108, "OpenCreditsScript");
        buttonCredits->SetName("CreditsButton");
        scene->AddGameObject(buttonCredits);
        std::shared_ptr<ChangeSceneBehaviour> scriptCredits = std::make_shared<ChangeSceneBehaviour>("OpenCreditsScript", "CreditsScene");
        buttonCredits->AddComponent(scriptCredits);

        buttonQuit = std::make_shared<spic::Button>("", 840, 663, 270, 108, "QuitScript");
        buttonQuit->SetName("QuitButton");
        scene->AddGameObject(buttonQuit);
    }
   
    std::shared_ptr<QuitBehaviour> quitScript = std::make_shared<QuitBehaviour>();
    buttonQuit->AddComponent(quitScript);
    return scene;
}