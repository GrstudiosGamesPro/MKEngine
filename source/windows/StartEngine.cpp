#include "StartEngine.h"
#include "windowsmanager.h"

void StartEngine::Start() {
	windowsmanager* windows = new windowsmanager();
	windows->CreateWindow(Name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 700, false);

	const int frameDelay = 1000 / MaxFPS;

	Uint32 frameStart;
	int FrameTime;

	while (windows->Running())
	{
		frameStart = SDL_GetTicks();

		windows->InputEvents();
		windows->OnUpdate();
		windows->OnRender();

		FrameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > FrameTime) {
			SDL_Delay (frameDelay - FrameTime);
		}
	}

	windows->OnClean();
}

//on destroy engine
StartEngine::~StartEngine() {

}