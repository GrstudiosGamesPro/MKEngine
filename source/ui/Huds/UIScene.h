#ifndef UIScene_CLASS_H
#define UIScene_CLASS_H

#include "../UIBuilder.h"
#include "imgui.h"

class UIScene : public UIBuilder
{
public:
    SDL_Texture* imguiTexture = nullptr;
    int windowWidth = 0;
    int windowHeight = 0;


	void Start() {
		Name = "Scene";	
        imguiTexture = SDL_CreateTexture(windowsmanager::renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, windowWidth, windowHeight);
    }

    void InitializeTexture() {
        if (imguiTexture != nullptr) {
            SDL_DestroyTexture(imguiTexture);
            imguiTexture = nullptr;
        }

        imguiTexture = SDL_CreateTexture(windowsmanager::renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, windowWidth, windowHeight);
    }

    void Draw() {
        int windowWidth, windowHeight;
        SDL_GetWindowSize(windowsmanager::windows, &windowWidth, &windowHeight);

        SDL_Surface* surface = SDL_CreateRGBSurface(0, windowWidth, windowHeight, 32, 0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF);
        SDL_RenderReadPixels(windowsmanager::renderer, nullptr, SDL_PIXELFORMAT_RGBA8888, surface->pixels, surface->pitch);

        SDL_Surface* imguiSurface = SDL_ConvertSurfaceFormat(surface, SDL_PIXELFORMAT_RGBA8888, 0);

        if (imguiTexture != nullptr) {
            SDL_DestroyTexture(imguiTexture);
            imguiTexture = nullptr;
        }

        imguiTexture = SDL_CreateTextureFromSurface(windowsmanager::renderer, imguiSurface);

        SDL_FreeSurface(surface);
        SDL_FreeSurface(imguiSurface);

        ImVec2 imageSize(windowWidth, windowHeight);

        ImGui::Begin(Name.c_str());
        ImGui::Image(reinterpret_cast<ImTextureID>(imguiTexture), imageSize);
        ImGui::End();
    }

};
#endif // !UIHIERARCHY