/**
 * @file LevelLoader.h
 * @brief Declares the utility class responsible for loading level layouts from files.
 */

 #pragma once
 #include <vector>
 #include <string>
 #include "../entities/Brick.h"
 
 /**
  * @class LevelLoader
  * @brief Provides functionality to load brick layout levels from text files.
  */
 class LevelLoader {
 public:
     /**
      * @brief Loads a level layout from a file path.
      * @param filePath Path to the level layout text file
      * @return A vector of bricks representing the loaded level
      */
     static std::vector<Brick> LoadLevel(const std::string& filePath);
 };