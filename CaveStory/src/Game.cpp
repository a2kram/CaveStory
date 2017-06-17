//
// Game class
// This class holds all of our information for our main game loop
//

#include <algorithm>

#include <SDL.h>

#include <Game.h>
#include <Graphics.h>
#include <Input.h>

static const int FPS = 50;
static const int MAX_FRAME_TIME = 5 * 1000 / FPS; // max time frame can last

Game::Game()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	this->GameLoop();
}

Game::~Game()
{

}

void Game::GameLoop()
{
	Graphics Graphics;
	SDL_Event event;
	Input input;

	this->_Player = Player(Graphics, 100, 100);
	this->_Level = Level("map1", Vector2(100, 100), Graphics);

	// ms since SDL_INIT
	int LAST_UPDATE_TIME = SDL_GetTicks();
	int CURRENT_TIME_MS;
	int ELAPSED_TIME_MS;

	// Start game loop
	while (1)
	{
		input.BeginNewFrame();
	
		// Check for new events
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYDOWN)
			{
				// Ensure key is not held down
				if (event.key.repeat == 0)
				{
					input.KeyDownEvent(event);
				}
			}

			else if(event.type == SDL_KEYUP)
			{
				input.KeyUpEvent(event);
			}

			else if (event.type == SDL_QUIT)
			{
				return;
			}
		}

		if (input.WasKeyPressed(SDL_SCANCODE_ESCAPE) == true)
		{
			return;
		}
		else if (input.IsKeyHeld(SDL_SCANCODE_LEFT) == true)
		{
			this->_Player.MoveLeft();
		}
		else if (input.IsKeyHeld(SDL_SCANCODE_RIGHT) == true)
		{
			this->_Player.MoveRight();
		}

		if (!input.IsKeyHeld(SDL_SCANCODE_LEFT) && !input.IsKeyHeld(SDL_SCANCODE_RIGHT))
		{
			this->_Player.StopMoving();
		}

		CURRENT_TIME_MS = SDL_GetTicks();
		ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
		
		this->Update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));

		LAST_UPDATE_TIME = CURRENT_TIME_MS;

		this->Draw(Graphics);
	}
}

void Game::Draw(
	Graphics &Graphics
	)
{
	Graphics.Clear();

	this->_Level.Draw(Graphics);
	this->_Player.Draw(Graphics);

	Graphics.Flip();
}

void Game::Update(
	int ElapsedTime
	)
{
	this->_Player.Update(ElapsedTime);
	this->_Level.Update(ElapsedTime);
}