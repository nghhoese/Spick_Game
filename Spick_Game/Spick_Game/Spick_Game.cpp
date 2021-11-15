// Spick_Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "API_Headers/Importation.hpp"
#include "API_Headers/Point.hpp"

int main()
{
    spic::Importation* k = new spic::Importation();
    spic::Point point = k->MousePosition();
        
    std::cout << point.x << point.y << std::endl;
}
