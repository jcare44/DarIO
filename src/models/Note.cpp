#include "Note.h"
#include <cstdlib>

Note::Note()
{
	if((rand()%100)/100 < MIDI_PAUSE_RATIO)
	{
		midi = MIDI_PAUSE;
	}
	else
	{
		midi = rand()%(MIDI_MAX-MIDI_MIN)+MIDI_MIN;
	}
	
	float _time[TIME_LENGTH] = TIME;
	time = _time[rand()%TIME_LENGTH];
}

int Note::getMidi()
{
	return midi;
}

void Note::setMidi(int _midi)
{
	midi = _midi;
}

float Note::getTime()
{
	return time;
}

void Note::setTime(float _time)
{
	time = _time;
}