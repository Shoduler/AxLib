#ifndef INCLUDED_AX_ARRAY
#define INCLUDED_AX_ARRAY

#include "Base.hpp"

namespace ax
{
	Generic1T class Array
	{
	public:
		/* DO NOT ACCESS MANUALLY. */
		T* ptr; uint32 size;

		/* Creates a new empty array. */
		Array();

		/* Creates a copy of an existing array. */
		Array(const Array<T>& other);

		/* Destroys the array. */
		~Array();

		/* Returns the value at the specified index. */
		T& operator[](uint32 index);

		/* Sets the contents of the array to another array's. */
		void operator=(const Array<T>& other);

		/* Returns True if the arrays' contents are equal. */
		bool operator==(const Array<T>& other);

		/*
		Inserts a specified amount of empty values starting from the specified index.
		... Returns False if:
		... a) the new size would be greater than the maximum array size, or...
		... b) the specified index is invalid.
		*/
		bool InsertSpaces(uint32 iFirst, uint32 sizeInc);

		/*
		Erases a specified amount of values starting from the specified index.
		... Returns False if:
		... a) the new size would be less than zero, or...
		... b) the specified index is invalid.
		*/
		bool EraseValues(uint32 iFirst, uint32 sizeDec);

		/*
		Inserts a value at the specified index.
		... Returns False if:
		... a) the new size would be greater than the maximum array size, or...
		... b) the specified index is invalid.
		*/
		bool Insert(const T& value, uint32 index);

		/*
		Inserts an array of values starting from the specified index.
		... Returns False if:
		... a) the new size would be greater than the maximum array size, or...
		... b) the specified starting index is invalid.
		*/
		bool Insert(const Array<T>& values, uint32 iFirst);

		/*
		Erases the value at the specified index.
		... Returns False if:
		... a) the new size would be less than zero, or...
		... b) the specified index is invalid.
		*/
		bool Pop(uint32 index);

		/*
		Inserts a value at the end of the array.
		... Returns False if the new size would be greater than the maximum array size.
		*/
		bool PushBack(const T& value);

		/*
		Inserts an array of values at the end of the array.
		... Returns False if the new size would be greater than the maximum array size.
		*/
		bool PushBack(const Array<T>& values);

		/*
		Erases the value at the end of the array.
		... Returns False if the new size would be less than zero.
		*/
		bool PopBack();

		/*
		Erases a specified amount of values starting from the end of the array.
		... Returns False if the new size would be less than zero.
		*/
		bool PopBack(uint32 sizeDec);

		/* Returns the amount of values in the array. */
		uint32 GetSize();

		/* Empties the contents of the array. */
		void Empty();

		/*
		Swaps the values at the two specified indices.
		... Returns False if either of the indices is invalid.
		*/
		bool Swap(uint32 iOne, uint32 iTwo);

		/* Returns True if the specified index is  valid. */
		bool IsIndexValid(uint32 index);
	};

	Generic1T Array<T>::Array() : ptr(0), size(0) { }

	Generic1T Array<T>::Array(const Array<T>& other)
	{ (*this) = other; }

	Generic1T Array<T>::~Array()
	{ MemFree(ptr); }

	Generic1T T& Array<T>::operator[](uint32 index)
	{ return ptr[index]; }

	Generic1T void Array<T>::operator=(const Array<T>& other)
	{
		if (other.size > 0)
		{
			size = other.size;
			MemAlloc(ptr, T, size);
			for (uint32 i = 0; i < size; i++) ptr[i] = other.ptr[i];
		}

		else Empty();
	}

	Generic1T bool Array<T>::operator==(const Array<T>& other)
	{
		if (size != other.size) return False;

		for (uint32 i = 0; i < size; i++)
		{
			if (ptr[i] != other.ptr[i])
			{ return False; }
		}

		return True;
	}

	Generic1T bool Array<T>::InsertSpaces(uint32 iFirst, uint32 sizeInc)
	{
		if (size + sizeInc > MAX_ARRAY_SIZE || iFirst > size) return False;
		T* ptrCopy = ptr;
		size += sizeInc;
		MemAlloc(ptr, T, size);

		uint32 i = 0;
		for (i = 0; i < iFirst; i++) ptr[i] = ptrCopy[i];
		for (i = iFirst + sizeInc; i < size; i++) ptr[i] = ptrCopy[i - sizeInc];

		MemFree(ptrCopy);
		return True;
	}

	Generic1T bool Array<T>::EraseValues(uint32 iFirst, uint32 sizeDec)
	{
		if (size < iFirst + sizeDec || iFirst >= size) return False;
		size -= sizeDec;
		if (size == 0) { MemAlloc(ptr, T, 1); return True; }
		T* ptrCopy = ptr;
		MemAlloc(ptr, T, size);

		uint32 i;
		for (i = 0; i < iFirst; i++) ptr[i] = ptrCopy[i];
		for (i = iFirst; i < size; i++) ptr[i] = ptrCopy[i + sizeDec];

		MemFree(ptrCopy);
		return True;
	}

	Generic1T bool Array<T>::Insert(const T& value, uint32 index)
	{
		if (!InsertSpaces(index, 1)) return False;
		if (index < size) { ptr[index] = value; return True; }
		return False;
	}

	Generic1T bool Array<T>::Insert(const Array<T>& values, uint32 iFirst)
	{
		if (ptr == values.ptr)
		{
			T* ptrCopy;
			MemAlloc(ptrCopy, T, values.size);

			uint32 i;
			for (i = 0; i < values.size; i++) ptrCopy[i] = values.ptr[i];
			if (!InsertSpaces(iFirst, values.size)) return False;
			for (i = 0; i < values.size; i++) ptr[i + iFirst] = ptrCopy[i];

			MemFree(ptrCopy);
		}

		else
		{
			if (!InsertSpaces(iFirst, values.size)) return False;
			for (uint32 i = 0; i < values.size; i++) ptr[i + iFirst] = values.ptr[i];
		}

		return True;
	}

	Generic1T bool Array<T>::Pop(uint32 index)
	{ return EraseValues(index, 1); }

	Generic1T bool Array<T>::PushBack(const T& value)
	{ return Insert(value, size); }

	Generic1T bool Array<T>::PushBack(const Array<T>& values)
	{ return Insert(values, size); }

	Generic1T bool Array<T>::PopBack()
	{ return Pop(size - 1); }

	Generic1T bool Array<T>::PopBack(uint32 sizeDec)
	{ return Pop(size - sizeDec, sizeDec); }

	Generic1T uint32 Array<T>::GetSize()
	{ return size; }

	Generic1T void Array<T>::Empty()
	{ ptr = 0; size = 0; }

	Generic1T bool Array<T>::Swap(uint32 iOne, uint32 iTwo)
	{
		if (iOne >= size || iTwo >= size || iOne == iTwo) return False;
		T oldVal = ptr[iOne];
		ptr[iOne] = ptr[iTwo];
		ptr[iTwo] = oldVal;
		return True;
	}

	Generic1T bool Array<T>::IsIndexValid(uint32 index)
	{ return (index < size); }
}

#endif // INCLUDED_AX_ARRAY