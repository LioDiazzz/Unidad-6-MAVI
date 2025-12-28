#include "Game.h"
#include "GameConfig.h"

Game::Game()
{
    state = GameState::Menu;
    score = 0;
    lives = 3;
    spawnTimer = 0;
}

Game::~Game()
{
    for (Enemy* e : enemies)
        delete e;

    enemies.clear();
}

void Game::ResetGame()
{
    for (Enemy* e : enemies)
        delete e;

    enemies.clear();

    score = 0;
    lives = 3;
    projectile.active = false;
}

void Game::SpawnEnemy()
{
    int type = GetRandomValue(0, 2);

    if (type == 0)
        enemies.push_back(new EnemyMRU({ -40, (float)GetRandomValue(120,400) }, 120));

    else if (type == 1)
        enemies.push_back(new EnemyFall({ (float)GetRandomValue(300,1100), -40 }));

    else
        enemies.push_back(new EnemyBounce({ 1280, 200 }, -140));
}

void Game::UpdatePlaying(float dt)
{
    player.UpdateInput(dt);

    if (IsKeyPressed(KEY_SPACE) && !projectile.active)
        projectile.Shoot(player.position, player.angleDeg, player.power);

    projectile.Update(dt);

    spawnTimer += dt;

    if (spawnTimer >= 1.8f)
    {
        spawnTimer = 0;
        SpawnEnemy();
    }

    for (Enemy* e : enemies)
    {
        if (!e->alive) continue;

        e->Update(dt);

        if (!e->alive)
        {
            lives--;
            if (lives <= 0)
                state = GameState::GameOver;
        }

        if (projectile.active &&
            CheckCollisionRecs(projectile.GetHitbox(), e->GetHitbox()))
        {
            projectile.active = false;
            e->alive = false;
            score += 10;
        }
    }
}

void Game::DrawHUD()
{
    DrawText(TextFormat("Puntaje: %d", score), 20, 20, 24, WHITE);
    DrawText(TextFormat("Vidas: %d", lives), 20, 50, 24, WHITE);

    DrawText(TextFormat("Angulo: %.1f", player.angleDeg), 20, 90, 22, YELLOW);
    DrawText(TextFormat("Potencia: %.1f", player.power), 20, 120, 22, ORANGE);

    DrawRectangleLines(0, 0, screenWidth, screenHeight, RED);
}

void Game::DrawMenu()
{
    DrawText("TIRO OBLICUO", 460, 160, 60, WHITE);
    DrawText("Presiona ENTER para iniciar", 420, 300, 28, YELLOW);
}

void Game::DrawGameOver()
{
    DrawText("PERDISTE", 520, 220, 64, RED);
    DrawText(TextFormat("Puntaje final: %d", score), 500, 310, 32, WHITE);
    DrawText("ENTER para volver al menu", 460, 380, 28, GRAY);
}

void Game::Run()
{
    float dt = GetFrameTime();

    if (state == GameState::Menu)
    {
        if (IsKeyPressed(KEY_ENTER))
        {
            ResetGame();
            state = GameState::Playing;
        }
    }
    else if (state == GameState::Playing)
    {
        UpdatePlaying(dt);
    }
    else if (state == GameState::GameOver)
    {
        if (IsKeyPressed(KEY_ENTER))
            state = GameState::Menu;
    }

    bg.Draw();

    if (state == GameState::Menu)
        DrawMenu();

    else if (state == GameState::Playing)
    {
        for (Enemy* e : enemies)
            if (e->alive) e->Draw();

        player.Draw();
        projectile.Draw();

        DrawHUD();
    }
    else
        DrawGameOver();
}