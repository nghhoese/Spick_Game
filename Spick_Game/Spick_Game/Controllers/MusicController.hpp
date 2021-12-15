#pragma once

#include <memory>
#include <API_Headers/GameObject.hpp>
#include <API_Headers/AudioSource.hpp>
#include "EngineController.hpp"

class MusicController {
private:
	MusicController();
public:
	static MusicController* GetInstance();
	void SetMainMenuMusic(std::shared_ptr<spic::Scene> mainMenu);
	void SetLevelMusic();
};