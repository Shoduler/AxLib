#ifndef INCLUDED_AX_CLOCK
#define INCLUDED_AX_CLOCK

#include "Base.hpp"

namespace ax
{
	class Clock
	{
	private:
		sf::Clock clock;

	public:
		/* Creates a new clock and starts its timer. */
		Clock() { }

		/* Resets the timer. */
		void Restart();

		/* Returns the time passed since the last reset, in seconds. */
		float32 GetTimeInSeconds();

		/* Returns the time passed since the last reset, in milliseconds. */
		int32 GetTimeInMilliseconds();

		/* Returns the time passed since the last reset, in microseconds. */
		int64 GetTimeInMicroseconds();
	};

	void Clock::Restart()
	{ clock.restart(); }

	float32 Clock::GetTimeInSeconds()
	{ return clock.getElapsedTime().asSeconds(); }

	int32 Clock::GetTimeInMilliseconds()
	{ return clock.getElapsedTime().asMilliseconds(); }

	int64 Clock::GetTimeInMicroseconds()
	{ return clock.getElapsedTime().asMicroseconds(); }
}

#endif // INCLUDED_AX_CLOCK