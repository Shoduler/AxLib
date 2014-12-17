#ifndef INCLUDED_AX_FONT
#define INCLUDED_AX_FONT

#include "Base.hpp"

namespace ax
{
	class Font
	{
	public:
		/* DO NOT ACCESS THIS MANUALLY. */
		sf::Font font;

		/* Creates a new empty font. */
		Font() { }

		/* Creates a new font form a TrueType or OpenType font file. */
		Font(const String& fileName);

		/*
		Loads the font from a TrueType or OpenType font file.
		... Returns True if the specified font file exists.
		*/
		bool Load(const String& fileName);
	};

	Font::Font(const String& fileName)
	{ font.loadFromFile(fileName.ptr); }

	bool Font::Load(const String& fileName)
	{ return font.loadFromFile(fileName.ptr); }
}

#endif // INCLUDED_AX_FONT