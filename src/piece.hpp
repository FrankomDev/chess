#pragma once

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
};

extern struct Pieces {
    std::unordered_map<Piece, PieceDetails> db;
    void init();
} pieces;
