#ifndef INCLUDED_AX_TEXT
#define INCLUDED_AX_TEXT

#include "Font.hpp"
#include "Color.hpp"

namespace ax
{
	class Text
	{
	private:
		sf::Text text;

	public:
		/* Creates a new empty text object. */
		Text() { }

		/* Creates a new text object and sets its font. */
		Text(Font& font);

		/* Sets the font of the text object. */
		void Load(Font& font);

		/* Sets the string to display. */
		void SetString(const String& str);

		/* Sets the character size of the text object. */
		void SetSize(uint32 size);

		/* Sets the text style to use. */
		void SetStyle(TextStyle style);

		/* Sets the color of the text object. */
		void SetColor(Color color);

		/* Sets the position of the top left corner of the text object. */
		void SetPosition(FloatPair position);

		/* Sets the scale of the text object. */
		void SetScale(FloatPair scale);

		/* Moves the text object by the specified object. */
		void Move(FloatPair offset);

		/* Rotates the text object by the specified amount of degrees. */
		void Rotate(float32 degrees);
	};

	Text::Text(Font& font)
	{ text.setFont(font.font); }

	void Text::Load(Font& font)
	{ text.setFont(font.font); }

	void Text::SetString(const String& str)
	{ text.setString(str.ptr); }

	void Text::SetSize(uint32 size)
	{ text.setCharacterSize(size); }

	void Text::SetStyle(TextStyle style)
	{ text.setStyle(style); }

	void Text::SetColor(Color color)
	{ text.setColor(color); }

	void Text::SetPosition(FloatPair position)
	{ text.setPosition(position.x, position.y); }

	void Text::SetScale(FloatPair scale)
	{ text.setScale(scale.x, scale.y); }

	void Text::Move(FloatPair offset)
	{ text.move(offset.x, offset.y); }

	void Text::Rotate(float32 degrees)
	{ text.rotate(degrees); }
}

#endif // INCLUDED_AX_TEXT