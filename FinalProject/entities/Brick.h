/**
 * @file Brick.h
 * @brief Defines the destructible bricks used in the game.
 */

 #pragma once
 #include "../components/TransformComponent.h"
 #include <SDL.h>
 
 /**
  * @class Brick
  * @brief Represents a destructible block in the game.
  */
 class Brick {
 public:
     TransformComponent transform;  ///< Brick position and size
     bool destroyed = false;        ///< Whether the brick has been destroyed
     int hitPoints = 1;             ///< Number of hits required to destroy the brick
 
     /**
      * @brief Constructs a brick with specified location, size, and hit points.
      * @param x X-coordinate
      * @param y Y-coordinate
      * @param w Width
      * @param h Height
      * @param hp Hit points (default = 1)
      */
     Brick(float x, float y, float w = 60, float h = 20, int hp = 1);
 
     /**
      * @brief Applies damage to the brick. Destroys it if hit points reach 0.
      */
     void TakeHit();
 
     /**
      * @brief Renders the brick.
      * @param renderer SDL renderer pointer
      */
     void Render(SDL_Renderer* renderer);
 };