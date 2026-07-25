#pragma once

#include <raylib.h>
extern struct ResourceManager {
    void load();
    void unload();

    Texture2D white_bishop;
    Texture2D white_king;
    Texture2D white_knight;
    Texture2D white_pawn;
    Texture2D white_queen;
    Texture2D white_rook;

    Texture2D black_bishop;
    Texture2D black_king;
    Texture2D black_knight;
    Texture2D black_pawn;
    Texture2D black_queen;
    Texture2D black_rook;

} resource_manager;
