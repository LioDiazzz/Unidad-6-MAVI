#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

class Player
{
    public:

        Vector2 position;

        float angleDeg;
        float power;

        float minAngle;
        float maxAngle;

        float minPower;
        float maxPower;

        Player();

        void UpdateInput(float dt);
        void Draw();
    private:
        Texture2D texture;
        float spriteScale;
};

#endif
