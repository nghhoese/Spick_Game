// Spick_Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define SDL_MAIN_HANDLED
#include <iostream>
#include "API_Headers/Scene.hpp"
#include "API_Headers/Text.hpp"

int main()
{
    std::shared_ptr<spic::Scene> scene = std::make_shared<spic::Scene>("test");
    spic::Color textColor = spic::Color(0.0, 0.0, 0.0, 1.0);
    std::shared_ptr<spic::Text> text = std::make_shared<spic::Text>("Advanced Stealth", "Capsmall", 60, textColor, 10, 50);

    scene->AddGameObject(text);

    while (true) {
        scene->Render();
    }
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
