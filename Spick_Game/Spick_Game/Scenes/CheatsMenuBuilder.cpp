#include "CheatsMenuBuilder.hpp"

std::shared_ptr<spic::Scene> CheatsMenuBuilder::BuildScene(spic::Engine* engine) {
    std::shared_ptr<spic::Scene> scene = std::make_shared<spic::Scene>("CheatsMenu");

    buttonDamageLess = std::make_shared<spic::Button>("button", 314, 165, 72, 134, "DamageLessScript");
    scene->AddGameObject(buttonDamageLess);

    buttonBackToLevel = std::make_shared<spic::Button>("button", 295, 245, 72, 180, "StartGameScript");
    scene->AddGameObject(buttonBackToLevel);

    spic::Color textColor = spic::Color(1.0, 1.0, 1.0, 1.0);
    std::shared_ptr<spic::Text> text = std::make_shared<spic::Text>("Cheats Menu", "Capsmall", 60, textColor, 10, 50);

    scene->AddGameObject(text);

    return scene;
    
}

void CheatsMenuBuilder::BuildScript(spic::Engine* engine) {
    std::shared_ptr<ChangeSceneBehaviour> scriptDamageLess = std::make_shared<ChangeSceneBehaviour>("DamageLessScript", "", engine);
    buttonDamageLess->AddComponent(scriptDamageLess);

    // Ophalen in welk level de player momenteel zit
    std::shared_ptr<ChangeSceneBehaviour> scriptBackToLevel = std::make_shared<ChangeSceneBehaviour>("StartGameScript", "level1", engine);
    buttonBackToLevel->AddComponent(scriptBackToLevel);
}