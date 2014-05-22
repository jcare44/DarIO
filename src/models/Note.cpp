#include "Note.h"
#include <cstdlib>
#include <time.h>

Note::Note()
{
	std::srand(time(NULL));
	float r = rand()%100;
	if(r/100 < MIDI_PAUSE_RATIO)
	{
		midi = MIDI_PAUSE;
	}
	else
	{
		std::srand(time(NULL));
		midi = rand()%(MIDI_MAX-MIDI_MIN)+MIDI_MIN;
	}
	std::srand(time(NULL));
	float _duration[DURATION_LENGTH] = DURATION;
	duration = _duration[rand()%DURATION_LENGTH];
}

int Note::getMidi()
{
	return midi;
}

void Note::setMidi(int _midi)
{
	midi = _midi;
}

float Note::getDuration()
{
	return duration;
}

void Note::setDuration(float _duration)
{
	duration = _duration;
}
