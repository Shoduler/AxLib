#ifndef INCLUDED_AX_MUSIC
#define INCLUDED_AX_MUSIC

#include "Base.hpp"

namespace ax
{
	class Music
	{
	private:
		sf::Music music;

	public:
		/*
		Creates a new empty piece of music.
		Note that if the piece of music is short and will be played very frequently, <ax::SoundEffect> is more effective.
		*/
		Music() { }

		/* Creates a new piece of music from an audio file. */
		Music(const String& fileName);

		/* Loads the piece of music from an audio file. */
		bool Load(const String& fileName);

		/* Starts the playback of the music. */
		void Play();

		/* Pauses the playback of the music. */
		void Pause();

		/* Stops the playback of the music. */
		void Stop();

		/* Sets whether the music should loop or not. */
		void SetLooping(bool isLooping);

		/* Returns True if the music is set to loop. */
		bool IsLooping();

		/* Sets the pitch of the music. */
		void SetPitch(float32 pitch);

		/* Returns the pitch of the music. */
		float32 GetPitch();

		/* Sets the volume of the music. */
		void SetVolume(float32 volume);

		/* Returns the volume of the music. */
		float32 GetVolume();

		/* Sets the position of the music. */
		void SetPosition(float32 seconds);

		/* Returns the position of the music, in seconds. */
		float32 GetPositionInSeconds();

		/* Returns the duration of the music, in seconds. */
		float32 GetDurationInSeconds();
	};

	Music::Music(const String& fileName)
	{ music.openFromFile(fileName.ptr); }

	bool Music::Load(const String& fileName)
	{ return music.openFromFile(fileName.ptr); }

	void Music::Play()
	{ music.play(); }

	void Music::Pause()
	{ music.pause(); }

	void Music::Stop()
	{ music.stop(); }

	void Music::SetLooping(bool isLooping)
	{ music.setLoop(isLooping); }

	void Music::SetPitch(float32 pitch)
	{ music.setPitch(pitch); }

	void Music::SetVolume(float32 volume)
	{ music.setVolume(volume); }

	void Music::SetPosition(float32 seconds)
	{ music.setPlayingOffset(sf::Time(sf::seconds(seconds))); }

	float32 Music::GetDurationInSeconds()
	{ return music.getDuration().asSeconds(); }
}

#endif // INCLUDED_AX_MUSIC