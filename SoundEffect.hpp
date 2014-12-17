#ifndef INCLUDED_AX_SOUND_EFFECT
#define INCLUDED_AX_SOUND_EFFECT

#include "Base.hpp"

namespace ax
{
	class SoundEffect
	{
	private:
		sf::Sound sound;
		sf::SoundBuffer buffer;

	public:
		/*
		Creates a new empty sound effect.
		Note that if the sound effect is very long, <ax::Music> is more effective.
		*/
		SoundEffect() { }

		/* Creates a new sound effect from an existing audio file. */
		SoundEffect(const String& fileName);

		/* Loads the sound effect from an existing audio file. */
		bool Load(const String& fileName);

		/* Starts the playback of the sound effect. */
		void Play();

		/* Pauses the playback of the sound effect. */
		void Pause();

		/* Stops the playback of the sound effect. */
		void Stop();

		/* Sets whether the sound effect should loop or not. */
		void SetLooping(bool isLooping);

		/* Returns True if the sound effect is set to loop. */
		bool IsLooping();

		/* Sets the pitch of the sound effect. */
		void SetPitch(float32 pitch);

		/* Returns the pitch of the sound effect. */
		float32 GetPitch();

		/* Sets the volume of the sound effect. */
		void SetVolume(float32 volume);

		/* Returns the volume of the sound effect. */
		float32 GetVolume();

		/* Sets the position of the sound effect. */
		void SetPosition(float32 seconds);

		/* Returns the position of the sound effect, in seconds. */
		float32 GetPositionInSeconds();
	};

	SoundEffect::SoundEffect(const String& fileName)
	{ Load(fileName); }

	bool SoundEffect::Load(const String& fileName)
	{
		if (!buffer.loadFromFile(fileName.ptr)) { return False; }
		sound.setBuffer(buffer);
		return True;
	}

	void SoundEffect::Play()
	{ sound.play(); }

	void SoundEffect::Pause()
	{ sound.pause(); }

	void SoundEffect::Stop()
	{ sound.stop(); }

	void SoundEffect::SetLooping(bool isLooping)
	{ sound.setLoop(isLooping); }

	bool SoundEffect::IsLooping()
	{ return sound.getLoop(); }

	void SoundEffect::SetPitch(float32 pitch)
	{ sound.setPitch(pitch); }

	float32 SoundEffect::GetPitch()
	{ return sound.getPitch(); }

	void SoundEffect::SetVolume(float32 volume)
	{ sound.setVolume(volume); }

	float32 SoundEffect::GetVolume()
	{ return sound.getVolume(); }

	void SoundEffect::SetPosition(float32 seconds)
	{ sound.setPlayingOffset(sf::Time(sf::seconds(seconds))); }

	float32 SoundEffect::GetPositionInSeconds()
	{ return sound.getPlayingOffset().asSeconds(); }
}

#endif // INCLUDED_AX_SOUND_EFFECT