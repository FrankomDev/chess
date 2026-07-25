#include <raylib.h>
#include "board.hpp"
#include "piece.hpp"
#include "utils.hpp"

Board board;

void Board::init() {
    squares[0][0] = {Piece::Rook, Team::Black};
    squares[1][0] = {Piece::Knight, Team::Black};
    squares[2][0] = {Piece::Bishop, Team::Black};
    squares[3][0] = {Piece::Queen, Team::Black};
    squares[4][0] = {Piece::King, Team::Black};
    squares[5][0] = {Piece::Bishop, Team::Black};
    squares[6][0] = {Piece::Knight, Team::Black};
    squares[7][0] = {Piece::Rook, Team::Black};
    for (int i=0; i<8; i++) {
        squares[i][1] = {Piece::Pawn, Team::Black};
        squares[i][6] = {Piece::Pawn, Team::White};
    }
    squares[0][7] = {Piece::Rook, Team::White};
    squares[1][7] = {Piece::Knight, Team::White};
    squares[2][7] = {Piece::Bishop, Team::White};
    squares[3][7] = {Piece::Queen, Team::White};
    squares[4][7] = {Piece::King, Team::White};
    squares[5][7] = {Piece::Bishop, Team::White};
    squares[6][7] = {Piece::Knight, Team::White};
    squares[7][7] = {Piece::Rook, Team::White};
}

void Board::draw() {
    for (int x=0; x<8; x++) {
        static enum {
            Black, White
        } color = White;
        for (int y=0; y<8; y++) {
            Vector2 position = {
                .x = (float)x*SQUARE_SIZE,
                .y = (float)y*SQUARE_SIZE
            };
            DrawRectangle(position.x, position.y, SQUARE_SIZE, SQUARE_SIZE, (color == White) ? (Color){234, 236, 208, 255} : (Color){118, 149, 86, 255});
            color = (color == White) ? Black : White;

            BoardSquare square = get_square(x, y);
            if (square.piece != Piece::Nothing) {
                Texture texture = (square.team == Team::White) ? *pieces.db[square.piece].texture_white : *pieces.db[square.piece].texture_black;
                //DrawTexture(texture, position.x, position.y, WHITE);
                DrawTextureEx(texture, {position.x+50-texture.width*SCALE/2, position.y}, 0, SCALE, WHITE);
            }
        }
        color = (color == White) ? Black : White;
    }
}

BoardSquare Board::get_square(int x, int y) {
    return (currently_moves == Team::White) ? squares[x][y] : squares[7-x][7-y];
}

void Board::change_square(int x, int y, BoardSquare new_square) {
    if (currently_moves == Team::White)
        squares[x][y] = new_square;
    else
        squares[7-x][7-y] = new_square;
}

void Board::clear_square(int x, int y) {
    if (currently_moves == Team::White)
        squares[x][y] = {Piece::Nothing, Team::None};
    else
        squares[7-x][7-y] = {Piece::Nothing, Team::None};
}
