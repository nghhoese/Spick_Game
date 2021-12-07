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

    buttonOptions = std::make_shared<spic::Button>("button", 295, 245, 180, 72, "OpenOptionsScript");
    scene->AddGameObject(buttonOptions);
    return scene;
}

void MainMenuBuilder::BuildScript() {
    std::shared_ptr<ChangeSceneBehaviour> scriptPlay = std::make_shared<ChangeSceneBehaviour>("StartGameScript", "level1");
    buttonPlay->AddComponent(scriptPlay);
    std::shared_ptr<ChangeSceneBehaviour> scriptOptions = std::make_shared<ChangeSceneBehaviour>("OpenOptionsScript", "level1");
    buttonOptions->AddComponent(scriptOptions);
}