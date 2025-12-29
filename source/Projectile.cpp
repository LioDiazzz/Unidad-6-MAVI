#include "Projectile.h"
#include "GameConfig.h"

Projectile::Projectile()
{
    active = false;
    gravity = 400;

    texture = LoadTexture("resources/tinta_calamar.png");

    spriteWidth = 40;
    spriteHeight = 39;
}

void Projectile::Shoot(Vector2 startPos, float angleDeg, float power)
{
    position = startPos;

    float rad = angleDeg * DEG2RAD;

    velocity.x = cosf(rad) * power;
    velocity.y = -sinf(rad) * power;

    active = true;
}

void Projectile::Update(float dt)
{
    if (!active) return;

    velocity.y += gravity * dt;

    position.x += velocity.x * dt;
    position.y += velocity.y * dt;

    if (position.x < -40 ||
        position.x > screenWidth + 40 ||
        position.y > screenHeight + 40)
    {
        active = false;
    }
}

Rectangle Projectile::GetHitbox()
{
    return { position.x - 6, position.y - 6, 12, 12 };
}

void Projectile::Draw()
{
    if (!active) return;

    DrawTexturePro(
        texture,
        { 0, 0, (float)texture.width, (float)texture.height },
        {
            position.x - spriteWidth / 2,
            position.y - spriteHeight / 2,
            spriteWidth,
            spriteHeight
        },
        { 0, 0 },
        0,
        WHITE
    );
}