#pragma once

struct TransformComponent {
    float x, y;
    float width, height;

    TransformComponent(float _x, float _y, float _w, float _h)
        : x(_x), y(_y), width(_w), height(_h) {}
};
