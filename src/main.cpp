#include <raylib.h>
#include "game.h"
using namespace std;

double lastTimeUpdate = 0;
bool EventTriggered(double interval) {
    double currentTime = GetTime();
        if (currentTime - lastTimeUpdate >= interval)
        {
            lastTimeUpdate = currentTime;
            return true;
        }
        return false;
}
int main() 
{
    Color darkblue = {44, 44, 127, 255};
    InitWindow(300, 600, "Tetris");
    SetTargetFPS(60);
    Game game = Game();
    while (WindowShouldClose() == false)
    {
        game.HandleInput();
        if (EventTriggered(0.5))
        {
            game.MoveBlockDown();
        }
        
        BeginDrawing();
        ClearBackground(darkblue);
        game.Draw();
        EndDrawing();
    }
    
    CloseWindow();
}