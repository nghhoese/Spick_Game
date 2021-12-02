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
	if (_engine->getGameOver()) {

		// Reset levels
		std::shared_ptr<LevelSceneBuilder> levelSceneBuilder = std::make_shared<LevelSceneBuilder>();

		levelSceneBuilder->BuildLevel(_engine, 1);
		levelSceneBuilder->BuildLevel(_engine, 2);
		levelSceneBuilder->BuildLevel(_engine, 3);

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


