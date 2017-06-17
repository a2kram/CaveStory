
#include <SDL.h>

#include "Level.h"
#include "Globals.h"
#include "Graphics.h"

Level::Level() {}

Level::Level(std::string MapName, Vector2 SpawnPoint, Graphics &Graphics) :
	_MapName(MapName),
	_SpawnPoint(SpawnPoint),
	_Size(Vector2(0,0))
{
	this->LoadMap(MapName, Graphics);
}

Level::~Level() {}

void Level::LoadMap(std::string MapName, Graphics &Graphics)
{
	// TEMPORARY CODE TO LOAD THE BACKGROUND
	this->_BackgroundTexture = SDL_CreateTextureFromSurface(Graphics.GetRenderer(),
		Graphics.LoadImage("../CaveStory/res/Backgrounds/bkBlue.png"));

	this->_Size = Vector2(1280, 960);
}

void Level::Update(int ElapsedTime)
{

}

void Level::Draw(Graphics &Graphics)
{
	// Draw the background
	SDL_Rect SourceRect = {0, 0, 64, 64};
	SDL_Rect DestRect;

	for (int x = 0; x < (this->_Size.x / 64); ++x)
	{
		for (int y = 0; y < (this->_Size.y / 64); ++y)
		{
			DestRect.x = x * 64 * globals::SPRITE_SCALE;
			DestRect.y = y * 64 * globals::SPRITE_SCALE;
			DestRect.w = 64 * globals::SPRITE_SCALE;
			DestRect.h = 64 * globals::SPRITE_SCALE;

			Graphics.BlitSurface(this->_BackgroundTexture, &SourceRect, &DestRect);
		}
	}
}
