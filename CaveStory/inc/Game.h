#ifndef GAME_H
#define GAME_H

#include <Player.h>
#include <Level.h>

class Graphics;

class Game
{
public:
	Game();
	~Game();

private:
	void GameLoop();
	void Draw(Graphics &Graphics);
	void Update(int ElapsedTime);

	Player _Player;
	Level _Level;
};

#endif 