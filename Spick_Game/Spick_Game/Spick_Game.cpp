// Spick_Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "API_Headers/Importation.hpp"
#include "API_Headers/Point.hpp"
#include "API_Headers/KeyCode.hpp"
#include "API_Headers/Scene.hpp"

int main()
{
    spic::Importation* k = new spic::Importation();
    spic::KeyCode c = spic::KeyCode::A;
    spic::MouseButton m = spic::MouseButton::RIGHT;
    spic::MouseButton l = spic::MouseButton::LEFT;

    spic::Scene* scene = new spic::Scene("test");
    
    while (true) {
        //spic::Point point = k->MousePosition();
        //std::cout << "x " << point.x << " y " << point.y << std::endl;
        
        //std::cout << k->GetMouseButton(m) << std::endl;
        //std::cout << k->GetMouseButton(l) << std::endl;

        //std::cout << k->GetMouseButtonUp(m) << std::endl;
        //std::cout << k->GetMouseButtonDown(m) << std::endl;

        //std::cout << k->AnyKeyDown() << std::endl;
        //std::cout << k->GetKey(c) << std::endl;
        //std::cout << k->AnyKey() << std::endl; ----------- werkt gedeeltelijk

        //std::cout << k->GetKeyDown(c) << std::endl;
        //std::cout << k->GetKeyUp(c) << std::endl;
    }
}
