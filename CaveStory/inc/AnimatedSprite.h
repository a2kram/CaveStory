#ifndef ANIMATED_SPRITE_H 
#define ANIMATED_SPRITE_H

#include <map>
#include <string>
#include <vector>

#include <Globals.h>
#include <Sprite.h>

class Graphics;

//
// Animated Sprite class
// Holds logic for animating sprites
//

class AnimatedSprite : public Sprite
{

public:
	AnimatedSprite();
	AnimatedSprite(Graphics &Graphics, const std::string &FilePath, int SourceX, int SourceY, 
		int Width, int Height, float PosX, float PosY, float TimeToUpdate);
	
	// Once has an optional parameter, meaning function can be called with the second param blank,
	// with it defaulted to false
	// Function plays animation provided if it's not already playing
	void PlayAnimation(std::string Animation, bool Once = false);
	
	// Updates the animated sprite (timer)
	void Update(int ElapsedTime);

	// Draws sprite to screen
	void Draw(Graphics &Graphics, int x, int y);

protected:
	double _TimeToUpdate;
	bool _CurrentAnimationOnce;
	std::string _CurrentAnimation;


	// Adds an animation to the map of animations for the sprite
	void AddAnimation(int Frames, int x, int y, std::string Name, int Width, int Height, Vector2 Offset);

	// Resets all animations associated with this sprite
	void ResetAnimations();

	// Stops the current animation
	void StopAnimation();

	// Changes the visibility of the animated sprite
	void SetVisible(bool visible);

	// Logic that happens when animation ends
	virtual void AnimationDone(std::string CurrentAnimation) = 0;

	// A required function that sets up all animations for a sprite
	virtual void SetupAnimations() = 0;

private:
	std::map<std::string, std::vector<SDL_Rect>> _Animations;
	std::map<std::string, Vector2> _Offsets;

	int _FrameIndex;
	double _TimeElapsed;
	bool _Visible;

};
	
#endif // !ANIMATED_SPRITE_H 