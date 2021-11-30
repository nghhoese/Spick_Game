#include "CheatsMenuBuilder.hpp"

std::shared_ptr<spic::Scene> CheatsMenuBuilder::BuildScene(spic::Engine* engine) {
    std::shared_ptr<spic::Scene> scene = std::make_shared<spic::Scene>("CheatsMenu");

    buttonBackToLevel = std::make_shared<spic::Button>("button", 295,400, 72, 180, "StartGameScript");
    scene->AddGameObject(buttonBackToLevel);

    spic::Color textColor = spic::Color(1.0, 1.0, 1.0, 1.0);
    std::shared_ptr<spic::Text> text = std::make_shared<spic::Text>("Cheats Menu", "Capsmall", 60, textColor, 10, 50);
    scene->AddGameObject(text);

    std::shared_ptr<spic::Text> text2 = std::make_shared<spic::Text>("Up Movement Speed: Arrow Key Up", "Capsmall", 40, textColor, 10, 150);
    scene->AddGameObject(text2);

    std::shared_ptr<spic::Text> text3 = std::make_shared<spic::Text>("Lower Movement Speed: Arrow Key Down", "Capsmall", 40, textColor, 10, 200);
    scene->AddGameObject(text3);

    std::shared_ptr<spic::Text> text4 = std::make_shared<spic::Text>("Enable Damageless: L", "Capsmall", 40, textColor, 10, 250);
    scene->AddGameObject(text4);

    std::shared_ptr<spic::Text> text5 = std::make_shared<spic::Text>("Enable Undetectability: U", "Capsmall", 40, textColor, 10, 300);
    scene->AddGameObject(text5);

    return scene;
    
}

void CheatsMenuBuilder::BuildScript(spic::Engine* engine) {
    // Ophalen in welk level de player momenteel zit
    std::shared_ptr<ChangeSceneBehaviour> scriptBackToLevel = std::make_shared<ChangeSceneBehaviour>("StartGameScript", "level1", engine);
    buttonBackToLevel->AddComponent(scriptBackToLevel);
}