#ifndef INCLUDED_AX_ANIMATED_IMAGE
#define INCLUDED_AX_ANIMATED_IMAGE

#include "Image.hpp"

namespace ax
{
	class AnimatedImage
	{
	private:
		FloatPair scale;
		bool isPaused;

	public:
		/* DO NOT ACCESS MANUALLY. */
		Image sheet;
		ShortPair frameSize, crtFrame;

		/* Creates a new empty animated image. */
		AnimatedImage();

		/*
		Loads the animation from an image sheet file with a specified amount of horizontal and vertical frames.
		... Returns True if the image sheet file exists.
		*/
		bool LoadSheet(const String& fileName, ShortPair frameAmount);

		/*
		Loads the animation from an image sheet file with a specified amount of horizontal and vertical frames, turning the specified color transparent.
		... Returns True if the image sheet file exists.
		*/
		bool LoadSheet(const String& fileName, ShortPair frameAmount, Color transparencyColor);

		/* Sets the coordinates of the animation's top left corner. */
		void SetPosition(ShortPair position);

		/* Returns the coordinates of the animation's top left corner. */
		ShortPair GetPosition();

		/* Returns the size of a single non-scaled frame. */
		ShortPair GetFrameSize();

		/* Sets the scale of the animation. */
		void SetScale(const FloatPair& scale);

		/*
		Changes the transparency of a specified color to the specified alpha value.
		... Returns True unless the operation failed.
		*/
		bool ChangeColorTransparency(Color color, uint8 newAlpha);

		/* Resets the currently displayed frame to the first one - (0, 0). */
		void ResetFrame();

		/* Specifies whether the animation should be visible or not. */
		void SetVisibility(bool isVisible);

		/* Returns True if the animation is not visible. */
		bool IsVisible();

		/* Specifies whether the animation should be paused or not. */
		void Pause(bool isPaused);

		/* Returns True if the animation is paused. */
		bool IsPaused();

		/* Sets the color of the animation. */
		void SetColor(Color color);

		/* Moves the animation by the specified offset, horizontally and vertically. */
		void Move(FloatPair offset);

		/* Rotates the animation by a specified number of degrees. */
		void Rotate(float32 angle);
	};

	AnimatedImage::AnimatedImage() : scale(1.f, 1.f), isPaused(false) { }

	bool AnimatedImage::LoadSheet(const String& fileName, ShortPair frameAmount)
	{
		if (frameAmount.x == 0 || frameAmount.y == 0) return False;
		sheet.Load(fileName);
		sheet.SetScale(scale);
		frameSize.x = sheet.GetBaseSize().x / frameAmount.x;
		frameSize.y = sheet.GetBaseSize().y / frameAmount.y;
		return True;
	}

	bool AnimatedImage::LoadSheet(const String& fileName, ShortPair frameAmount, Color transparencyColor)
	{
		if (frameAmount.x == 0 || frameAmount.y == 0) return False;
		sheet.Load(fileName, transparencyColor);
		sheet.SetScale(scale);
		frameSize.x = sheet.GetBaseSize().x / frameAmount.x;
		frameSize.y = sheet.GetBaseSize().y / frameAmount.y;
		return True;
	}

	void AnimatedImage::SetPosition(ShortPair position)
	{
		sheet.SetPosition(position);
		sheet.SetScale(scale);
	}

	ShortPair AnimatedImage::GetPosition()
	{ return sheet.GetPosition(); }

	ShortPair AnimatedImage::GetFrameSize()
	{ return frameSize; }

	void AnimatedImage::SetScale(const FloatPair& scale)
	{
		this->scale = scale;
		sheet.SetScale(scale);
	}

	bool AnimatedImage::ChangeColorTransparency(Color color, uint8 newAlpha)
	{ return sheet.ChangeColorTransparency(color, newAlpha); }

	void AnimatedImage::ResetFrame()
	{ crtFrame.x = 0; crtFrame.y = 0; }

	void AnimatedImage::SetVisibility(bool isVisible)
	{ sheet.SetVisibility(isVisible); }

	bool AnimatedImage::IsVisible()
	{ return sheet.isVisible; }

	void AnimatedImage::Pause(bool isPaused)
	{ this->isPaused = isPaused; }

	bool AnimatedImage::IsPaused()
	{ return isPaused; }

	void AnimatedImage::SetColor(Color color)
	{ sheet.SetColor(color); }

	void AnimatedImage::Move(FloatPair offset)
	{ sheet.Move(offset); }

	void AnimatedImage::Rotate(float32 angle)
	{ sheet.Rotate(angle); }
}

#endif // INCLUDED_AX_ANIMATED_IMAGE