#include "Scene_GameOver.h"
#include <SDL.h>

void Scene_GameOver::SceneStartUp(SDL_Renderer* renderer) {
    Scene::SceneStartUp(renderer);
}

void Scene_GameOver::Input(SDL_Event& e) {
    if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN) {
        SetSceneStatus(false);  // exit or back to main menu
    }
}

void Scene_GameOver::Render() {
    SDL_SetRenderDrawColor(mRenderer, 30, 0, 0, 255);
    SDL_RenderClear(mRenderer);
}
