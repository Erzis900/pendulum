#include <raylib.h>
#include <iostream>
#include "pendulum.h"
#include "constants.h"
#include "inputManager.h"

int main()
{
    InitWindow(Constant::screenWidth, Constant::screenHeight, "Pendulum Simulation");
    SetTargetFPS(60);

    Pendulum pendulum;
    InputManager inputManager;

    while (!WindowShouldClose())
    {
        pendulum.Update();
        inputManager.HandleInput(pendulum);

        BeginDrawing();

            ClearBackground(BLACK);
            pendulum.Draw();

            DrawText(TextFormat("Angle: %.1f rad (%.1f°)", pendulum.GetAngle(), pendulum.GetAngle() * RAD2DEG), 10, 10, 20, LIGHTGRAY);
            DrawText(TextFormat("Angular Velocity: %.1f rad/s (%.1f °/s)", pendulum.GetAngularVelocity(), pendulum.GetAngularVelocity() * RAD2DEG), 10, 35, 20, LIGHTGRAY);
            DrawText(TextFormat("Damping: %.1f", pendulum.GetDamping()), 10, 80, 20, LIGHTGRAY);
            DrawText("Press 'R' to reset", 10, 105, 20, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}