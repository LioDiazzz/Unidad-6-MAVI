#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "raylib.h"

class Background
{
public:
    Background();
    ~Background();

    void Draw();

private:
    Texture2D texture;
};

#endif
