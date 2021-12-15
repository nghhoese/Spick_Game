#include "MainMenuBuilder.hpp"

std::shared_ptr<spic::Scene> MainMenuBuilder::BuildScene() {
    std::shared_ptr<spic::Scene> scene = std::make_shared<spic::Scene>("MainMenu");

    int screenWidth = EngineController::GetInstance()->GetScreenWidth();
    int screenHeight = EngineController::GetInstance()->GetScreenHeight();

    std::shared_ptr<spic::GameObject> background = std::make_shared<spic::GameObject>("Background");
    std::shared_ptr<spic::Sprite> sprite = std::make_shared<spic::Sprite>();
    scene->AddGameObject(background);
    spic::Transform transfrom = *background->getTransform();
    background->AddComponent(sprite);
    sprite->SetSprite("assets/title.jpg");

    transfrom.position.x = (screenWidth / 3.1);
    transfrom.position.y = ((screenHeight - screenHeight) + 50);
    transfrom.scale = 1.5;

    background->setTransform(&transfrom);


    buttonPlay = std::make_shared<spic::Button>("playbutton", (screenWidth / 2.3), ((screenHeight - screenHeight) + 288), 270, 108, "StartGameScript");
    buttonPlay->SetName("StartGameButton");
    scene->AddGameObject(buttonPlay);
    std::shared_ptr<ChangeSceneBehaviour> scriptPlay = std::make_shared<ChangeSceneBehaviour>("StartGameScript", "level1");
    buttonPlay->AddComponent(scriptPlay);

    buttonHelp = std::make_shared<spic::Button>("helpbutton", (screenWidth / 2.3), ((screenHeight - screenHeight) + 413), 270, 108, "OpenHelpScript");
    buttonHelp->SetName("HelpButton");
    scene->AddGameObject(buttonHelp);
    std::shared_ptr<ChangeSceneBehaviour> scriptHelp = std::make_shared<ChangeSceneBehaviour>("OpenHelpScript", "HelpScene");
    buttonHelp->AddComponent(scriptHelp);

    buttonCredits = std::make_shared<spic::Button>("creditsbutton", (screenWidth / 2.3), ((screenHeight - screenHeight) + 538), 270, 108, "OpenCreditsScript");
    buttonCredits->SetName("CreditsButton");
    scene->AddGameObject(buttonCredits);
    std::shared_ptr<ChangeSceneBehaviour> scriptCredits = std::make_shared<ChangeSceneBehaviour>("OpenCreditsScript", "CreditsScene");
    buttonCredits->AddComponent(scriptCredits);

    buttonQuit = std::make_shared<spic::Button>("quitbutton", (screenWidth / 2.3), ((screenHeight - screenHeight) + 663), 270, 108, "QuitScript");
    buttonQuit->SetName("QuitButton");
    scene->AddGameObject(buttonQuit);
    std::shared_ptr<QuitBehaviour> quitScript = std::make_shared<QuitBehaviour>();
    buttonQuit->AddComponent(quitScript);
    return scene;
}