#ifndef LEVEL_H
#define LEVEL_H

#include <string>

#include "Globals.h"

class Graphics;
struct SDL_Texture;

class Level
{

public:
	Level();
	Level(std::string MapName, Vector2 SpawnPoint, Graphics &Graphics);
	~Level();
	void Update(int ElapsedTime);
	void Draw(Graphics &Graphics);

private:
	std::string _MapName;
	Vector2 _SpawnPoint;
	Vector2 _Size;
	SDL_Texture* _BackgroundTexture;

	// Loads a map
	void LoadMap(std::string MapName, Graphics &Graphics);
};

#endif