// Spick_Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "API_Headers/Importation.hpp"
#include "API_Headers/Point.hpp"
#include "API_Headers/KeyCode.hpp"

int main()
{
    spic::Importation* k = new spic::Importation();
    spic::KeyCode c = spic::KeyCode::W;
    
    while (true) {
        spic::Point point = k->MousePosition();
        std::cout << point.x << point.y << std::endl;
        //k->GetKeyDown(c);
    }
}
