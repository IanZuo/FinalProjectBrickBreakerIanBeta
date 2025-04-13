#pragma once
#include "../Scene.h"
#include "../entities/Ball.h"
#include "../entities/Paddle.h"
#include "../entities/Brick.h"
#include "../utils/LevelLoader.h"
#include "../utils/GameSession.h"

class Scene_Level1 : public Scene {
private:
    Ball mBall{400, 300};
    Paddle mPaddle{350, 550};
    std::vector<Brick> mBricks;

public:
    void SceneStartUp(SDL_Renderer* renderer) override;
    void SceneShutDown() override;
    void Input(SDL_Event& e) override;
    void Update(float dt) override;
    void Render() override;
};
