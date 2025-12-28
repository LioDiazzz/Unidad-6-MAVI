#include "EnemyFall.h"
#include "GameConfig.h"

EnemyFall::EnemyFall(Vector2 startPos)
{
    position = startPos;
    velocity = { 0,0 };
    gravity = 300;
}

void EnemyFall::Update(float dt)
{
    if (!alive) return;

    velocity.y += gravity * dt;
    position.y += velocity.y * dt;

    if (position.y > screenHeight +40)
        alive = false;
}