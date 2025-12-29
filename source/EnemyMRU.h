#ifndef ENEMY_MRU_H
#define ENEMY_MRU_H

#include "Enemy.h"

class EnemyMRU : public Enemy
{
    public:
        EnemyMRU(Vector2 startPos, float speed);

        void Update(float dt) override;
        void Draw() override;
};

#endif
