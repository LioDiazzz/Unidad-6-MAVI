#include "Enemy.h"
#include "GameConfig.h"

Enemy::Enemy()
{
    position = { 0,0 };
    velocity = { 0,0 };
    radius = 20;
    alive = true;

    hasTexture = false;
}

Enemy::~Enemy()
{
    UnloadSprite();
}

void Enemy::LoadSprite(const std::string& path)
{
    texture = LoadTexture(path.c_str());
    hasTexture = true;
}

void Enemy::UnloadSprite()
{
    if (hasTexture)
    {
        UnloadTexture(texture);
        hasTexture = false;
    }
}

Rectangle Enemy::GetHitbox()
{
    return { position.x - radius, position.y - radius, radius * 2, radius * 2 };
}

void Enemy::Draw()
{
    if (!alive) return;

    if (hasTexture)
    {
        DrawTexturePro(
            texture,
            { 0,0,(float)texture.width,(float)texture.height },
            { position.x, position.y, radius * 2, radius * 2 },
            { radius, radius },
            0,
            WHITE
        );
    }
    else
    {
        DrawCircleV(position, radius, RED);
    }
}