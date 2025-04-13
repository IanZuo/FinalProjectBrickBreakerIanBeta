/**
 * @file Application.h
 * @brief Defines the core application engine that manages SDL window, renderer, and scenes.
 */

 #pragma once
 #include <SDL.h>
 #include <vector>
 #include "Scene.h"
 
 /**
  * @class Application
  * @brief The main engine class responsible for running the game loop and managing scenes.
  */
 class Application {
 private:
     SDL_Window* mWindow = nullptr;           ///< SDL window handle
     SDL_Renderer* mRenderer = nullptr;       ///< SDL renderer handle
     std::vector<Scene*> mScenes;             ///< All game scenes
     int mCurrentScene = 0;                   ///< Index of current scene
     bool mIsRunning = true;                  ///< Main loop control flag
 
 public:
     /**
      * @brief Destructor that shuts down the application.
      */
     ~Application();
 
     /**
      * @brief Initializes SDL and the game scenes.
      */
     void StartUp();
 
     /**
      * @brief Main game loop.
      */
     void Loop();
 
     /**
      * @brief Shuts down SDL and deallocates scenes.
      */
     void ShutDown();
 };
 