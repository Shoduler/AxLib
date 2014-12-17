#ifndef INCLUDED_AX_COLOR
#define INCLUDED_AX_COLOR

#include "Base.hpp"

namespace ax
{
	class Color
	{
	public:
		uint8 r, g, b, a;

		/* Creates a new color with its red, green, blue and alpha values set to 255. */
		Color();

		/* Creates a new color with specified red, green, blue and alpha values. */
		Color(uint8 r, uint8 g, uint8 b, uint8 a = 255);

		/* Sets the red, green, blue and alpha values to another color's. */
		void operator=(Color other);

		/* Returns True if the red, green, blue and alpha values are equal to another color's. */
		bool operator==(Color other);

		/* Returns True if the red, green, blue and alpha values are not equal to another color's. */
		bool operator!=(Color other);

		/* USED FOR INTERNAL PURPOSES ONLY. */
		operator sf::Color();
	};

	Color::Color(): r(0), g(0), b(0), a(255) { }

	Color::Color(uint8 r, uint8 g, uint8 b, uint8 a): r(r), g(g), b(b), a(a) { }

	void Color::operator=(Color other)
	{
		r = other.r;
		g = other.g;
		b = other.b;
		a = other.a;
	}

	bool Color::operator==(Color other)
	{ return (r == other.r && g == other.g && b == other.b && a == other.a); }

	bool Color::operator!=(Color other)
	{ return !((*this) == other); }

	Color::operator sf::Color()
	{ return sf::Color(r, g, b, a); }
}

#endif // INCLUDED_AX_COLOR