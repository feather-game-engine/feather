#pragma once

#include <feather/components/component.h>
#include <feather/entities/entity.h>

namespace fl {

class Collider : public fl::Component {
public:
    Collider(fl::Entity* owner);

    void setHitbox(int w, int h);
    SDL_Rect& getHitbox();

    bool isColliding();
    std::vector<Entity*> getCollisions();

    void setColliding(bool b);
    void addCollision(Entity* e);
    void clearCollisions();

private:
    int hitbox_w;
    int hitbox_h;
    SDL_Rect m_hitbox;
    bool m_colliding;
    std::vector<Entity*> m_collisions;

};

}
