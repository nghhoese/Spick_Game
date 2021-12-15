#include "HelpSceneBuilder.hpp"

std::shared_ptr<spic::Scene> HelpSceneBuilder::BuildScene()
{
    std::shared_ptr<spic::Scene> scene = std::make_shared<spic::Scene>("HelpScene");

    int screenWidth = EngineController::GetInstance()->GetScreenWidth();
    int screenHeight = EngineController::GetInstance()->GetScreenHeight();

    buttonBack= std::make_shared<spic::Button>("back", (screenWidth - 400), (screenHeight - 200), 219, 120, "BackToMenuScript");
	buttonBack->SetName("BackToMenuScript");
    scene->AddGameObject(buttonBack);

    spic::Color textColor = spic::Color(1.0, 1.0, 1.0, 1.0);

    std::shared_ptr<spic::Text> title = std::make_shared<spic::Text>("Help", "Capsmall", 100, textColor, ((screenWidth - screenWidth) + 60), ((screenHeight - screenHeight) + 50));
    std::shared_ptr<spic::Text> head1 = std::make_shared<spic::Text>("Your Mission", "Capsmall", 60, textColor, ((screenWidth - screenWidth) + 60), ((screenHeight - screenHeight) + 150));
    std::shared_ptr<spic::Text> m1 = std::make_shared<spic::Text>("YOUR MISSION WILL BE TO INFILTRATE THIS GERMAN FACILITY AND TAKE OUT THE SCIENTIST ", "Segment16CBold", 38, textColor, ((screenWidth - screenWidth) + 60), ((screenHeight - screenHeight) + 220));
    std::shared_ptr<spic::Text> m2 = std::make_shared<spic::Text>("PERFORMING DANGEROUS RESEARCH HERE. TRY TO MOVE UNDETECTED THROUGH THE FACILITY, ", "Segment16CBold", 38, textColor, ((screenWidth - screenWidth) + 60), ((screenHeight - screenHeight) + 260));
    std::shared_ptr<spic::Text> m3 = std::make_shared<spic::Text>("USE THE DARKNESS AS COVER AND USE VIOLENCE AS A LAST RESORT.", "Segment16CBold", 38, textColor, ((screenWidth - screenWidth) + 60), ((screenHeight - screenHeight) + 300));
    std::shared_ptr<spic::Text> head2 = std::make_shared<spic::Text>("Controls", "Capsmall", 60, textColor, ((screenWidth - screenWidth) + 60), ((screenHeight - screenHeight) + 370));
    std::shared_ptr<spic::Text> c1 = std::make_shared<spic::Text>("MOVEMENT             | WASD-KEYS", "Segment16CBold", 38, textColor, ((screenWidth - screenWidth) + 60), ((screenHeight - screenHeight) + 450));
    std::shared_ptr<spic::Text> c2 = std::make_shared<spic::Text>("SHOOT                | LEFT-MOUSE-CLICK", "Segment16CBold", 38, textColor, ((screenWidth - screenWidth) + 60), ((screenHeight - screenHeight) + 490));
    std::shared_ptr<spic::Text> c3 = std::make_shared<spic::Text>("PAUSE                | ESCAPE-KEY", "Segment16CBold", 38, textColor, ((screenWidth - screenWidth) + 60), ((screenHeight - screenHeight) + 530));
    std::shared_ptr<spic::Text> c4 = std::make_shared<spic::Text>("CHEATS               | EQUALS-KEY", "Segment16CBold", 38, textColor, ((screenWidth - screenWidth) + 60), ((screenHeight - screenHeight) + 570));
    std::shared_ptr<spic::Text> c5 = std::make_shared<spic::Text>("SPEEDUP              | PAGEUP-KEY", "Segment16CBold", 38, textColor, ((screenWidth - screenWidth) + 60), ((screenHeight - screenHeight) + 610));
    std::shared_ptr<spic::Text> c6 = std::make_shared<spic::Text>("SLOWDOWN             | PAGEDOWN-KEY", "Segment16CBold", 38, textColor, ((screenWidth - screenWidth) + 60), ((screenHeight - screenHeight) + 650));
    std::shared_ptr<spic::Text> c7 = std::make_shared<spic::Text>("RESET GAMEPLAY SPEED | HOME-KEY", "Segment16CBold", 38, textColor, ((screenWidth - screenWidth) + 60), ((screenHeight - screenHeight) + 690));
    std::shared_ptr<spic::Text> c8 = std::make_shared<spic::Text>("SHOW FPS             | F-KEY", "Segment16CBold", 38, textColor, ((screenWidth - screenWidth) + 60), ((screenHeight - screenHeight) + 730));
    std::shared_ptr<spic::Text> c9 = std::make_shared<spic::Text>("ENABLE CHEATS        | C-KEY", "Segment16CBold", 38, textColor, ((screenWidth - screenWidth) + 60), ((screenHeight - screenHeight) + 770));

    scene->AddGameObject(title);
    scene->AddGameObject(head1);
    scene->AddGameObject(m1);
    scene->AddGameObject(m2);
    scene->AddGameObject(m3);
    scene->AddGameObject(head2);
    scene->AddGameObject(c1);
    scene->AddGameObject(c2);
    scene->AddGameObject(c3);
    scene->AddGameObject(c4);
    scene->AddGameObject(c5);
    scene->AddGameObject(c6);
    scene->AddGameObject(c7); 
    scene->AddGameObject(c8);
    scene->AddGameObject(c9);

    std::shared_ptr<ChangeSceneBehaviour> scriptPlay = std::make_shared<ChangeSceneBehaviour>("BackToMenuScript", "MainMenu");
    buttonBack->AddComponent(scriptPlay);
    
    return scene;
}
