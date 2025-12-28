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
    DrawCircleV(position, 18, SKYBLUE);

    Vector2 aim =
    {
        position.x + 40 * std::cos(DEG2RAD * angleDeg),
        position.y - 40 * std::sin(DEG2RAD * angleDeg)
    };

    DrawLineEx(position, aim, 3, YELLOW);
}