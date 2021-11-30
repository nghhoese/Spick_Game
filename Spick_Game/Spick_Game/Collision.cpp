#include "Collision.hpp"
#include "API_Headers/Scene.hpp"


std::shared_ptr<spic::BoxCollider> Collision::AABB(spic::GameObject* obj1, std::string tag)
{
    std::shared_ptr<spic::BoxCollider> collider = std::dynamic_pointer_cast<spic::BoxCollider>(obj1->GetComponent <spic::BoxCollider>());
    int obj1ColliderWidth = collider->Width();
    int obj1ColliderHeight = collider->Height();
    int obj2ColliderWidth = 1;
    int obj2ColliderHeight = 1;
    for (std::shared_ptr<spic::GameObject> obj2 : obj1->getScene().get()->GetGameObjectsByTag(tag)) {
        std::shared_ptr<spic::BoxCollider> collider2 = std::dynamic_pointer_cast<spic::BoxCollider>(obj2->GetComponent <spic::BoxCollider>());
        obj2ColliderWidth = collider2->Width();
        obj2ColliderHeight = collider2->Height();
        if (obj1->getTransform()->position.x + obj1ColliderWidth >= obj2->getTransform()->position.x &&
            obj2->getTransform()->position.x + obj2ColliderWidth >= obj1->getTransform()->position.x &&
            obj1->getTransform()->position.y + obj1ColliderWidth >= obj2->getTransform()->position.y &&
            obj2->getTransform()->position.y + obj2ColliderHeight >= obj1->getTransform()->position.y
            ) {
            return collider2;
        }
    }

    return nullptr;
}