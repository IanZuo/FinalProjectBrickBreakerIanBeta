#include "Ball.h"

Ball::Ball(float x, float y, float speed)
    : transform(x, y, 15, 15), velX(speed), velY(-speed) {}

void Ball::Update(float dt) {
    transform.x += velX * dt;
    transform.y += velY * dt;

    // 边界反弹
    if (transform.x <= 0 || transform.x + transform.width >= 800)
        velX = -velX;
    if (transform.y <= 0)
        velY = -velY;
}

void Ball::Render(SDL_Renderer* renderer) {
    SDL_Rect rect = {
        static_cast<int>(transform.x),
        static_cast<int>(transform.y),
        static_cast<int>(transform.width),
        static_cast<int>(transform.height)
    };
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255); // yellow
    SDL_RenderFillRect(renderer, &rect);
}
