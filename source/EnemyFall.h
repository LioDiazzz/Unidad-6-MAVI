#ifndef ENEMY_FALL_H
#define ENEMY_FALL_H

#include "Enemy.h"

class EnemyFall : public Enemy
{
    public:
        float gravity;

        EnemyFall(Vector2 startPos);

        void Update(float dt) override;
        void Draw() override;
};

#endif
