#pragma once

#include "utils.hpp"
#include <functional>
#include <raylib.h>
#include <unordered_map>

enum class Piece {
    Nothing,
    Pawn,
    Bishop,
    Knight,
    Rook,
    Queen,
    King
};

enum class Team {
    None,
    White,
    Black
};

struct BoardSquare {
    Piece piece = Piece::Nothing;
    Team team = Team::None;
};

struct PieceDetails {
    Texture *texture_black = nullptr;
    Texture *texture_white = nullptr;
    std::function<bool(Vector2Int current_position, Vector2Int new_position)> can_move;
    int value;
};

extern struct Pieces {
    std::unordered_map<Piece, PieceDetails> db;
    void init();
} pieces;

bool pawn_can_move(Vector2Int current_position, Vector2Int new_position);
bool bishop_can_move(Vector2Int current_position, Vector2Int new_position);
bool knight_can_move(Vector2Int current_position, Vector2Int new_position);
bool rook_can_move(Vector2Int current_position, Vector2Int new_position);
bool queen_can_move(Vector2Int current_position, Vector2Int new_position);
bool king_can_move(Vector2Int current_position, Vector2Int new_position);
