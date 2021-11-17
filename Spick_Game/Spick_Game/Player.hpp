#pragma once

#include "API_Headers/Importation.hpp"
#include "API_Headers/Point.hpp"
#include "API_Headers/KeyCode.hpp"

class Player {
private:
	int healthpoints;
	int ammo;
public:
	double x;
	double y;
	const void checkMouseButtons();
	const void checkKeys();
	const spic::Point checkMousePosition();
};