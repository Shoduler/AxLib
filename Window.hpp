#ifndef INCLUDED_AX_WINDOW
#define INCLUDED_AX_WINDOW

#include "Color.hpp"
#include "AnimatedImage.hpp"
#include "Array.hpp"

namespace ax
{
	class Window
	{
	private:
		sf::Event ev;
		Color clearColor;
		sf::Keyboard keyboard;
		Array<bool> keysPrevDown, buttonsPrevDown;

	public:
		/* DO NOT ACCESS THIS MANUALLY. */
		sf::RenderWindow window;

		/* Creates a new window, but does not open it. */
		Window();

		/* Creates a new window, sets its size and title, and opens it. */
		Window(ShortPair size, const String& title);

		/* Sets the window's size and title and opens it. */
		void Open(ShortPair size, const String& title);

		/* Returns True if the window is open. */
		bool IsOpen();

		/* Sets the window's size. */
		void SetSize(ShortPair size);

		/* Sets the window's title. */
		void SetTitle(const String& title);

		/* Sets the position of the window's top left corner. */
		void SetPosition(ShortPair position);

		/* Sets the window's clear color. */
		void SetClearColor(Color color);

		/* Clears the window with a certain color. Should be called once every frame. */
		void Clear(Color color);

		/* Clears the window with the set clear color. Should be called once every frame. */
		void Clear();

		/* Draws a static image to the screen. */
		void Draw(Image& image);

		/* Draws the current frame of an animated image to the screen. */
		void Draw(AnimatedImage& image);

		/* Displays all the changes made to the window. Should be called once every frame. */
		void Display();

		/* Closes the window. */
		void Close();

		/* Specifies whether the window should be visible or not. */
		void SetVisibility(bool isVisible);

		/* Takes a screenshot and saves it to the specified file name. */
		void TakeScreenshot(const String& outputFileName);

		/* Returns True if an event is waiting to be processed. */
		bool CheckForEvent();

		/* Waits until an event is waiting to be processed and then returns True. */
		bool WaitForEvent();

		/* Returns True if the current event type is equal to the specified event type. */
		bool IsCurrentEvent(EventType type);

		/* Returns the status of a specified keyboard key. */
		InputStatus GetKeyStatus(Key key);

		/* Returns the status of a specified mouse button. */
		InputStatus GetButtonStatus(Button button);

		/* Specifies whether the mouse cursor should be visible or not. */
		void SetCursorVisibility(bool isVisible);

		/* Sets the coordinates of the mouse cursor relative to the window. */
		void SetMousePosition(ShortPair position);

		/* Returns the coordinates of the mouse cursor relative to the window. */
		ShortPair GetMousePosition();
	};

	Window::Window()
	{
		keysPrevDown.InsertSpaces(0, 101);
		buttonsPrevDown.InsertSpaces(0, 5);
	}

	Window::Window(ShortPair size, const String& title) : window(sf::VideoMode(size.x, size.y, 32), title.ptr)
	{
		keysPrevDown.InsertSpaces(0, 101);
		buttonsPrevDown.InsertSpaces(0, 5);
	}

	void Window::Open(ShortPair size, const String& title)
	{
		window.create(sf::VideoMode(size.x, size.y, 32), title.ptr);
	}

	bool Window::IsOpen()
	{
		return window.isOpen();
	}

	void Window::SetSize(ShortPair size)
	{
		window.setSize(sf::Vector2<uint32>(size.x, size.y));
	}

	void Window::SetTitle(const String& title)
	{
		window.setTitle(title.ptr);
	}

	void Window::SetPosition(ShortPair position)
	{
		window.setPosition(sf::Vector2<int32>(position.x, position.y));
	}

	void Window::SetClearColor(Color color)
	{
		clearColor = color;
	}

	void Window::Clear(Color color)
	{
		window.clear(color);
	}

	void Window::Clear()
	{
		window.clear(clearColor);
	}

	void Window::Draw(Image& image)
	{
		if (image.isVisible) { window.draw(image.sprite); }
	}

	void Window::Draw(AnimatedImage& image)
	{
		if (!image.IsPaused())
		{
			if (image.crtFrame.x * image.frameSize.x >= image.sheet.GetBaseSize().x)
			{
				image.crtFrame.x = 0;

				if (2 * image.crtFrame.y * image.frameSize.y >= image.sheet.GetBaseSize().y)
				{
					image.crtFrame.y = 0;
				}

				else if (image.frameSize.y != image.sheet.GetBaseSize().y)
				{
					image.crtFrame.y++;
				}
			}

			image.sheet.CutFromBaseImage(Rect(
				image.crtFrame.x * image.frameSize.x,
				image.crtFrame.y * image.frameSize.y,
				image.frameSize));
			image.crtFrame.x++;
		}

		Draw(image.sheet);
	}

	void Window::Display()
	{
		window.display();
	}

	void Window::Close()
	{
		window.close();
	}

	void Window::SetVisibility(bool isVisible)
	{
		window.setVisible(isVisible);
	}

	void Window::TakeScreenshot(const String& outputFileName)
	{
		window.capture().saveToFile(outputFileName.ptr);
	}

	bool Window::CheckForEvent()
	{
		return window.pollEvent(ev);
	}

	bool Window::WaitForEvent()
	{
		return window.waitEvent(ev);
	}

	bool Window::IsCurrentEvent(EventType type)
	{
		return (ev.type == type);
	}

	InputStatus Window::GetKeyStatus(Key key)
	{
		bool isDown = False;
		InputStatus status = InputStatus::None;

		if (keyboard.isKeyPressed(key)) isDown = True;

		if (isDown)
		{
			if (keysPrevDown[key])
			{
				status = InputStatus::Held;
			}

			else
			{
				status = InputStatus::Tapped;
			}
		}

		else if (!isDown && keysPrevDown[key])
		{
			status = InputStatus::Released;
		}

		keysPrevDown[key] = isDown;
		return status;
	}

	InputStatus Window::GetButtonStatus(Button button)
	{
		bool isDown = False;
		InputStatus status = InputStatus::None;

		if (sf::Mouse::isButtonPressed(button)) isDown = True;

		if (isDown)
		{
			if (buttonsPrevDown[button])
			{
				status = InputStatus::Held;
			}

			else
			{
				status = InputStatus::Tapped;
			}
		}

		else if (!isDown && buttonsPrevDown[button])
		{
			status = InputStatus::Released;
		}

		buttonsPrevDown[button] = isDown;
		return status;
	}

	void Window::SetCursorVisibility(bool isVisible)
	{
		window.setMouseCursorVisible(isVisible);
	}

	void Window::SetMousePosition(ShortPair position)
	{
		sf::Mouse::setPosition(sf::Vector2<int32>(position.x, position.y), window);
	}

	ShortPair Window::GetMousePosition()
	{
		return ShortPair(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
	}
}

#endif // INCLUDED_AX_WINDOW