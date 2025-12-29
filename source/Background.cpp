#include "Background.h"
#include "raylib.h"

Background::Background()
{
    texture = LoadTexture("resources/FondoU5.png"); 
}

Background::~Background()
{
    UnloadTexture(texture);
}

void Background::Draw()
{
    DrawTexturePro(
        texture,
        { 0, 0, (float)texture.width, (float)texture.height },
        { 0, 0, (float)GetScreenWidth(), (float)GetScreenHeight() },
        { 0, 0 },
        0,
        WHITE
    );
}

