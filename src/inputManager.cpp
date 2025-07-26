#include "inputManager.h"
#include "pendulum.h"
#include <raymath.h>

InputManager::InputManager()
{
}

void InputManager::HandleInput(Pendulum &pendulum)
{
    HandleMouseInput(pendulum);
    HandleKeyboardInput(pendulum);
}

void InputManager::HandleMouseInput(Pendulum &pendulum)
{
    Vector2 mousePos = GetMousePosition();
    float distanceToBob = Vector2Distance(mousePos, pendulum.GetBob());

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && distanceToBob < pendulum.GetBobRadius())
    {
        pendulum.SetIsDragging(true);
        pendulum.SetAngularVelocity(0.f);
        pendulum.GetTrailPoints().clear();
    }

    if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON) && pendulum.GetIsDragging())
    {
        pendulum.SetIsDragging(false);
    }

    if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
    {
        pendulum.SetPivot(GetMousePosition());
        pendulum.ResetSimulation();
    }

    if (IsKeyPressed(KEY_R))
    {
        pendulum.Reset();
    }
}

void InputManager::HandleKeyboardInput(Pendulum &pendulum)
{
    if (IsKeyPressed(KEY_UP))
    {
        pendulum.SetDamping(pendulum.GetDamping() + 0.1f);
    }
    if (IsKeyPressed(KEY_DOWN) && pendulum.GetDamping() > 0.1f)
    {
        pendulum.SetDamping(pendulum.GetDamping() - 0.1f);
    }
}