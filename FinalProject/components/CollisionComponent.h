/**
 * @file CollisionComponent.h
 * @brief Provides static utility for axis-aligned bounding box (AABB) collision detection.
 */

 #pragma once
 #include "TransformComponent.h"
 
 /**
  * @class CollisionComponent
  * @brief Provides static utility for axis-aligned bounding box (AABB) collision detection.
  */
 class CollisionComponent {
 public:
     /**
      * @brief Checks AABB collision between two transform components.
      * @param a First transform (entity A)
      * @param b Second transform (entity B)
      * @return True if the rectangles overlap (collide)
      */
     static bool CheckCollision(const TransformComponent& a, const TransformComponent& b) {
         return (
             a.x < b.x + b.width &&
             a.x + a.width > b.x &&
             a.y < b.y + b.height &&
             a.y + a.height > b.y
         );
     }
 };