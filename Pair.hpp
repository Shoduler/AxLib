#ifndef INCLUDED_AX_PAIR
#define INCLUDED_AX_PAIR

#include "Base.hpp"

namespace ax
{
	Generic2T class Pair
	{
	public:
		T1 x;
		T2 y;

		/* Creates a new empty pair. */
		Pair() { }

		/* Creates a new pair with set values. */
		Pair(const T1& x, const T2& y) : x(x), y(y) { }

		/* Creates a new pair with set values. */
		Pair(const Pair<T1, T2>& pair) : x(pair.x), y(pair.y) { }

		void operator=(const Pair<T1, T2>& pair);
		bool operator==(const Pair<T1, T2>& pair);
		bool operator!=(const Pair<T1, T2>& pair);
	};

	Generic2T void Pair<T1, T2>::operator=(const Pair<T1, T2>& pair)
	{ x = pair.x; y = pair.y; }

	Generic2T bool Pair<T1, T2>::operator==(const Pair<T1, T2>& pair)
	{ return (x == pair.x && y == pair.y); }

	Generic2T bool Pair<T1, T2>::operator!=(const Pair<T1, T2>& pair)
	{ return (x != pair.x && y != pair.y); }

	typedef Pair<uint16, uint16> ShortPair;
	typedef Pair<float32, float32> FloatPair;
}

#endif // INCLUDED_AX_PAIR