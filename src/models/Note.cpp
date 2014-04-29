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
