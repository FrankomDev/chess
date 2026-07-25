#include "piece.hpp"
#include "resourceManager.hpp"

Pieces pieces;

void Pieces::init() {
    db[Piece::Pawn]   = {&resource_manager.black_pawn, &resource_manager.white_pawn};
    db[Piece::Bishop] = {&resource_manager.black_bishop, &resource_manager.white_bishop};
    db[Piece::Knight] = {&resource_manager.black_knight, &resource_manager.white_knight};
    db[Piece::Rook]   = {&resource_manager.black_rook, &resource_manager.white_rook};
    db[Piece::Queen]  = {&resource_manager.black_queen, &resource_manager.white_queen};
    db[Piece::King]   = {&resource_manager.black_king, &resource_manager.white_king};
}
