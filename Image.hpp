#ifndef INCLUDED_AX_IMAGE
#define INCLUDED_AX_IMAGE

#include "Rectangle.hpp"
#include "Color.hpp"
#include "String.hpp"

namespace ax
{
	class Image
	{
		sf::Texture texture;
		Rect rect;
		FloatPair scale;

	public:
		/* DO NOT ACCESS MANUALLY. */
		sf::Sprite sprite; bool isVisible;

		/* Creates a new empty image. */
		Image();

		/*
		Loads the image from an image file.
		... Returns True if the image file exists.
		*/
		bool Load(const String& fileName);

		/*
		Loads the image from an image file, turning the specified color transparent.
		... Returns True if the image file exists.
		*/
		bool Load(const String& fileName, Color transparencyColor);

		/* Sets the window coordinates of the image's top left corner.. */
		void SetPosition(ShortPair position);

		/* Returns the window coordinates of the image's top left corner. */
		ShortPair GetPosition();

		/* Returns the non-scaled size of the image. */
		ShortPair GetBaseSize();

		/* Returns the scaled size of the image. */
		ShortPair GetSize();

		/* Selects a specified rectangle of the image and discards the rest. */
		void CutFromBaseImage(Rect rect);

		/* Specifies whether the image should be visible or not. */
		void SetVisibility(bool isVisible);

		/* Returns True if the image is currently visible. */
		bool IsVisible();

		/* Sets the scale of the image. */
		void SetScale(const FloatPair& scale);

		/*
		Changes the transparency of a specified color to the specified alpha value.
		... Returns True unless the operation failed.
		*/
		bool ChangeColorTransparency(Color color, uint8 newAlpha);

		/* Sets the color of the image. */
		void SetColor(Color color);

		/* Moves the image by the specified offset, horizontally and vertically. */
		void Move(FloatPair offset);

		/* Rotates the image by a specified number of degrees. */
		void Rotate(float32 angle);
	};

	Image::Image() : scale(1.f, 1.f), isVisible(true) { }

	bool Image::Load(const String& fileName)
	{
		if (!texture.loadFromFile(fileName.ptr)) return False;
		sprite.setTexture(texture);
		sprite.setScale(scale.x, scale.y);
		rect.size.x = texture.getSize().x;
		rect.size.y = texture.getSize().y;
		return True;
	}

	bool Image::Load(const String& fileName, Color transparencyColor)
	{
		sf::Image image;
		if (!image.loadFromFile(fileName.ptr)) return False;
		image.createMaskFromColor(transparencyColor);
		if (!texture.loadFromImage(image)) return False;
		sprite.setTexture(texture);
		sprite.setScale(scale.x, scale.y);
		rect.size.x = texture.getSize().x;
		rect.size.y = texture.getSize().y;
		return True;
	}

	void Image::SetPosition(ShortPair position)
	{
		rect.position = position;
		sprite.setPosition(position.x, position.y);
	}

	ShortPair Image::GetPosition()
	{ return rect.position; }

	ShortPair Image::GetBaseSize()
	{ return rect.size; }

	ShortPair Image::GetSize()
	{ return ShortPair(rect.size.x * scale.x, rect.size.y * scale.y); }

	void Image::CutFromBaseImage(Rect rect)
	{ sprite.setTextureRect(rect); }

	void Image::SetVisibility(bool isVisible)
	{ this->isVisible = isVisible; }

	bool Image::IsVisible()
	{ return isVisible; }

	void Image::SetScale(const FloatPair& scale)
	{
		this->scale = scale;
		sprite.setScale(scale.x, scale.y);
	}

	bool Image::ChangeColorTransparency(Color color, uint8 newAlpha)
	{
		sf::Image image = texture.copyToImage();
		image.createMaskFromColor(color, newAlpha);
		return texture.loadFromImage(image);
	}

	void Image::SetColor(Color color)
	{ sprite.setColor(color); }
	
	void Image::Move(FloatPair offset)
	{ sprite.move(sf::Vector2<float32>(offset.x, offset.y)); }
	
	void Image::Rotate(float32 angle)
	{ sprite.rotate(angle); }
}

#endif // INCLUDED_AX_IMAGE