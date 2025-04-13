    # Final Project 

**Overall Objective for the Final Project** 

* This final project is meant to be fun! I know it's a final project for a course, but this is the time where you have the freedom to modify your game engine however you'd like (but must use components and scenes).

More details on each part can be found below this section.

* **Abstract your Application into a Scene Class.** Then add functionality to load multiple scenes into your program. 

* **Customize Your Game Engine.** Turn your game engine into something personal whether its enhancing the space invaders functionality, or creating an entirely new game.

* **Create a Game using your Game Engine.** You should create an executable that allows the player to play your game. You should have at least 3 scenes or levels that get played through without restarting your executable.

* **Set Up a GitHub Repository to Showcase Your Final Project.** This project can be used as a portfolio piece if you want, but for this course you will be required to set it up as a portfolio piece.

* All final project directories and files should be included in the Final Project Submission directory provided.

* NOTE: I mention player and enemy often throughout these instructions but these entities could be blocks, walls, coins, etc. I know we've been working on Space Invaders the entire semester, so it may be difficult to see how our game engine can be changed to different styles of games. A simple way of reworking that mindset is to think about the enemies as simple Game Entities that can be: static, moved around, be collided with, fire projectiles, disappear, etc. They don't have to be "enemies". You can also add more game entities as well! Maybe you do want enemies, but you also want tiles that act as shields or powerups.

* Some Examples. The "enemy": could be a block forming a wall for a maze, a block that disappears when collided with, a coin that the player needs to collect, a power-up, etc.

**Section 1: Abstract your Application into a Scene Class**

* NOTE: These instructions are just a guide. Feel free to add different logic, functions, member variables etc. These instructions will help you set up a Scene and following them will hopefully allow you to understand the abstraction and why we're moving certain code away from the application.

* NOTE: This is the last section that is guided with instructions. The rest will be up to you!

* Our application is currently handling setting up SDL, constructing our game, and managing our game loop. The application should handle the technical aspects of our game engine, but not so much the logic and functionality. Thus, the application should handle setting up SDL, managing windows, and running our game loop.

* To abstract our application we will be creating a Scene struct/class that will handle the actual creation of our game. You can think of a scene as a level or a level manager. This is where we will be placing enemies and players. (In your own game, you might use it to set up scenery, blocks, tiles, powerups, walls, etc.)

* Having a Scene will allow us to have multiple different scenes (levels, views, worlds). You may want to go further and implement a scene manager, but that is not required here.

***Scene Class***

* Create a Scene struct/class and copy over all of the code from the Application .hpp and .cpp files. Replace all mentions of "Application" with "Scene". The Scene class will only have member variables: enemies, player, score, an SDL renderer, and a boolean to see if the scene is active or not.

* The Scene constructor doesn't need to call StartUp() because we'll be calling it in our application. It may be helpful to rename StartUp and Shutdown to something like SceneStartUp() and SceneShutDown().

* The Scene's StartUp() will take in an SDL Renderer and assign it to the member variable. ShutDown() will do nothing at this point.

* Input() will JUST update the mainCharacter.

* Create a setter and a getter for changing the member variable mSceneIsActive which is a boolean.

***Application Class***

* The application class will hold onto a vector of Scenes. I would recommend having a member variable that tracks the current scene and set it to 0. This way you can access the first scene in the vector to make sure your code is running.

* The Application's StartUp() should not be setting up any GameEntities, it should be setting up SDL, our window, and calling our first Scene's StartUp() function.
* Note: You can create a sample scene with: Scene s, mScenes.push_back(s), mScenes[currentScene].StartUp();

* Update, and Render will just call the mScenes[currentScene]'s Input, Update, and Render Functions.
* Note: You may want to think about whether the list of scenes should be a vector or a linked list. When we add scenes to a vector, it may need to copy over scenes as it expands. For our simple space invaders game, the scenes won't hold much data but as your games expand and get more complex, it may be something to think about.

* Input() will also call mScenes[currentScene]'s Input function but after handling input logic for closing the window. Instead of relying on mRun as the boolean here, we'll be relying on whether the Scene is active or not since the Scene has a member variable tracking this. When the user's input is of type SDL Quit, we can access the current scene and call SetSceneStatus(false);

* Because we changed mRun to the currentSceneStatus, we can also modify our Loop() to no longer rely on mRun but rather on the current Scene's GetSceneStatus(). 

***Overall Notes***
* Make sure you include the new scene.hpp where it is needed.
* Remember what the difference between the Scene and the Application is and their roles in the game engine.

**Section 1A: Add Functionality for Loading In Scenes**

* Your final project must allow for loading in multiple scenes. You will have to figure out how to manage this.

* One idea is to use .txt files for each scene which will hold data about your player and enemy. You could write them manually or create a GUI for creating scenes and saving them to .txt files.

* Another suggestion for your code is to think about how StartUp() is creating a standard scene. It's creating a hard-coded version of space invaders, but maybe you'll call a different function if a file is included in your command line arguments.

**Section 2: Customize Your Game Engine**

* Here you have two options:

***Option 1. Keep your Game Engine as a Space Invaders game engine.***

* 1A. If you choose this option, you must add functionality or additional components that makes your game articulably unique from the Space Invaders game completed in Assignment #8. This option has the most ambiguous of standards because it is difficult to say what exactly would make your game unique enough. But I can say, for example, adding 2 projectiles instead of 1, adding more enemies, or simply changing the graphics WILL NOT be enough. If you have any questions about this, please ask me.

***Option 2. Revise your Game Engine to create a different style of game.***

* 2A. This can seem intimidating as we've only created Space Invaders in this class, but as I mentioned before, try not to think about your Game Entities in a Player vs. Enemy mindset. Your player will still likely be needed as most games have a player. But your enemies can be different. You can use different assets, change the size of these entities, change their functionality. Maybe they move differently, maybe they interact differently when collided with, or maybe they don't do anything except annoy your player and get in the way. Some games to think about, and you don't have to create these, are snake, pong, bubble-shooter, brick-breaker, tetris, pacman, asteroids, minesweeper.

**Section 3: Create a Game using your Game Engine** 

* After finalizing your Game Engine, create a game that someone else can play by running your executable file.

* This game must include at least three scenes (levels). The user must be able to play all three scenes by running the executable file once. They should not need to run the executable file multiple times to play each scene.

* Include this executable file in your submission directory and give it a name representing the game.

**Section 4: Create a Portfolio out of your GitHub Repository**

1. Your struct/class implementations and functions must include Doxygen style comments. These comments will allow you to automate the process of creating documentation for your game engine. 

2. Look up down to download Doxygen, how to properly comment, and how to create the documentation from these comments. Include the files in your submission.

3. In the Project.md, include a description of your game engine, a 1-2 minute video trailer followed by at least 3 screenshots of your game.
    * This video should highlight the data-driven nature of your final project. Explain how your game engine works, a new feature you added, and a quick playthrough of your game.

4. Post-Mortem README.
    * A few paragraphs describing how you would take the project further, what went well and what you would change if given another month on the project.
