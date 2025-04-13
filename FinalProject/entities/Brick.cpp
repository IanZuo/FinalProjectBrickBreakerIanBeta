#include "Brick.h"

Brick::Brick(float x, float y, float w, float h, int hp)
    : transform(x, y, w, h), hitPoints(hp) {}

void Brick::TakeHit() {
    hitPoints--;
    if (hitPoints <= 0) {
        destroyed = true;
    }
}

void Brick::Render(SDL_Renderer* renderer) {
    if (destroyed) return;

    SDL_Rect rect = {
        static_cast<int>(transform.x),
        static_cast<int>(transform.y),
        static_cast<int>(transform.width),
        static_cast<int>(transform.height)
    };

    if (hitPoints == 1) {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // 红色
    } else if (hitPoints == 2) {
        SDL_SetRenderDrawColor(renderer, 255, 165, 0, 255); // 橙色
    } else {
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255); // 黄色
    }

    SDL_RenderFillRect(renderer, &rect);
}
