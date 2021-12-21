#include <crtdbg.h>
#include <iostream>
#include "Controllers/EngineController.hpp"

int main(char* argv[]) {
    try{
        EngineController::GetInstance()->StartGame();
    }
    catch (const std::exception& ex) {
        std::cerr << argv[0] << ": " << ex.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...) {
        std::cerr << argv[0] << ": unknown error\n";
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}