#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "raylib.h"
#include <cmath>

class Projectile
{
public:
    bool active;

    Vector2 position;
    Vector2 velocity;

    float gravity;

    Projectile();

    void Shoot(Vector2 startPos, float angleDeg, float power);
    void Update(float dt);

    void Draw();
    Rectangle GetHitbox();
};

#endif
