#include "Application.h"
#include "utils/GameSession.h"

// all level include
#include "scenes/Scene_Level1.h"
#include "scenes/Scene_Level2.h"
#include "scenes/Scene_Level3.h"
#include "scenes/Scene_Victory.h"
#include "scenes/Scene_GameOver.h"

#include <iostream>

void Application::StartUp() {
    SDL_Init(SDL_INIT_VIDEO);

    mWindow = SDL_CreateWindow("Brick Breaker",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        800, 600, 0);

    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);

    // initialize life points default 3
    GameSession::Get().Reset();

    // Scene used here
    mScenes.push_back(new Scene_Level1());
    mScenes.push_back(new Scene_Level2());
    mScenes.push_back(new Scene_Level3());
    mScenes.push_back(new Scene_Victory());
    mScenes.push_back(new Scene_GameOver());

    // initialize first scene
    mScenes[mCurrentScene]->SceneStartUp(mRenderer);
}

void Application::Loop() {
    SDL_Event e;
    Uint32 lastTick = SDL_GetTicks();

    while (mIsRunning && mCurrentScene < mScenes.size()) {
        Scene* current = mScenes[mCurrentScene];

        while (current->GetSceneStatus()) {
            Uint32 currentTick = SDL_GetTicks();
            float dt = (currentTick - lastTick) / 1000.0f;
            lastTick = currentTick;

            while (SDL_PollEvent(&e)) {
                if (e.type == SDL_QUIT) {
                    current->SetSceneStatus(false);
                    mIsRunning = false;
                }
                current->Input(e);
            }

            current->Update(dt);
            current->Render();
            SDL_RenderPresent(mRenderer);
        }

        current->SceneShutDown();

        // move on logic SCene
        if (mCurrentScene == 0 || mCurrentScene == 1 || mCurrentScene == 2) {
            if (GameSession::Get().IsGameOver()) {
                mCurrentScene = 4; // GameOverScene
            } else if (mCurrentScene == 2) {
                mCurrentScene = 3; // finallevel complete → Victory
            } else {
                mCurrentScene++;   // nextlevel
            }
        } 
                else {
            mIsRunning = false;    // scene end
        }

        if (mCurrentScene < mScenes.size() && mIsRunning) {
            mScenes[mCurrentScene]->SceneStartUp(mRenderer);
        }
    }
}

void Application::ShutDown() {
    for (Scene* scene : mScenes) {
        delete scene;
    }
    mScenes.clear();

    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}

Application::~Application() {
    ShutDown();
}
