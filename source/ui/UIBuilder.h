#ifndef UIBUILDER_CLASS_H
#define UIBUILDER_CLASS_H
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "../windows/windowsmanager.h"

using namespace std;

class UIBuilder
{
public: 
    string Name;
	bool isOpen;

	void Start();
	void Draw();
	void Delete();
};
#endif