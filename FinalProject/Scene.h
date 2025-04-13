/**
 * @file Scene.h
 * @brief Defines the abstract base class for all game scenes.
 */

 #pragma once
 #include <SDL.h>
 
 /**
  * @class Scene
  * @brief Abstract base class for all game scenes (levels, menus, etc).
  */
 class Scene {
 protected:
     SDL_Renderer* mRenderer = nullptr;  ///< Pointer to SDL renderer for rendering scene objects
     bool mSceneIsActive = true;         ///< Whether the scene is currently active
 
 public:
     /**
      * @brief Virtual destructor.
      */
     virtual ~Scene() = default;
 
     /**
      * @brief Called when the scene is initialized.
      * @param renderer SDL renderer pointer.
      */
     virtual void SceneStartUp(SDL_Renderer* renderer) {
         mRenderer = renderer;
     }
 
     /**
      * @brief Called when the scene is shutting down.
      */
     virtual void SceneShutDown() {}
 
     /**
      * @brief Handles input events for the scene.
      * @param e SDL event reference.
      */
     virtual void Input(SDL_Event& e) = 0;
 
     /**
      * @brief Updates scene logic.
      * @param dt Delta time since last frame.
      */
     virtual void Update(float dt) = 0;
 
     /**
      * @brief Renders the scene.
      */
     virtual void Render() = 0;
 
     /**
      * @brief Gets whether the scene is active.
      * @return True if active.
      */
     bool GetSceneStatus() const { return mSceneIsActive; }
 
     /**
      * @brief Sets the active status of the scene.
      * @param status True to keep active, false to end.
      */
     void SetSceneStatus(bool status) { mSceneIsActive = status; }
 };