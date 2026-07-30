#include "game.hpp"
#include "board.hpp"
#include "piece.hpp"
#include "utils.hpp"
#include <raylib.h>
#include <string>

void Game::handle_mouse_clicks() {

    Vector2 mouse = GetMousePosition();

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        for (int x=0; x<8; x++) {
            for (int y=0; y<8; y++) {
                Vector2 position = {
                    .x = (float)x*SQUARE_SIZE,
                    .y = (float)y*SQUARE_SIZE
                };
                if (CheckCollisionPointRec(mouse, {position.x, position.y, SQUARE_SIZE, SQUARE_SIZE})) {
                    if (currently_holding.first.piece == Piece::Nothing) {
                        if (board.get_square(x, y).team == board.currently_moves) {
                            currently_holding.first = board.get_square(x, y);
                            currently_holding.second = {x, y};
                        }
                    } else {
                        if (x == currently_holding.second.x && y == currently_holding.second.y) {
                            clear_holding();
                        } else {
                            make_move(x, y);
                        }
                    }
                    return;
                }
            }
        }
    }
}

void Game::update() {
    handle_mouse_clicks();
}

void Game::draw() {
    board.draw();

    DrawLineEx({0, 800}, {800, 800}, 5.0f, BLACK);

    std::string white = "White: " + std::to_string(board.score.white);
    std::string black = std::to_string(board.score.black) + " :Black";
    Font font = GetFontDefault();
    Vector2 white_v = MeasureTextEx(font, white.c_str(), 40, 4);
    Vector2 black_v = MeasureTextEx(font, black.c_str(), 40, 4);

    DrawText(white.c_str(), 20, 850-white_v.y/2, 40, BLACK);
    DrawText(black.c_str(), 780-black_v.x, 850-black_v.y/2, 40, BLACK);

    if (currently_holding.first.piece != Piece::Nothing) {
        Vector2 mouse = GetMousePosition();
        Texture texture = (currently_holding.first.team == Team::White) ? *pieces.db[currently_holding.first.piece].texture_white : *pieces.db[currently_holding.first.piece].texture_black;
        DrawTextureEx(texture, {mouse.x-texture.width*SCALE/2, mouse.y-texture.height*SCALE/2}, 0, SCALE, WHITE);
    }
}

void Game::clear_holding() {
    currently_holding = {{Piece::Nothing, Team::None}, {-1, -1}};
}

void Game::change_moving_team() {
    board.currently_moves = (board.currently_moves == Team::White) ? Team::Black : Team::White;
}

void Game::make_move(int x, int y) {
    BoardSquare current_square = board.get_square(x, y);
    if (current_square.piece == Piece::King)
        return;
    if (pieces.db[currently_holding.first.piece].can_move(currently_holding.second, {x, y}, false)) {
        board.change_square(x, y, currently_holding.first);
        board.clear_square(currently_holding.second.x, currently_holding.second.y);
        if (board.is_checkmate()) {
            board.change_square(currently_holding.second.x, currently_holding.second.y, currently_holding.first);
            board.change_square(x, y, current_square);
        } else {
            board.change_square(currently_holding.second.x, currently_holding.second.y, currently_holding.first);
            board.change_square(x, y, current_square);
            if (pieces.db[currently_holding.first.piece].can_move(currently_holding.second, {x, y}, true)) { //checking again because this time it can capture (maybe fix)
                board.change_square(x, y, currently_holding.first);
                board.clear_square(currently_holding.second.x, currently_holding.second.y);
                clear_holding();
                change_moving_team();
            }
        }
    }
}
