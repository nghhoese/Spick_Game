#define SDL_MAIN_HANDLED

#include <crtdbg.h>
#include <iostream>
#include "Controllers/EngineController.hpp"
#include "Controllers/MusicController.hpp"

int main(char* argv[]) {
    try{
        EngineController::GetInstance()->CreateNewWindow("Tactical Stealth", 1920, 1080);
        std::shared_ptr<spic::Scene> mainMenu = EngineController::GetInstance()->BuildMainMenu();

        EngineController::GetInstance()->AddScene(mainMenu);
        EngineController::GetInstance()->BuildLevels();
        MusicController::GetInstance()->SetLevelMusic();
        MusicController::GetInstance()->SetMainMenuMusic(mainMenu);
        EngineController::GetInstance()->BuildGameOverScene();
        EngineController::GetInstance()->BuildCheatScene();
        EngineController::GetInstance()->BuildHelpScene();
        EngineController::GetInstance()->BuildCreditScene();
        EngineController::GetInstance()->SetActiveScene(mainMenu);
        EngineController::GetInstance()->StartGameLoop();
    }
    catch (const std::exception& ex) {
        std::cerr << argv[0] << ": " << ex.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...) {
        std::cerr << argv[0] << ": unknown error\n";
        return EXIT_FAILURE;
    }

   /* _CrtDumpMemoryLeaks();*/
    return EXIT_SUCCESS;
}