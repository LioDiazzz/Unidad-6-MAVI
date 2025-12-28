#ifndef ENEMY_BOUNCE_H
#define ENEMY_BOUNCE_H

#include "Enemy.h"

class EnemyBounce : public Enemy
{
public:
    float gravity;
    float bounceFactor;
    float floorY;

    EnemyBounce(Vector2 startPos, float vx);

    void Update(float dt) override;
};

#endif
