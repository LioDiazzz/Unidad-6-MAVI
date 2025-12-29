#include "EnemyMRU.h"

EnemyMRU::EnemyMRU(Vector2 startPos, float speed)
{
    position = startPos;
    velocity = { speed, 0 };

    radius = 55;

    texture = LoadTexture("resources/tiburon_azul.png");
}

void EnemyMRU::Update(float dt)
{
    if (!alive) return;

    position.x += velocity.x * dt;

    if (position.x < -60 || position.x > 860)
        alive = false;
}

//void EnemyMRU::Draw()
//{
//    if (!alive) return;
//
//    DrawTexturePro(
//        texture,
//        { 0,0,(float)texture.width,(float)texture.height },
//        { position.x - radius, position.y - radius, radius * 2, radius * 2 },
//        { radius, radius },
//        0,
//        WHITE
//    );
//}

//void EnemyMRU::Draw()
//{
//    if (!alive) return;
//
//    float renderWidth = 170;
//    float renderHeight = 150;
//
//    DrawTexturePro(
//        texture,
//        { 0,0,(float)texture.width,(float)texture.height },
//        {
//            position.x - renderWidth / 2,
//            position.y - renderHeight / 2,
//            renderWidth,
//            renderHeight
//        },
//        { renderWidth / 2, renderHeight / 2 },
//        0,
//        WHITE
//    );
//}

void EnemyMRU::Draw()
{
    if (!alive) return;

    float renderWidth = 170;
    float renderHeight = 150;

    DrawTexturePro(
        texture,
        { 0, 0, (float)texture.width, (float)texture.height },
        { position.x - texture.width / 2,
          position.y - texture.height / 2,
          (float)texture.width,
          (float)texture.height },
        { 0, 0 },
        0,
        WHITE
    );
}