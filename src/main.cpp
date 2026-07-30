#include "game.hpp"
#include "resourceManager.hpp"
#include <raylib.h>

int main() {

    InitWindow(800, 900, "Chess");
    SetTargetFPS(60);
    resource_manager.load();
    Game game;

    while (!WindowShouldClose()) {

        game.update();

        BeginDrawing();
        ClearBackground({234, 236, 208, 255});
        game.draw();

        EndDrawing();
    }

    resource_manager.unload();
    CloseWindow();
    return 0;
}
