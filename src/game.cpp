#include "game.hpp"
#include "board.hpp"
#include "piece.hpp"
#include "utils.hpp"
#include <raylib.h>

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
                            board.clear_square(x, y);
                        }
                    } else {
                        if (x == currently_holding.second.x && y == currently_holding.second.y) {
                            board.change_square(x, y, currently_holding.first);
                            clear_holding();
                        } else {

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

    //if (IsKeyPressed(KEY_R))
    //    board.currently_moves = (board.currently_moves == Team::White) ? Team::Black : Team::White;
}

void Game::draw() {
    board.draw();

    if (currently_holding.first.piece != Piece::Nothing) {
        Vector2 mouse = GetMousePosition();
        Texture texture = (currently_holding.first.team == Team::White) ? *pieces.db[currently_holding.first.piece].texture_white : *pieces.db[currently_holding.first.piece].texture_black;
        DrawTextureEx(texture, {mouse.x-texture.width*SCALE/2, mouse.y-texture.height*SCALE/2}, 0, SCALE, WHITE);
    }
}

void Game::clear_holding() {
    currently_holding = {{Piece::Nothing, Team::None}, {-1, -1}};
}
