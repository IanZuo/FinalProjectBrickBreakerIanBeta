/**
 * @file Paddle.hpp
 * @brief Defines the player-controlled paddle in the Brick Breaker game.
 */

 #pragma once
 #include "../components/TransformComponent.h"
 #include <SDL.h>
 
 /**
  * @class Paddle
  * @brief Represents the player's paddle used to bounce the ball.
  */
 class Paddle {
 public:
     TransformComponent transform;  ///< Position and size of the paddle
 
     /**
      * @brief Constructs a paddle with optional width and height.
      * @param x X-coordinate of the paddle
      * @param y Y-coordinate of the paddle
      * @param w Width of the paddle (default: 100.0f)
      * @param h Height of the paddle (default: 15.0f)
      */
     Paddle(float x, float y, float w = 100.0f, float h = 15.0f);
 
     /**
      * @brief Renders the paddle using the given SDL renderer.
      * @param renderer SDL_Renderer used to draw the paddle
      */
     void Render(SDL_Renderer* renderer);
 };
 