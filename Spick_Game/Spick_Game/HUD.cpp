#include "HUD.hpp"

HUD::HUD(spic::Engine* engine)
{
	this->engine = engine;
}

void HUD::OnAwake()
{
}

void HUD::OnStart()
{
}

void HUD::OnUpdate()
{
	SetFps(engine->GetFPS());
}

void HUD::OnRender()
{
}

void HUD::OnTriggerEnter2D(const Collider& collider)
{
}

void HUD::OnTriggerExit2D(const Collider& collider)
{
}

void HUD::OnTriggerStay2D(const Collider& collider)
{
}

void HUD::SetFps(const int& fps)
{
	this->fps = fps;
}

const int& HUD::GetFps()
{
	return this->fps;
}
