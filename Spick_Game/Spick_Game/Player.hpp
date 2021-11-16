#pragma once

#include "API_Headers/Importation.hpp"
#include "API_Headers/Point.hpp"
#include "API_Headers/KeyCode.hpp"

class Player {
private:
	int healthpoints;
	int ammo;
	double x;
	double y;
public:
	void checkMouseButtons();
	void checkKeys();
	const spic::Point checkMousePosition();
};