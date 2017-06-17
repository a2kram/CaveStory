
#include "AnimatedSprite.h"
#include "Player.h"
#include "Graphics.h"

namespace Player_Constants
{
	const float WALK_SPEED = 0.2f;
}

Player::Player() {}

Player::Player(Graphics &Graphics, float x, float y) :
	AnimatedSprite(Graphics, "../CaveStory/res/Sprites/MyChar.png", 0, 0, 16, 16, x, y, 100)
{
	Graphics.LoadImage("../CaveStory/res/Sprites/MyChar.png");

	this->SetupAnimations();
	this->PlayAnimation("RunRight");
}

void Player::SetupAnimations()
{
	this->AddAnimation(3, 0, 0, "RunLeft", 16, 16, Vector2(0, 0));
	this->AddAnimation(3, 0, 16, "RunRight", 16, 16, Vector2(0, 0));
	this->AddAnimation(1, 0, 0, "IdleLeft", 16, 16, Vector2(0, 0));
	this->AddAnimation(1, 0, 16, "IdleRight", 16, 16, Vector2(0, 0));
}

void Player::AnimationDone(std::string CurrentAnimation) {}

void Player::MoveLeft()
{
	this->_dx = -Player_Constants::WALK_SPEED;
	this->PlayAnimation("RunLeft");
	this->_Facing = LEFT;
}

void Player::MoveRight()
{
	this->_dx = Player_Constants::WALK_SPEED;
	this->PlayAnimation("RunRight");
	this->_Facing = RIGHT;
}

void Player::StopMoving()
{
	this->_dx = 0.0f;
	this->PlayAnimation(this->_Facing == RIGHT ? "IdleRight": "IdleLeft");
}

void Player::Update(float ElapsedTime)
{
	// Move by dx
	this->_x += this->_dx * ElapsedTime;

	AnimatedSprite::Update(ElapsedTime);
}

void Player::Draw(Graphics &Graphics)
{
	AnimatedSprite::Draw(Graphics, this->_x, this->_y);
}