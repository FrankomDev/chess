#include "piece.hpp"
#include "board.hpp"
#include "resourceManager.hpp"
#include "utils.hpp"
#include <algorithm>

Pieces pieces;

void Pieces::init() {
    db[Piece::Pawn]   = {&resource_manager.black_pawn, &resource_manager.white_pawn, pawn_can_move, 1};
    db[Piece::Bishop] = {&resource_manager.black_bishop, &resource_manager.white_bishop, bishop_can_move, 3};
    db[Piece::Knight] = {&resource_manager.black_knight, &resource_manager.white_knight, knight_can_move, 3};
    db[Piece::Rook]   = {&resource_manager.black_rook, &resource_manager.white_rook, rook_can_move, 5};
    db[Piece::Queen]  = {&resource_manager.black_queen, &resource_manager.white_queen, queen_can_move, 9};
    db[Piece::King]   = {&resource_manager.black_king, &resource_manager.white_king, king_can_move, 0};
}

bool pawn_can_move(Vector2Int current_position, Vector2Int new_position) {
    int max_hop = (current_position.y == 6) ? 2 : 1;
    BoardSquare new_position_square = board.get_square(new_position.x, new_position.y);

    // going 1-2 hop forward
    if (current_position.x == new_position.x && (current_position.y - new_position.y == 1 || current_position.y - new_position.y == max_hop)
        && new_position_square.piece == Piece::Nothing)
            return true;

    // capture piece
    else if (current_position.y - new_position.y == 1 && (current_position.x - new_position.x == 1 || current_position.x - new_position.x == -1 )
        && new_position_square.team != board.currently_moves && new_position_square.piece != Piece::Nothing) {
            board.capture_piece(new_position.x, new_position.y);
            return true;
    }

    return false;
}

bool bishop_can_move(Vector2Int current_position, Vector2Int new_position) {return false;}

bool knight_can_move(Vector2Int current_position, Vector2Int new_position) {
    Vector2Int distance = {
        .x = std::max(current_position.x, new_position.x) - std::min(current_position.x, new_position.x),
        .y = std::max(current_position.y, new_position.y) - std::min(current_position.y, new_position.y),
    };

    if ((distance.x == 2 && distance.y == 1) || (distance.x == 1 && distance.y == 2)) {
        if (board.get_square(new_position.x, new_position.y).piece == Piece::Nothing)
            return true;
        else if (board.get_square(new_position.x, new_position.y).team != board.currently_moves) {
            board.capture_piece(new_position.x, new_position.y);
            return true;
        }
    }

    return false;
}

bool rook_can_move(Vector2Int current_position, Vector2Int new_position) {
    enum {
       Up, Down, Right, Left
    } direction;

    if (current_position.x != new_position.x && current_position.y != new_position.y)
        return false;
    else if (current_position.x == new_position.x && current_position.y != new_position.y)
        direction = (current_position.y > new_position.y) ? Up : Down;
    else if (current_position.x != new_position.x && current_position.y == new_position.y)
        direction = (current_position.x > new_position.x) ? Left : Right;

    switch (direction) {
        case Up: {
            for (int y=current_position.y; y>new_position.y; y--) {
                if (board.get_square(current_position.x, y).piece != Piece::Nothing)
                    return false;
            }
            break;
        };
        case Down: {
            for (int y=current_position.y; y<new_position.y; y++) {
                if (board.get_square(current_position.x, y).piece != Piece::Nothing)
                    return false;
            }
            break;
        };
        case Left: {
            for (int x=current_position.x; x>new_position.x; x--) {
                if (board.get_square(x, current_position.y).piece != Piece::Nothing)
                    return false;
            }
            break;
        };
        case Right: {
            for (int x=current_position.x; x<new_position.x; x++) {
                if (board.get_square(x, current_position.y).piece != Piece::Nothing)
                    return false;
            }
            break;
        };
        default: break;
    }

    if (board.get_square(new_position.x, new_position.y).piece == Piece::Nothing)
        return true;
    else if (board.get_square(new_position.x, new_position.y).team != board.currently_moves) {
        board.capture_piece(new_position.x, new_position.y);
        return true;
    }

    return false;
}

bool queen_can_move(Vector2Int current_position, Vector2Int new_position) {return false;}
bool king_can_move(Vector2Int current_position, Vector2Int new_position) {return false;}
