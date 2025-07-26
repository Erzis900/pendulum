#include <raylib.h>
#include <vector>

class Pendulum
{
public:
    Pendulum();
    void Update();
    void Draw();
    void Reset();
    void ResetSimulation();

    float GetAngle() const { return angle; }
    float GetAngularVelocity() const { return angularVelocity; }
    float GetDamping() const { return damping; }
    void SetDamping(float newDamping) { damping = newDamping; }

    Vector2 GetBob() const { return bob; }
    Vector2 GetPivot() const { return pivot; }
    void SetPivot(Vector2 newPivot) { pivot = newPivot; }

    float GetBobRadius() const {return bobRadius;}
    bool GetIsDragging() const { return isDragging; }
    void SetIsDragging(bool dragging) { isDragging = dragging; }
    void SetAngularVelocity(float velocity) { angularVelocity = velocity; }
    std::vector<Vector2>& GetTrailPoints() { return trailPoints; }
private:
    float angle;
    float angularVelocity;
    float damping;

    Vector2 pivot;
    Vector2 bob;
    float bobRadius;
    bool isDragging;

    std::vector<Vector2> trailPoints;
    int maxTrailLength;

    float MetersToPixels(float meters);

    void DragPendulum();
    void SimulatePhysics();
    void UpdateTrail();
};