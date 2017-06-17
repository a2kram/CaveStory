//
// Graphics class
// Holds all information dealing with graphics for the game
//

#include <SDL.h>
#include <SDL_image.h>
#include <Graphics.h>
#include <Globals.h>

Graphics::Graphics()
{
	SDL_CreateWindowAndRenderer(globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT, 0, &this->_Window, &this->_Renderer);
	SDL_SetWindowTitle(this->_Window, "CaveStory");
}

Graphics::~Graphics()
{
	SDL_DestroyWindow(this->_Window);
}

SDL_Surface* Graphics::LoadImage(const std::string &FilePath)
{
	if (this->_SpriteSheets.count(FilePath) == 0)
	{
		this->_SpriteSheets[FilePath] = IMG_Load(FilePath.c_str());
	}

	return this->_SpriteSheets[FilePath];
}

void Graphics::BlitSurface(SDL_Texture* Texture, SDL_Rect* SourceRectangle, SDL_Rect* DestinationRectangle)
{
	// Copy texture to renderer
	SDL_RenderCopy(this->_Renderer, Texture, SourceRectangle, DestinationRectangle);
}

void Graphics::Flip()
{
	SDL_RenderPresent(this->_Renderer);
}

void Graphics::Clear()
{
	SDL_RenderClear(this->_Renderer);
}

// Const since not allowed to make changes to class members
SDL_Renderer* Graphics::GetRenderer() const
{
	return this->_Renderer;
}