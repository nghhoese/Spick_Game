#include "MainMenuBuilder.hpp"

std::shared_ptr<spic::Scene> MainMenuBuilder::BuildScene() {
    std::shared_ptr<spic::Scene> scene = std::make_shared<spic::Scene>("MainMenu");

    std::shared_ptr<spic::GameObject> background = std::make_shared<spic::GameObject>("Background");
    std::shared_ptr<spic::Sprite> sprite = std::make_shared<spic::Sprite>();
    scene->AddGameObject(background);
    spic::Transform transfrom = *background->getTransform();
    background->AddComponent(sprite);
    sprite->SetSprite("assets/menu.png");

    transfrom.position.x = 0;
    transfrom.position.y = 0;
    transfrom.scale = 1;

    background->setTransform(&transfrom);


    buttonPlay = std::make_shared<spic::Button>("", 314, 165, 134, 72, "StartGameScript");
    scene->AddGameObject(buttonPlay);
    std::shared_ptr<ChangeSceneBehaviour> scriptPlay = std::make_shared<ChangeSceneBehaviour>("StartGameScript", "level1");
    buttonPlay->AddComponent(scriptPlay);

    buttonHelp = std::make_shared<spic::Button>("", 295, 245, 180, 72, "OpenHelpScript");
    scene->AddGameObject(buttonHelp);
    std::shared_ptr<ChangeSceneBehaviour> scriptHelp = std::make_shared<ChangeSceneBehaviour>("OpenHelpScript", "HelpScene");
    buttonHelp->AddComponent(scriptHelp);

    buttonCredits = std::make_shared<spic::Button>("", 295, 397, 180, 72, "OpenCreditsScript");
    scene->AddGameObject(buttonCredits);
    std::shared_ptr<ChangeSceneBehaviour> scriptCredits = std::make_shared<ChangeSceneBehaviour>("OpenCreditsScript", "CreditsScene");
    buttonCredits->AddComponent(scriptCredits);

    buttonQuit = std::make_shared<spic::Button>("", 316, 492, 122, 81, "QuitScript");
    scene->AddGameObject(buttonQuit);
    std::shared_ptr<QuitBehaviour> quitScript = std::make_shared<QuitBehaviour>();
    buttonQuit->AddComponent(quitScript);
    return scene;
}