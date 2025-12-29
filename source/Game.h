#ifndef GAME_H
#define GAME_H

#include <vector>

#include "raylib.h"

#include "Background.h"
#include "Player.h"
#include "Projectile.h"

#include "Enemy.h"
#include "EnemyMRU.h"
#include "EnemyFall.h"
#include "EnemyBounce.h"

enum class GameState
{
    Menu,
    Playing,
    GameOver
};

class Game
{
public:

    GameState state;

    Background bg;
    Player player;
    Projectile projectile;

    std::vector<Enemy*> enemies;

    int score;
    int lives;

    float spawnTimer;

    Game();
    ~Game();

    void ResetGame();
    void SpawnEnemy();

    void UpdatePlaying(float dt);

    void DrawHUD();
    void DrawMenu();
    void DrawGameOver();

    void Run();

};

#endif
