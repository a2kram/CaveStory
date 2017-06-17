#ifndef PLAYER_H
#define PLAYER_H

#include "AnimatedSprite.h"

class Graphics;

class Player : public AnimatedSprite
{

public: 
	Player();
	Player(Graphics &Graphics, float x, float y);
	void Draw(Graphics &Graphics);
	void Update(float ElapsedTime);

	// Moves player left by -dx
	void MoveLeft();

	// Moves player right by dx
	void MoveRight();

	// Stops moving the player 
	void StopMoving();

	virtual void AnimationDone(std::string CurrentAnimation);
	virtual void SetupAnimations();

private:
	float _dx, _dy;

	Direction _Facing;
};

#endif
