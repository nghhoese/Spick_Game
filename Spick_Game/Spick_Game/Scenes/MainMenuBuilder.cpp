#include "MainMenuBuilder.hpp"
#include "../Behaviourscript/ChangeSceneBehaviour.hpp"

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


    buttonPlay = std::make_shared<spic::Button>("", 314, 165, 72, 134, "StartGameScript");
    scene->AddGameObject(buttonPlay);

    buttonOptions = std::make_shared<spic::Button>("button", 295, 245, 72, 180, "OpenOptionsScript");
    scene->AddGameObject(buttonOptions);

    spic::Color textColor = spic::Color(1.0, 1.0, 1.0, 1.0);
    std::shared_ptr<spic::Text> text = std::make_shared<spic::Text>("Hallo", "Capsmall", 60, textColor, 10, 50);

    scene->AddGameObject(text);

    return scene;
}

void MainMenuBuilder::BuildScript(spic::Engine* engine) {
    std::shared_ptr<ChangeSceneBehaviour> scriptPlay = std::make_shared<ChangeSceneBehaviour>("StartGameScript", "level1", engine);
    buttonPlay->AddComponent(scriptPlay);
    std::shared_ptr<ChangeSceneBehaviour> scriptOptions = std::make_shared<ChangeSceneBehaviour>("OpenOptionsScript", "TestScene", engine);
    buttonOptions->AddComponent(scriptOptions);
}