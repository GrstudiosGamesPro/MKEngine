#ifndef WINDOWS_MANAGER_H
#define WINDOWS_MANAGER_H
#include "SDL.h"
#include <iostream>

class windowsmanager
{
public:
	static SDL_Renderer* renderer;
	static SDL_Window* windows;

	void CreateWindow (const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	//Key events
	void InputEvents();

	//On update frame
	void OnUpdate();

	//On start engine
	void OnStart();

	//Render graphics
	void OnRender();

	//On finish the engine
	void OnClean();

	//On editor is running
	bool Running();

	windowsmanager();
	~windowsmanager();

private:
	bool isRunning;
	SDL_Event engineEvents;
};

#endif