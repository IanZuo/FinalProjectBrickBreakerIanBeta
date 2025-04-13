/**
 * @file Ball.h
 * @brief Defines the behavior and rendering of the ball entity.
 */

 #pragma once
 #include "../components/TransformComponent.h"
 #include <SDL.h>
 
 /**
  * @class Ball
  * @brief Represents the ball entity in the game that bounces around.
  */
 class Ball {
 public:
     TransformComponent transform;  ///< Position and size of the ball
     float velX;  ///< X velocity
     float velY;  ///< Y velocity
 
     /**
      * @brief Constructs a ball with initial position and optional speed.
      * @param x X-coordinate
      * @param y Y-coordinate
      * @param speed Initial speed of the ball
      */
     Ball(float x, float y, float speed = 250.0f);
 
     /**
      * @brief Updates the ball's position and handles screen edge bouncing.
      * @param dt Delta time
      */
     void Update(float dt);
 
     /**
      * @brief Renders the ball.
      * @param renderer SDL renderer pointer
      */
     void Render(SDL_Renderer* renderer);
 };