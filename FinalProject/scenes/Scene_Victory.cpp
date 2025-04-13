#include "Scene_Victory.h"
#include <iostream>

void Scene_Victory::SceneStartUp(SDL_Renderer* renderer) {
    Scene::SceneStartUp(renderer);
    std::cout << "[Scene_Victory] You win! Press Enter to exit.\n";
}

void Scene_Victory::Input(SDL_Event& e) {
    if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN) {
        SetSceneStatus(false); // scence ended move on or end
    }
}

void Scene_Victory::Render() {
    // green for victory
    SDL_SetRenderDrawColor(mRenderer, 0, 100, 0, 255);
    SDL_RenderClear(mRenderer);
    
}
