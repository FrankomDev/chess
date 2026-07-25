#include "resourceManager.hpp"
#include <raylib.h>

ResourceManager resource_manager;

void ResourceManager::load() {
    white_bishop = LoadTexture("../assets/bishop_white.png");
    white_king = LoadTexture("../assets/king_white.png");
    white_knight = LoadTexture("../assets/knight_white.png");
    white_pawn = LoadTexture("../assets/pawn_white.png");
    white_queen = LoadTexture("../assets/queen_white.png");
    white_rook = LoadTexture("../assets/rook_white.png");

    black_bishop = LoadTexture("../assets/bishop_black.png");
    black_king = LoadTexture("../assets/king_black.png");
    black_knight = LoadTexture("../assets/knight_black.png");
    black_pawn = LoadTexture("../assets/pawn_black.png");
    black_queen = LoadTexture("../assets/queen_black.png");
    black_rook = LoadTexture("../assets/rook_black.png");
}

void ResourceManager::unload() {
    UnloadTexture(white_bishop);
    UnloadTexture(white_king);
    UnloadTexture(white_knight);
    UnloadTexture(white_pawn);
    UnloadTexture(white_queen);
    UnloadTexture(white_rook);

    UnloadTexture(black_bishop);
    UnloadTexture(black_king);
    UnloadTexture(black_knight);
    UnloadTexture(black_pawn);
    UnloadTexture(black_queen);
    UnloadTexture(black_rook);
}
