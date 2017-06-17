#pragma once

#include <string>
#include <SDL.h>

class Graphics;

//
// Sprite class
// Holds all information for individual sprites
//

class Sprite
{
public:
	Sprite();
	Sprite(Graphics &Graphics, const std::string &Filepath, int SourceX, int SourceY,
		int width, int height, float PosX, float PoxY);
	virtual ~Sprite();
	virtual void Update();
	void Draw(Graphics &Graphics, int x, int y);

protected:
	SDL_Rect _SourceRect;
	SDL_Texture* _SpriteSheet;
	float _x, _y;

private:
	
};