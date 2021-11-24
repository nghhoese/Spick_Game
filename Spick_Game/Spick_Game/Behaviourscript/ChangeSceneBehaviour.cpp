#include "ChangeSceneBehaviour.hpp"
#include "API_Headers/Scene.hpp"
#include <API_Headers/Engine.hpp>


ChangeSceneBehaviour::ChangeSceneBehaviour(std::string name, std::string scene, spic::Engine* engine)
: _engine(engine),_scene(scene){
	Name(name);
}

void ChangeSceneBehaviour::OnUpdate()
{
	std::cout << _scene << std::endl;
	_engine->SetActiveScene(_engine->GetSceneByName(_scene));	
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


