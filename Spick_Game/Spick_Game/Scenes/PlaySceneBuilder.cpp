#include "PlaySceneBuilderr.hpp"
#include "../Behaviourscript/ChangeSceneBehaviour.hpp"

std::shared_ptr<spic::Scene> PlaySceneBuilder::BuildScene() {
    std::shared_ptr<spic::Scene> scene = std::make_shared<spic::Scene>("PlayScene");

    std::shared_ptr<spic::GameObject> background = std::make_shared<spic::GameObject>("Background");
    std::shared_ptr<spic::Sprite> sprite = std::make_shared<spic::Sprite>();
    scene->AddGameObject(background);
    spic::Transform transfrom = *background->getTransform();
    background->AddComponent(sprite);
    sprite->SetSprite("assets/Eric.png");

    transfrom.position.x = 0;
    transfrom.position.y = 0;
    transfrom.scale = 1;

    background->setTransform(&transfrom);

    spic::Color textColor = spic::Color(1.0, 1.0, 1.0, 1.0);
    std::shared_ptr<spic::Text> text = std::make_shared<spic::Text>("Hallo", "Capsmall", 60, textColor, 10, 50);

    scene->AddGameObject(text);

    return scene;
}