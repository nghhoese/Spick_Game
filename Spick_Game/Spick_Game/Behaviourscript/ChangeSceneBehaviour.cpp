#include "ChangeSceneBehaviour.hpp"
#include "API_Headers/Scene.hpp"
#include <API_Headers/Engine.hpp>
#include "../Scenes/LevelSceneBuilder.hpp"


ChangeSceneBehaviour::ChangeSceneBehaviour(std::string name, std::string scene, spic::Engine* engine)
: _engine(engine),_scene(scene){
	Name(name);
}

void ChangeSceneBehaviour::OnClick()
{
	std::cout << _scene << std::endl;

	if (_engine->getGameOver()) {

		std::shared_ptr<LevelSceneBuilder> levelSceneBuilder = std::make_shared<LevelSceneBuilder>();
		std::shared_ptr<spic::Scene> levelOneScene = _engine->GetSceneByName("level1");
		levelOneScene = levelSceneBuilder->BuildLevelScene(_engine, 1);
		_engine->AddScene(levelOneScene);

		std::shared_ptr<spic::Scene> levelTwoScene = _engine->GetSceneByName("level2");
		levelTwoScene = levelSceneBuilder->BuildLevelScene(_engine, 2);
		_engine->AddScene(levelTwoScene);

		std::shared_ptr<spic::Scene> levelThreeScene = _engine->GetSceneByName("level3");
		levelThreeScene = levelSceneBuilder->BuildLevelScene(_engine, 3);
		_engine->AddScene(levelThreeScene);

		_engine->setGameOver(false);
	}

	_engine->SetActiveScene(_scene);

}

void ChangeSceneBehaviour::OnUpdate() {
}

void ChangeSceneBehaviour::OnAwake()
{
}

void ChangeSceneBehaviour::OnStart()
{
}

void ChangeSceneBehaviour::OnRender()
{
}

void ChangeSceneBehaviour::OnTriggerEnter2D(const Collider& collider)
{
}

void ChangeSceneBehaviour::OnTriggerExit2D(const Collider& collider)
{
}

void ChangeSceneBehaviour::OnTriggerStay2D(const Collider& collider)
{
}


