#include "CreditsSceneBuilder.hpp"

std::shared_ptr<spic::Scene> CreditsSceneBuilder::BuildScene()
{
    std::shared_ptr<spic::Scene> scene = std::make_shared<spic::Scene>("CreditsScene");

    buttonBack = std::make_shared<spic::Button>("back", 1600, 870, 219, 120, "BackToMenuScript");
	buttonBack->SetName("BackToMenuButton");
    scene->AddGameObject(buttonBack);

    spic::Color textColor = spic::Color(1.0, 1.0, 1.0, 1.0);

    std::shared_ptr<spic::Text> title = std::make_shared<spic::Text>("Credits", "Capsmall", 100, textColor, 60, 5);
    std::shared_ptr<spic::Text> head1 = std::make_shared<spic::Text>("THANK YOU FOR PLAYING", "Capsmall", 80, textColor, 38, 150);
    std::shared_ptr<spic::Text> head2 = std::make_shared<spic::Text>("THE TEAM:", "Capsmall", 60, textColor, 38, 300);
    std::shared_ptr<spic::Text> n1 = std::make_shared<spic::Text>("JOERY VAN EGMOND", "Segment16CBold", 38, textColor, 38, 390);
    std::shared_ptr<spic::Text> n2 = std::make_shared<spic::Text>("JEROEN VAN DER POEL", "Segment16CBold", 38, textColor, 38, 430);
    std::shared_ptr<spic::Text> n3 = std::make_shared<spic::Text>("BAS VAN PELT", "Segment16CBold", 38, textColor, 38, 470);
    std::shared_ptr<spic::Text> n4 = std::make_shared<spic::Text>("NICK 'DE KAPITEIN' VAN HOESEL ", "Segment16CBold", 38, textColor, 38, 510);
    std::shared_ptr<spic::Text> n5 = std::make_shared<spic::Text>("RENS ASPERS", "Segment16CBold", 38, textColor, 38, 550);

    /*std::shared_ptr<spic::Text> t1 = std::make_shared<spic::Text>("WITH SPECIAL THANKS TO:", "Capsmall", 40, textColor, 10, 460);
    std::shared_ptr<spic::Text> t2 = std::make_shared<spic::Text>("STACK OVERFLOW | FOR TEATCHING US C++", "Segment16CBold", 20, textColor, 10, 510);
    std::shared_ptr<spic::Text> t3 = std::make_shared<spic::Text>("FERRAN | FOR EMOTIONAL SUPPORT", "Segment16CBold", 20, textColor, 10, 530);
    std::shared_ptr<spic::Text> t4 = std::make_shared<spic::Text>("JURGEN | INSPIRING US", "Segment16CBold", 20, textColor, 10, 550);
    std::shared_ptr<spic::Text> t5 = std::make_shared<spic::Text>("BAHAR AND KWIBUS | MAKING THESE MONTHS SOMEWHAT BAREABLE", "Segment16CBold", 20, textColor, 10, 570);
    std::shared_ptr<spic::Text> t6 = std::make_shared<spic::Text>("REINOUT | BEING A WOESHOEM", "Segment16CBold", 20, textColor, 10, 590);*/


    scene->AddGameObject(title);
    scene->AddGameObject(head1);
    scene->AddGameObject(head2);
    scene->AddGameObject(n1);
    scene->AddGameObject(n2);
    scene->AddGameObject(n3);
    scene->AddGameObject(n4);
    scene->AddGameObject(n5);
    /*scene->AddGameObject(t1);
    scene->AddGameObject(t2);
    scene->AddGameObject(t3);
    scene->AddGameObject(t4);
    scene->AddGameObject(t5);
    scene->AddGameObject(t6);*/
    
    std::shared_ptr<ChangeSceneBehaviour> scriptPlay = std::make_shared<ChangeSceneBehaviour>("BackToMenuScript", "MainMenu");
    buttonBack->AddComponent(scriptPlay);
    return scene;
}
