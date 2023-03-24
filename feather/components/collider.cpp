#include <feather/components/collider.h>
#include <feather/components/transform.h>

namespace fl {

Collider::Collider(fl::Entity* owner) 
    : Component(owner) 
{

}


void Collider::setHitbox(int w, int h) {
    hitbox_w = w; 
    hitbox_h = h; 
}

SDL_Rect& Collider::getHitbox() {
    m_hitbox.x = m_owner->getComponent<fl::Transform>()->getPosition().x;
    m_hitbox.y = m_owner->getComponent<fl::Transform>()->getPosition().y;
    m_hitbox.w = hitbox_w;
    m_hitbox.h = hitbox_h;
    return m_hitbox;
}

bool Collider::isColliding() {
    return m_colliding;
}

std::vector<Entity*> Collider::getCollisions() {
    return m_collisions;
}

void Collider::setColliding(bool b) {
    m_colliding = b;
}

void Collider::addCollision(Entity* e) {
    m_collisions.push_back(e);
}

void Collider::clearCollisions() {
    m_collisions.clear();
}

}
