#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"
#include <string>

class Enemy
{
public:

    Vector2 position;
    Vector2 velocity;

    float radius;
    bool alive;

    // Sprite
    Texture2D texture;
    bool hasTexture;

    Enemy();
    virtual ~Enemy();

    virtual void Update(float dt) = 0;
    virtual void Draw();

    Rectangle GetHitbox();

    void LoadSprite(const std::string& path);
    void UnloadSprite();
};

#endif
