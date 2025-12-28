#include "EnemyBounce.h"
#include "GameConfig.h"

EnemyBounce::EnemyBounce(Vector2 startPos, float vx)
{
    position = startPos;
    velocity = { vx, 0 };

    gravity = 380;
    bounceFactor = -0.7f;
    floorY = screenHeight - 40;
}

void EnemyBounce::Update(float dt)
{
    if (!alive) return;

    velocity.y += gravity * dt;

    position.x += velocity.x * dt;
    position.y += velocity.y * dt;

    if (position.y > floorY)
    {
        position.y = floorY;
        velocity.y *= bounceFactor;
    }

    if (position.x < -100 || position.x > 1400)
        alive = false;
}