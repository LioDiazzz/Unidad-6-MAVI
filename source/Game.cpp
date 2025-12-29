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
        enemies.push_back(new EnemyFall({ (float)GetRandomValue(40,screenWidth - 40), -40 }));

    else
        enemies.push_back(new EnemyBounce({ (float)GetRandomValue(120, screenWidth - 120), 200 }, -140));
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
    DrawRectangleLines(0, 0, screenWidth, screenHeight, RED);

    DrawText(TextFormat("PUNTOS: %d", score), 20, 20, 20, WHITE);
    DrawText(TextFormat("VIDAS: %d", lives), GetScreenWidth() - 110, 20, 20, WHITE);

    DrawText(TextFormat("ANGULO: %.1f", player.angleDeg), 20, 90, 22, YELLOW);
    DrawText(TextFormat("POTENCIA: %.1f", player.power), 20, GetScreenHeight() - 40, 20, ORANGE);

}

void Game::DrawMenu()
{
    DrawText("DEFENSA DEL ARRECIFE", 400 - (MeasureText("DEFENSA DEL ARRECIFE", 40)/ 2), 200, 40, WHITE);
    DrawText("Presiona ENTER para iniciar", 400 - (MeasureText("Presiona ENTER para iniciar", 20) / 2), 350, 20, YELLOW);
}

void Game::DrawGameOver()
{
    DrawText("PERDISTE", 400 - (MeasureText("PERDISTE", 40) / 2), 200, 40, RED);
    DrawText(TextFormat("Puntaje final: %d", score), 310, 300, 25, WHITE);
    DrawText("ENTER para volver al menu", 265, 380, 20, GRAY);
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