#include "Quit.hpp"

QuitBehaviour::QuitBehaviour() {
	Name("QuitScript");
}

void QuitBehaviour::OnClick()
{
	EngineController::GetInstance()->GetSceneByName("MainMenu")->Quit();
	EngineController::GetInstance()->EndGameLoop();
}

void QuitBehaviour::OnUpdate() {
}

void QuitBehaviour::OnAwake()
{
}

void QuitBehaviour::OnStart()
{
}

void QuitBehaviour::OnRender()
{
}

void QuitBehaviour::OnTriggerEnter2D(const spic::Collider& collider)
{
}

void QuitBehaviour::OnTriggerExit2D(const spic::Collider& collider)
{
}

void QuitBehaviour::OnTriggerStay2D(const spic::Collider& collider)
{
}