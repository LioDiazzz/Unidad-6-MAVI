#include "EnemyMRU.h"

EnemyMRU::EnemyMRU(Vector2 startPos, float speed)
{
    position = startPos;
    velocity = { speed, 0 };
}

void EnemyMRU::Update(float dt)
{
    if (!alive) return;

    position.x += velocity.x * dt;

    if (position.x < -60 || position.x > 860)
        alive = false;
}