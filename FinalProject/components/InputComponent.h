#pragma once
#include "../entities/Paddle.h"
#include <SDL.h>

/**
 * @class InputComponent
 * @brief Handles player input and controls the paddle.
 */
class InputComponent {
public:
    /**
     * @brief Processes keyboard input to move the paddle.
     * @param paddle Reference to the paddle entity
     * @param dt Delta time for frame-independent movement
     * @param keyState Pointer to SDL key state array
     */
    void HandleInput(Paddle& paddle, float dt, const Uint8* keyState);
};