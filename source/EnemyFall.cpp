#include "EnemyFall.h"
#include "GameConfig.h"

EnemyFall::EnemyFall(Vector2 startPos)
{
    position = startPos;
    velocity = { 0,0 };
    gravity = 300;

    radius = 40;

    texture = LoadTexture("resources/pez_naranja.png");
}

void EnemyFall::Update(float dt)
{
    if (!alive) return;

    velocity.y += gravity * dt;
    position.y += velocity.y * dt;

    if (position.y > screenHeight +40)
        alive = false;
}

void EnemyFall::Draw()
{
    if (!alive) return;

    DrawTexturePro(
        texture,
        { 0, 0, (float)texture.width, (float)texture.height },
        { position.x - radius,
          position.y - radius,
          radius * 2,
          radius * 2 },
        { 0, 0 },
        0,
        WHITE
    );
}