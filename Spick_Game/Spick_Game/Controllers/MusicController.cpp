#include "MusicController.hpp"

static MusicController* instance;

MusicController::MusicController() {

}

MusicController* MusicController::GetInstance()
{
	if (!instance)
	{
		instance = new MusicController();
	}
	return instance;
}

void MusicController::SetMainMenuMusic(std::shared_ptr<spic::Scene> mainMenu)
{
	std::shared_ptr<spic::GameObject> mainMenuMusic = std::make_shared<spic::GameObject>();
	mainMenu->AddGameObject(mainMenuMusic);
	mainMenuMusic->AddTag("music");

	std::shared_ptr<spic::AudioSource> menuSong = std::make_shared<spic::AudioSource>();
	mainMenuMusic->AddComponent(menuSong);
	menuSong->SetAudioClip("assets/dimmadome.mp3");
	menuSong->SetIsMusic(true);
	menuSong->Play(true);
}

void MusicController::SetLevelMusic()
{
	std::shared_ptr<spic::GameObject> level1Music = std::make_shared<spic::GameObject>();
	EngineController::GetInstance()->GetSceneByName("level1")->AddGameObject(level1Music);
	level1Music->AddTag("music");

	std::shared_ptr<spic::AudioSource> levelSong = std::make_shared<spic::AudioSource>();
	level1Music->AddComponent(levelSong);
	levelSong->SetAudioClip("assets/bgmusic1.mp3");
	levelSong->SetIsMusic(true);
}
