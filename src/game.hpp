#pragma once

#include "piece.hpp"
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
        };

    private:
        std::pair<BoardSquare, Vector2Int> currently_holding = {{Piece::Nothing, Team::None}, {-1, -1}};
        void clear_holding();
        void handle_mouse_clicks();
};
