#include "TextureComponent.h"

SDL_Texture* TextureComponent::LoadTexture (const char* filePath, SDL_Renderer* renderer) {
	SDL_Surface* tempsurface = IMG_Load (filePath);
	SDL_Texture* texture = SDL_CreateTextureFromSurface (renderer, tempsurface);

	return texture;
}

void TextureComponent::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest, SDL_RendererFlip flip)
{
	SDL_RenderCopyEx(windowsmanager::renderer, tex, &src, &dest, NULL, NULL, flip);
}