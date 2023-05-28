#include "windowsmanager.h"
#include "SDL.h"
#include <stdio.h>
#include "../ui/ImGuiImplement.h"
#include "../components/texture/TextureComponent.h"

using namespace std;


ImGuiImplement* imgui = nullptr;
SDL_Renderer* windowsmanager::renderer = nullptr;
SDL_Window* windowsmanager::windows = nullptr;

SDL_Texture* textTest;

windowsmanager::windowsmanager() {

}

windowsmanager::~windowsmanager() {

}

//On start engine
void windowsmanager::CreateWindow(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	if (fullscreen) {

	}

	if (SDL_Init (SDL_INIT_EVERYTHING) == 0) {
		std::cout << "System initialised!..." << endl;
		windows = SDL_CreateWindow (title, xpos, ypos, width, height, SDL_WINDOW_RESIZABLE);

		if (windows) {
			std::cout << "Windows initialised!..." << endl;
		}

		renderer = SDL_CreateRenderer (windows, -1, 0);

		if (renderer) {
			std::cout << "Render initialised!..." << endl;
		}

		imgui = new ImGuiImplement();

		textTest = TextureComponent::LoadTexture("Assets/Sprites/Eye.png", renderer);

		imgui->SetupUI (windows, renderer);
		isRunning = true;
	}
	else {
		isRunning = false;
	}
}

//Key events
void windowsmanager::InputEvents() {
	SDL_Event events;

	SDL_PollEvent (&events);

	switch (events.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;

	default:
		break;
	}

	engineEvents = events;
}

//On update frame
void windowsmanager::OnUpdate() {

}

//On start engine
void windowsmanager::OnStart() {

}

//Render graphics
void windowsmanager::OnRender() {
	SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);

	SDL_Rect textureRect;
	textureRect.x = 0;
	textureRect.y = 0;
	textureRect.w = 500;
	textureRect.h = 500;

	SDL_RenderClear(renderer);

	SDL_RenderCopy(renderer, textTest, NULL, &textureRect);
	


	imgui->Render (engineEvents);
	imgui->GetRenderDrawData();
	SDL_RenderPresent(renderer);
}

//On finish the engine
void windowsmanager::OnClean() {
	imgui->Clean();
	SDL_DestroyWindow (windows);
	SDL_DestroyRenderer (renderer);
	SDL_Quit();
	std::cout << "Engine stopped!..." << endl;
}

//On editor is running
bool windowsmanager::Running() {
	if (isRunning) {
		return true;
	}

	return false;
}