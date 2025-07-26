#include "constants.h"
#include <cmath>

namespace Constant
{
    const float gravity = 9.81f;
    const float length = 2.f;
    const float initialAngle = M_PI / 2;
    const float initialAngularVelocity = 0.0f;
    const float initialDamping = 0.5f;
    const Vector2 initialPivot = { static_cast<float>(screenWidth) / 2, 100.0f };

    const int screenWidth = 1200;
    const int screenHeight = 720;
};