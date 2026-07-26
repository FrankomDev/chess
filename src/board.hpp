#pragma once

#include "piece.hpp"

#define SQUARE_SIZE 100

extern struct Board {
    public:
        void init();
        void draw();
        BoardSquare get_square(int x, int y);
        void change_square(int x, int y, BoardSquare new_square);
        void clear_square(int x, int y);
        void capture_piece(int x, int y);

        Team currently_moves = Team::White;
    private:
        BoardSquare squares[8][8];
        struct {
            int white = 0;
            int black = 0;
        } score;
} board;
