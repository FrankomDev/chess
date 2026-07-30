#pragma once

#include "board.hpp"
#include "utils.hpp"
#include <raylib.h>
#include <utility>

struct Game {
    public:
        void update();
        void draw();

        Game() {
            pieces.init();
            board.init();
            board.piece_in_move = &currently_holding;
        };

    private:
        std::pair<BoardSquare, Vector2Int> currently_holding = {{Piece::Nothing, Team::None}, {-1, -1}};
        void clear_holding();
        void change_moving_team();
        void handle_mouse_clicks();
        void make_move(int x, int y);
};
