#ifndef INCLUDED_AX_MAP
#define INCLUDED_AX_MAP

#include "Array.hpp"
#include "Pair.hpp"
#include "String.hpp"

namespace ax
{
	Generic2T class Map
	{
	public:
		/* DO NOT ACCESS MANUALLY. */
		Array<Pair<T1, T2>> arr;

		/* Creates a new empty map. */
		Map() { }

		/* Creates a copy of an existing map. */
		Map(const Map<T1, T2>& other);

		/* Returns the value at the specified key. */
		T2& operator[](const T1& key);

		/* Sets the contents of the map to another map's. */
		void operator=(const Map<T1, T2>& other);

		/* Returns True if the maps' contents are equal. */
		bool operator==(const Map<T1, T2>& other);

		/*
		Returns the index of the specified key.
		... Returns (MAX_ARRAY_SIZE + 1) if the key is invalid.
		*/
		uint32 IndexOfKey(const T1& key);

		/* Returns the key at the specified index. */
		T1& KeyAtIndex(uint32 index);

		/* Returns the value at the specified index. */
		T2& ValueAtIndex(uint32 index);

		/*
		Inserts a new key-value pair.
		... Returns False if the key already exists.
		*/
		bool Add(const T1& key, const T2& value);

		/*
		Erases the value at the specified key as well as the key itself.
		... Returns False if the key is invalid.
		*/
		bool Erase(const T1& key);

		/* Returns the amount of key-value pairs in the map. */
		uint32 GetSize();

		/* Empties the contents of the map. */
		void Empty();

		/*
		Swaps the values at the two specified keys.
		... Returns False if either of the keys is invalid.
		*/
		bool Swap(const T1& keyOne, const T1& keyTwo);

		/*
		Swaps the values at the two specified indices.
		... Returns False if either of the indices is invalid.
		*/
		bool Swap(uint16 iOne, uint16 iTwo);

		/* Returns True if the specified key is  valid. */
		bool IsKeyValid(const T1& key);
	};

	Generic2T Map<T1, T2>::Map(const Map<T1, T2>& other)
	{ (*this) = other; }

	Generic2T T2& Map<T1, T2>::operator[](const T1& key)
	{
		uint32 i;
		for (i = 0; i < arr.size; i++)
		{
			if (arr.ptr[i].x == key)
			{ break; }
		}

		return arr.ptr[i].y;
	}

	Generic2T void Map<T1, T2>::operator=(const Map<T1, T2>& other)
	{ arr = other.arr; }

	Generic2T bool Map<T1, T2>::operator==(const Map<T1, T2>& other)
	{
		if (arr.size != other.arr.size) return False;

		for (uint32 i = 0; i < other.arr.size; i++)
		{
			if (arr.ptr[i] != other.arr.ptr[i])
			{ return False; }
		}

		return True;
	}

	Generic2T uint32 Map<T1, T2>::IndexOfKey(const T1& key)
	{
		uint32 i;

		for (i = 0; i < arr.size; i++)
		{
			if (arr.ptr[i].x == key)
			{ break; }
		}

		return MAX_ARRAY_SIZE + 1;
	}

	Generic2T T1& Map<T1, T2>::KeyAtIndex(uint32 index)
	{ return arr.ptr[index].x; }

	Generic2T T2& Map<T1, T2>::ValueAtIndex(uint32 index)
	{ return arr.ptr[index].y; }

	Generic2T bool Map<T1, T2>::Add(const T1& key, const T2& value)
	{
		for (uint32 i = 0; i < arr.size; i++)
		{
			if (arr.ptr[i].x == key)
			{ return False; }
		}

		return arr.PushBack(Pair<T1, T2>(key, value));
	}

	Generic2T bool Map<T1, T2>::Erase(const T1& key)
	{
		for (uint32 i = 0; i < arr.size; i++)
		{
			if (arr.ptr[i].x == key)
			{ return arr.Pop(i); }
		}

		return False;
	}

	Generic2T uint32 Map<T1, T2>::GetSize()
	{ return arr.size; }

	Generic2T bool Map<T1, T2>::Swap(const T1& keyOne, const T1& keyTwo)
	{ return arr.Swap(IndexOfKey(keyOne), indexOfKey(keyTwo)); }

	Generic2T bool Map<T1, T2>::Swap(uint16 iOne, uint16 iTwo)
	{ return arr.Swap(iOne, iTwo); }

	Generic2T bool Map<T1, T2>::IsKeyValid(const T1& key)
	{
		for (uint32 i = 0; i < arr.size; i++)
		{
			if (arr.ptr[i].x == key)
			{ return True; }
		}

		return False;
	}

	Generic1T using StringMap = Map<String, T>;
}

#endif // INCLUDED_AX_MAP