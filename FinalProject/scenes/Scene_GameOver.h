#pragma once
#include "../Scene.h"
#include <SDL.h>

class Scene_GameOver : public Scene {
public:
    void SceneStartUp(SDL_Renderer* renderer) override;
    void SceneShutDown() override {}
    void Input(SDL_Event& e) override;
    void Update(float dt) override {}
    void Render() override;
};
