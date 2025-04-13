#include "InputComponent.h"

void InputComponent::HandleInput(Paddle& paddle, float dt, const Uint8* keyState) {
    float speed = 300.0f;
    if (keyState[SDL_SCANCODE_LEFT]) {
        paddle.transform.x -= speed * dt;
    }
    if (keyState[SDL_SCANCODE_RIGHT]) {
        paddle.transform.x += speed * dt;
    }

    // 保证挡板不超出边界
    if (paddle.transform.x < 0) paddle.transform.x = 0;
    if (paddle.transform.x + paddle.transform.width > 800)
        paddle.transform.x = 800 - paddle.transform.width;
}
