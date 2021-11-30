#pragma once
#include <API_Headers/GameObject.hpp>
#include "API_Headers/BoxCollider.hpp"
class Collision
{
public:
	static  std::shared_ptr<spic::BoxCollider> AABB(spic::GameObject* obj1, std::string tag);
};