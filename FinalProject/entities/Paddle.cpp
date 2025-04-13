#include "Paddle.h"

Paddle::Paddle(float x, float y, float w, float h)
    : transform(x, y, w, h) {}

void Paddle::Render(SDL_Renderer* renderer) {
    SDL_Rect rect = {
        static_cast<int>(transform.x),
        static_cast<int>(transform.y),
        static_cast<int>(transform.width),
        static_cast<int>(transform.height)
    };
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // white
    SDL_RenderFillRect(renderer, &rect);
}
