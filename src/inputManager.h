class Pendulum;

class InputManager
{
public:
    InputManager();
    void HandleInput(Pendulum& pendulum);

private:
    void HandleMouseInput(Pendulum& pendulum);
    void HandleKeyboardInput(Pendulum& pendulum);
};