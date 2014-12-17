#ifndef INCLUDED_AX_BASE
#define INCLUDED_AX_BASE

#pragma comment(lib, "SFML/sfml-system-d.lib")
#pragma comment(lib, "SFML/sfml-window-d.lib")
#pragma comment(lib, "SFML/sfml-graphics-d.lib")
#pragma comment(lib, "SFML/sfml-audio-d.lib")

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <cstdlib>

typedef signed char int8;
typedef unsigned char uint8;
typedef signed short int16;
typedef unsigned short uint16;
typedef signed int int32;
typedef unsigned int uint32;
typedef signed long long int64;
typedef unsigned long long uint64;
typedef float float32;
typedef double float64;

#define MemAlloc(ptr, type, size) ptr = (type*)malloc(sizeof(type) * size)
#define MemFree(ptr) if (ptr != 0) free(ptr); ptr = 0

#define Generic1T template<typename T>
#define Generic2T template<typename T1, typename T2>

#define MAX_ARRAY_SIZE 10000
#define MAX_STRING_SIZE 30000

#define True true
#define False false
#define elif else if

namespace ax
{
	typedef sf::Keyboard::Key Key;
	typedef sf::Mouse::Button Button;
	typedef sf::Event::EventType EventType;
	typedef sf::Text::Style TextStyle;

	enum InputStatus
	{ None, Tapped, Released, Held };
}

#endif // INCLUDED_AX_BASE