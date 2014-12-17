#ifndef INCLUDED_AX_RECTANGLE
#define INCLUDED_AX_RECTANGLE

#include "Base.hpp"
#include "Pair.hpp"

namespace ax
{
	class Rectangle
	{
	public:
		ShortPair position, size;

		/* Creates a new rectangle with its values set to 0. */
		Rectangle();

		/* Creates a new rectangle with specified values. */
		Rectangle(uint16 x, uint16 y, uint16 width, uint16 height);

		/* Creates a new rectangle with specified values. */
		Rectangle(uint16 x, uint16 y, ShortPair size);

		/* Creates a new rectangle with specified values. */
		Rectangle(ShortPair position, uint16 width, uint16 height);

		/* Creates a new rectangle with specified values. */
		Rectangle(ShortPair position, ShortPair size);

		/* Returns true if the specified screen coordinates are within the rectangle's bounds. */
		bool Contains(ShortPair pos);

		/* Sets the contents equal to another rectangle's. */
		void operator=(const Rectangle& other);

		/* Returns True if the position and size of both rectangles are equal. */
		bool operator==(const Rectangle& other);

		/* Multiplies the x and width values with the factor's x value and the y and height values with the factor's y value. */
		void operator*=(const FloatPair& factor);

		/* Returns the rectangle with the x and width values multiplied with the factor's x value and the y and height values multiplied with the factor's y value. */
		Rectangle operator*(const FloatPair& factor);

		/* USED FOR INTERNAL PURPOSES ONLY. */
		operator sf::Rect<int32>();
	};

	Rectangle::Rectangle(): position(0, 0), size(0, 0) { }

	Rectangle::Rectangle(uint16 x, uint16 y, uint16 width, uint16 height): position(x, y), size(width, height) { }

	Rectangle::Rectangle(uint16 x, uint16 y, ShortPair size): position(x, y), size(size) { }

	Rectangle::Rectangle(ShortPair position, uint16 width, uint16 height): position(position), size(width, height) { }

	Rectangle::Rectangle(ShortPair position, ShortPair size): position(position), size(size) { }

	bool Rectangle::Contains(ShortPair pos)
	{
		return(pos.x >= position.x && pos.y >= position.y &&
			pos.x <= position.x + size.x && pos.y <= position.y + size.y);
	}

	void Rectangle::operator=(const Rectangle& other)
	{
		position = other.position;
		size = other.size;
	}

	bool Rectangle::operator==(const Rectangle& other)
	{ return (position == other.position && size == other.size); }

	void Rectangle::operator*=(const FloatPair& factor)
	{
		position.x *= factor.x;
		position.y *= factor.y;
		size.x *= factor.x;
		size.y *= factor.y;
	}

	Rectangle Rectangle::operator*(const FloatPair& factor)
	{
		Rectangle output = (*this);
		output *= factor;
		return output;
	}

	Rectangle::operator sf::Rect<int32>()
	{ return sf::Rect<int32>(position.x, position.y, size.x, size.y); }

	typedef Rectangle Rect;
}

#endif // INCLUDED_AX_RECTANGLE