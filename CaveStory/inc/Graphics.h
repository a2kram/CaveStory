#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <map>
#include <string>

// Forward declaring pointers 
struct SDL_Window;
struct SDL_Renderer;

class Graphics 
{
public:
	Graphics();
	~Graphics();

	// Loads an image into the _SpriteSheets map if it doesnt already exist
	// Each image will be loaded only once
	// Returns an image from the map regardless of whether or not it was just loaded
	SDL_Surface* LoadImage(const std::string &filepath);

	// Draw a texture to a certain part of the screen
	// Source rectangle is part of sprite sheet to be drawn
	// Destination rectangle is part of screen to be drawn to
	void BlitSurface(SDL_Texture* Source, SDL_Rect* SourceRectangle, SDL_Rect* DestinationRectangle);

	// Renders everything to the screen
	void Flip(void);

	// Clear screen
	void Clear(void);

	// Returns the renderer
	SDL_Renderer* GetRenderer() const;

private:
	SDL_Window*	  _Window;
	SDL_Renderer* _Renderer;

	std::map<std::string, SDL_Surface*> _SpriteSheets;
};

#endif