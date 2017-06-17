#include <Sprite.h>
#include <Graphics.h>
#include <Globals.h>

Sprite::Sprite() {}

Sprite::Sprite(Graphics &Graphics, const std::string &FilePath, int SourceX, int SourceY, int width, int height, 
	float PosX, float PosY) : _x(PosX), _y(PosY)
{
	this->_SourceRect.x = SourceX;
	this->_SourceRect.y = SourceY;
	this->_SourceRect.w = width;
	this->_SourceRect.h = height;

	this->_SpriteSheet = SDL_CreateTextureFromSurface(Graphics.GetRenderer(), Graphics.LoadImage(FilePath));

	if (this->_SpriteSheet == NULL)
	{
		printf("\nError: Unable to load image!\n");
	}
}

Sprite::~Sprite() {}

void Sprite::Draw(Graphics &Graphics, int x, int y)
{
	SDL_Rect DestinationRectangle = { x, y, this->_SourceRect.w * globals::SPRITE_SCALE,
		this->_SourceRect.h  * globals::SPRITE_SCALE};

	Graphics.BlitSurface(this->_SpriteSheet, &this->_SourceRect, &DestinationRectangle);
}

void Sprite::Update() {}