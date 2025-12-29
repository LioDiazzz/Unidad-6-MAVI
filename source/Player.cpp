#include "Player.h"
#include <cmath>

Player::Player()
{
    position = { 80, 520 };

    angleDeg = 45;
    power = 300;

    minAngle = 10;
    maxAngle = 80;

    minPower = 150;
    maxPower = 600;

    texture = LoadTexture("resources/calamar_rosa_player.png"); 
    spriteScale = 0.35f; 
}

void Player::UpdateInput(float dt)
{
    if (IsKeyDown(KEY_UP)) angleDeg += 40 * dt;
    if (IsKeyDown(KEY_DOWN)) angleDeg -= 40 * dt;

    if (angleDeg < minAngle) angleDeg = minAngle;
    if (angleDeg > maxAngle) angleDeg = maxAngle;

    if (IsKeyDown(KEY_RIGHT)) power += 120 * dt;
    if (IsKeyDown(KEY_LEFT)) power -= 120 * dt;

    if (power < minPower) power = minPower;
    if (power > maxPower) power = maxPower;
}

void Player::Draw()
{
    float width = texture.width * spriteScale;
    float height = texture.height * spriteScale;

    DrawTexturePro(
        texture,
        { 0, 0, (float)texture.width, (float)texture.height },
        { position.x, position.y, width, height },
        { width / 2, height / 2 },   
        angleDeg,
        WHITE
    );
}
