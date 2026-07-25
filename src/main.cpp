#include "game.hpp"
#include "resourceManager.hpp"
#include <raylib.h>

int main() {

    InitWindow(800, 800, "Chess");
    SetTargetFPS(60);
    resource_manager.load();
    Game game;

    while (!WindowShouldClose()) {

        game.update();

        BeginDrawing();
        ClearBackground(GRAY);
        game.draw();

        EndDrawing();
    }

    resource_manager.unload();
    CloseWindow();
    return 0;
}
