#include "Background.h"

Background::Background()
{
    color = DARKBLUE;
}

void Background::Draw()
{
    ClearBackground(color);
}