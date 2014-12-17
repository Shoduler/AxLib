#ifndef INCLUDED_AX_STRING
#define INCLUDED_AX_STRING

#include "Base.hpp"

namespace ax
{
	class String
	{
	public:
		/* DO NOT ACCESS MANUALLY. */
		char* ptr; uint32 size;

		/* Creates a new empty string. */
		String();

		/* Creates a string based on an array of characters. */
		String(const char string[]);

		/* Creates a copy of an existing string. */
		String(const String& other);

		/* Destroys the string. */
		~String();

		/* Returns the character at the specified index. */
		char& operator[](uint32 index);

		/* Sets the contents of the string to another string's. */
		void operator=(const String& other);

		/* Returns True if the strings' contents are equal. */
		bool operator==(const String& other);

		/* Adds another string to the end of the string. */
		void operator+=(const String& other);

		/* Returns the string with another string added to the end of it. */
		String operator+(const String& other);

		/* Returns the amount of characters in the string. */
		uint32 GetSize();

		/*
		Returns the substring starting at the specified index of the specified length.
		... Returns "ERROR" if:
		... a) the closing index is invalid, or...
		... b) the specified length is zero.
		*/
		String GetSubstring(uint32 iStart, uint32 length);

		/*
		Converts the string to a positive integer and returns it.
		... Returns 0 if the string is not convertible to an integer.
		*/
		uint64 ToInteger();

		/* Converts all the string's characters to lowercase. */
		void ConvertToLowercase();

		/* Converts all the string's characters to uppercase. */
		void ConvertToUppercase();
	};

	String::String() : ptr(0), size(0) { }

	String::String(const char string[])
	{
		size = 0;

		uint16 i;
		for (i = 0; i <= MAX_STRING_SIZE; i++)
		{
			if (string[i] == '\0')
			{ break; }
		}

		if (i == 0 || i == MAX_STRING_SIZE) return;
		size = i;
		MemAlloc(ptr, char, size + 1);
		for (i = 0; i < size; i++) ptr[i] = string[i];
		ptr[size] = '\0';
	}

	String::String(const String& other)
	{ (*this) = other; }

	String::~String()
	{ MemFree(ptr); }

	char& String::operator[](uint32 index)
	{ return ptr[index]; }

	void String::operator=(const String& other)
	{
		size = other.size;
		MemAlloc(ptr, char, size + 1);
		for (uint32 i = 0; i < size; i++) ptr[i] = other.ptr[i];
		ptr[size] = '\0';
	}

	bool String::operator==(const String& other)
	{
		if (size != other.size) return False;

		for (uint32 i = 0; i < size; i++)
		{
			if (ptr[i] != other.ptr[i])
			{ return False; }
		}

		return True;
	}

	void String::operator+=(const String& other)
	{
		char* ptrCopy = ptr;
		MemAlloc(ptr, char, size + other.size + 1);

		uint32 i;
		for (i = 0; i < size; i++) ptr[i] = ptrCopy[i];
		for (i = size; i < size + other.size; i++) ptr[i] = other.ptr[i - size];

		size += other.size;
		ptr[size] = '\0';
	}

	String String::operator+(const String& other)
	{
		String output(ptr);
		output += other;
		return output;
	}

	uint32 String::GetSize()
	{ return size; }

	String String::GetSubstring(uint32 iStart, uint32 length)
	{
		if (iStart + length > size || length == 0) return "ERROR";
		char* charPtr;
		MemAlloc(charPtr, char, length + 1);
		for (uint32 i = 0; i < length; i++) charPtr[i] = ptr[i + iStart];
		charPtr[length] = '\0';
		String output(charPtr);
		MemFree(charPtr);
		return output;
	}

	uint64 String::ToInteger()
	{
		uint64 output = 0;

		for (uint32 i = 0; i < size; i++)
		{
			if (ptr[i] > 47 && ptr[i] < 58)
			{ output = output * 10 + ptr[i] - '0'; }
		}

		return output;
	}

	void String::ConvertToLowercase()
	{
		for (uint32 i = 0; i < size; i++)
		{
			if (ptr[i] == 'A') ptr[i] = 'a';
			elif (ptr[i] == 'B') ptr[i] = 'b';
			elif (ptr[i] == 'C') ptr[i] = 'c';
			elif (ptr[i] == 'D') ptr[i] = 'd';
			elif (ptr[i] == 'E') ptr[i] = 'e';
			elif (ptr[i] == 'F') ptr[i] = 'f';
			elif (ptr[i] == 'G') ptr[i] = 'g';
			elif (ptr[i] == 'H') ptr[i] = 'h';
			elif (ptr[i] == 'I') ptr[i] = 'i';
			elif (ptr[i] == 'J') ptr[i] = 'j';
			elif (ptr[i] == 'K') ptr[i] = 'k';
			elif (ptr[i] == 'L') ptr[i] = 'l';
			elif (ptr[i] == 'M') ptr[i] = 'm';
			elif (ptr[i] == 'N') ptr[i] = 'n';
			elif (ptr[i] == 'O') ptr[i] = 'o';
			elif (ptr[i] == 'P') ptr[i] = 'p';
			elif (ptr[i] == 'Q') ptr[i] = 'q';
			elif (ptr[i] == 'R') ptr[i] = 'r';
			elif (ptr[i] == 'S') ptr[i] = 's';
			elif (ptr[i] == 'T') ptr[i] = 't';
			elif (ptr[i] == 'U') ptr[i] = 'u';
			elif (ptr[i] == 'V') ptr[i] = 'v';
			elif (ptr[i] == 'W') ptr[i] = 'w';
			elif (ptr[i] == 'X') ptr[i] = 'x';
			elif (ptr[i] == 'Y') ptr[i] = 'y';
			elif (ptr[i] == 'Z') ptr[i] = 'z';
		}
	}

	void String::ConvertToUppercase()
	{
		for (uint32 i = 0; i < size; i++)
		{
			if (ptr[i] == 'a') ptr[i] = 'A';
			elif (ptr[i] == 'b') ptr[i] = 'B';
			elif (ptr[i] == 'c') ptr[i] = 'C';
			elif (ptr[i] == 'd') ptr[i] = 'D';
			elif (ptr[i] == 'e') ptr[i] = 'E';
			elif (ptr[i] == 'f') ptr[i] = 'F';
			elif (ptr[i] == 'g') ptr[i] = 'G';
			elif (ptr[i] == 'h') ptr[i] = 'H';
			elif (ptr[i] == 'i') ptr[i] = 'I';
			elif (ptr[i] == 'j') ptr[i] = 'J';
			elif (ptr[i] == 'k') ptr[i] = 'K';
			elif (ptr[i] == 'l') ptr[i] = 'L';
			elif (ptr[i] == 'm') ptr[i] = 'M';
			elif (ptr[i] == 'n') ptr[i] = 'N';
			elif (ptr[i] == 'o') ptr[i] = 'O';
			elif (ptr[i] == 'p') ptr[i] = 'P';
			elif (ptr[i] == 'q') ptr[i] = 'Q';
			elif (ptr[i] == 'r') ptr[i] = 'R';
			elif (ptr[i] == 's') ptr[i] = 'S';
			elif (ptr[i] == 't') ptr[i] = 'T';
			elif (ptr[i] == 'u') ptr[i] = 'U';
			elif (ptr[i] == 'v') ptr[i] = 'V';
			elif (ptr[i] == 'w') ptr[i] = 'W';
			elif (ptr[i] == 'x') ptr[i] = 'X';
			elif (ptr[i] == 'y') ptr[i] = 'Y';
			elif (ptr[i] == 'z') ptr[i] = 'Z';
		}
	}
}

#endif // INCLUDED_AX_STRING