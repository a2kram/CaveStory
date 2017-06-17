#include <AnimatedSprite.h>
#include <Graphics.h>
#include <Sprite.h>

//
// AnimatedSprite class
// Animates our sprites
//

AnimatedSprite::AnimatedSprite() {}

AnimatedSprite::AnimatedSprite(Graphics &Graphics, const std::string &Filepath, int SourceX, int SourceY,
	int Width, int Height, float PosX, float PosY, float TimeToUpdate) :
	Sprite(Graphics, Filepath, SourceX, SourceY, Width, Height, PosX, PosY),
	_FrameIndex(0),
	_TimeElapsed(0),
	_TimeToUpdate(TimeToUpdate),
	_Visible(true),
	_CurrentAnimationOnce(false),
	_CurrentAnimation("") {}

void AnimatedSprite::AddAnimation(int Frames, int x, int y, std::string Name, int Width, int Height, Vector2 Offset)
{
	std::vector<SDL_Rect> Rectangles;

	for (int i = 0; i < Frames; i++)
	{
		SDL_Rect NewRect = { (i + x) * Width, y, Width, Height };
		Rectangles.push_back(NewRect);
	}

	this->_Animations.insert(std::pair<std::string, std::vector<SDL_Rect>>(Name, Rectangles));
	this->_Offsets.insert(std::pair<std::string, Vector2>(Name, Offset));
}

void AnimatedSprite::ResetAnimations()
{
	this->_Animations.clear();
	this->_Offsets.clear();
}

void AnimatedSprite::PlayAnimation(std::string Animation, bool Once)
{
	this->_CurrentAnimationOnce = Once;

	if (this->_CurrentAnimation != Animation)
	{
		this->_CurrentAnimation = Animation;
		this->_FrameIndex = 0;
	}
}

void AnimatedSprite::SetVisible(bool Visible)
{
	this->_Visible = Visible;
}

void AnimatedSprite::StopAnimation()
{
	this->_FrameIndex = 0;
	this->AnimationDone(this->_CurrentAnimation);
}

void AnimatedSprite::Update(int ElapsedTime)
{
	Sprite::Update();

	this->_TimeElapsed += ElapsedTime;

	if (this->_TimeElapsed > this->_TimeToUpdate)
	{
		this->_TimeElapsed -= this->_TimeToUpdate;

		if (this->_FrameIndex < this->_Animations[this->_CurrentAnimation].size() - 1)
		{
			this->_FrameIndex++;
		}
		else
		{
			if (this->_CurrentAnimationOnce == true)
			{
				this->SetVisible(false);
			}

			this->_FrameIndex = 0;
			this->AnimationDone(this->_CurrentAnimation);
		}
	}
}

void AnimatedSprite::Draw(Graphics &Graphics, int x, int y)
{
	if (this->_Visible)
	{
		SDL_Rect DestinationRectangle;

		DestinationRectangle.x = x + this->_Offsets[this->_CurrentAnimation].x;
		DestinationRectangle.y = y + this->_Offsets[this->_CurrentAnimation].y;
		DestinationRectangle.w = this->_SourceRect.w * globals::SPRITE_SCALE;
		DestinationRectangle.h = this->_SourceRect.h * globals::SPRITE_SCALE;

		SDL_Rect SourceRect = this->_Animations[this->_CurrentAnimation][this->_FrameIndex];
		Graphics.BlitSurface(this->_SpriteSheet, &SourceRect, &DestinationRectangle);
	}
}
