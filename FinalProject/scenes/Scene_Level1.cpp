#include "Scene_Level1.h"
#include "../components/CollisionComponent.h"
#include "../components/InputComponent.h"
#include "../components/TransformComponent.h"
#include "../utils/LevelLoader.h"
#include "../utils/GameSession.h"
#include <cmath>
#include <iostream>

void Scene_Level1::SceneStartUp(SDL_Renderer* renderer) {
    Scene::SceneStartUp(renderer);
    mBricks = LevelLoader::LoadLevel("resources/level1.txt");
}

void Scene_Level1::SceneShutDown() {
    mBricks.clear();
}

void Scene_Level1::Input(SDL_Event& e) {
    if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_n) {
        SetSceneStatus(false);
    }
}

void Scene_Level1::Update(float dt) {
    InputComponent input;
    const Uint8* keys = SDL_GetKeyboardState(NULL);
    input.HandleInput(mPaddle, dt, keys);

    float oldX = mBall.transform.x;
    float oldY = mBall.transform.y;

    // check collide x axix
    mBall.transform.x += mBall.velX * dt;
    for (auto& brick : mBricks) {
        if (!brick.destroyed && CollisionComponent::CheckCollision(mBall.transform, brick.transform)) {
            mBall.velX *= -1;
            brick.TakeHit();
            mBall.transform.x = oldX;
            break;
        }
    }

    // Y axis movement and collision
    mBall.transform.y += mBall.velY * dt;
    for (auto& brick : mBricks) {
        if (!brick.destroyed && CollisionComponent::CheckCollision(mBall.transform, brick.transform)) {
            mBall.velY *= -1;
            brick.TakeHit();
            mBall.transform.y = oldY;
            break;
        }
    }

    // edge collide
    if (mBall.transform.x < 0) {
        mBall.transform.x = 0;
        mBall.velX *= -1;
    }
    if (mBall.transform.x + mBall.transform.width > 800) {
        mBall.transform.x = 800 - mBall.transform.width;
        mBall.velX *= -1;
    }
    if (mBall.transform.y < 0) {
        mBall.transform.y = 0;
        mBall.velY *= -1;
    }

    // paddle collide
    if (CollisionComponent::CheckCollision(mBall.transform, mPaddle.transform)) {
        mBall.velY = -std::fabsf(mBall.velY);
    }

    // fall bottom
    if (mBall.transform.y > 600) {
        GameSession::Get().LoseLife();
        if (GameSession::Get().IsGameOver()) {
            std::cout << "Game Over!\n";
            SetSceneStatus(false);
        } else {
            mBall = Ball(400, 300);
            mPaddle = Paddle(350, 550);
        }
    }

    // all brick broke = complete
    bool allDestroyed = true;
    for (auto& brick : mBricks) {
        if (!brick.destroyed) {
            allDestroyed = false;
            break;
        }
    }

    if (allDestroyed) {
        std::cout << "[Level1] Complete!\n";
        SetSceneStatus(false);
    }
}

void Scene_Level1::Render() {
    SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
    SDL_RenderClear(mRenderer);

    mPaddle.Render(mRenderer);
    mBall.Render(mRenderer);
    for (auto& brick : mBricks) {
        brick.Render(mRenderer);
    }

    int lives = GameSession::Get().GetLives();
    for (int i = 0; i < lives; ++i) {
        SDL_Rect lifeRect = {750 - i * 20, 10, 10, 10};
        SDL_SetRenderDrawColor(mRenderer, 255, 255, 0, 255);
        SDL_RenderFillRect(mRenderer, &lifeRect);
    }
}
