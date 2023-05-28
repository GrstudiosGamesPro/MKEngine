#ifndef TEXTURECMP_CLASS_H
#define TEXTURECMP_CLASS_H
#include <SDL.h>
#include "SDL_image.h"
#include "../../windows/windowsmanager.h"

class TextureComponent
{
public:
	static SDL_Texture* LoadTexture (const char* fileName, SDL_Renderer* renderer);
	static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest, SDL_RendererFlip flip);

};


#endif // !TEXTURECMP_CLASS_H
