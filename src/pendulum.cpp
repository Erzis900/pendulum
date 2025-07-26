#include "pendulum.h"
#include "constants.h"
#include <cmath>
#include <raymath.h>

float Pendulum::MetersToPixels(float meters)
{
    return meters * 200.0f;
}

Pendulum::Pendulum()
:angle(Constant::initialAngle),
 angularVelocity(Constant::initialAngularVelocity),
 damping(Constant::initialDamping),
 pivot(Constant::initialPivot),
 bob({ 0.0f, 0.0f }),
 bobRadius(30.f),
 isDragging(false),
 maxTrailLength(30)
{
    trailPoints.reserve(maxTrailLength);
}

void Pendulum::DragPendulum()
{
    Vector2 mousePos = GetMousePosition();
    Vector2 dir = Vector2Subtract(mousePos, pivot);

    angle = atan2f(dir.x, dir.y);

    bob.x = pivot.x + MetersToPixels(Constant::length) * sin(angle);
    bob.y = pivot.y + MetersToPixels(Constant::length) * cos(angle);
}

void Pendulum::SimulatePhysics()
{
    float dt = GetFrameTime();
    float angularAcceleration = -(Constant::gravity / Constant::length) * sin(angle);
    angularAcceleration -= damping * angularVelocity;

    angularVelocity += angularAcceleration * dt;
    angle += angularVelocity * dt;

    bob.x = pivot.x + MetersToPixels(Constant::length) * sin(angle);
    bob.y = pivot.y + MetersToPixels(Constant::length) * cos(angle);
}

void Pendulum::UpdateTrail()
{
    trailPoints.push_back(bob);
    if(trailPoints.size() > maxTrailLength)
    {
        trailPoints.erase(trailPoints.begin());
    }
}

void Pendulum::ResetSimulation()
{
    angle = Constant::initialAngle;
    angularVelocity = Constant::initialAngularVelocity;
    trailPoints.clear();
}

void Pendulum::Update()
{
    if (isDragging)
    {
        DragPendulum();
    }
    else
    {
        SimulatePhysics();
        UpdateTrail();
    }
}

void Pendulum::Draw()
{
    DrawLineV(pivot, bob, WHITE);
    DrawCircleV(pivot, 5.f, WHITE);
    DrawCircleV(bob, bobRadius, WHITE);

    for (int i = 0; i < trailPoints.size(); ++i)
    {
        float alpha = static_cast<float>(i) / trailPoints.size();

        Color color = Fade(WHITE, alpha);
        DrawCircleV(trailPoints[i], 3.f, color);
    }
}

void Pendulum::Reset()
{
    ResetSimulation();
    pivot = Constant::initialPivot;
}