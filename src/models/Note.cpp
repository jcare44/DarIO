#include "Note.h"
#include <cstdlib>
#include <time.h>
#include <random>

Note::Note()
{ 	std::random_device rdev;
	float r = rdev()%100;
	if(r/100 < MIDI_PAUSE_RATIO)
	{
		midi = MIDI_PAUSE;
	}
	else
	{
		midi = rdev()%(MIDI_MAX-MIDI_MIN)+MIDI_MIN;
	}

	float _duration[DURATION_LENGTH] = DURATION;
	duration = _duration[rdev()%DURATION_LENGTH];
}

Note::Note(Note* _n)
{
	midi = _n->getMidi();
	duration = _n->getDuration();
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

Note* Note::mutate(Note* _note)
{

        std::random_device rd;
        if (rd()%100 < MUTATE_RATE)
        {
            std::random_device rdev;
            float r = rdev()%100;
            if(r/100 < MIDI_PAUSE_RATIO)
            {
                midi = MIDI_PAUSE;
            }
            else
            {
                midi = rdev()%(MIDI_MAX-MIDI_MIN)+MIDI_MIN;
            }

            setMidi(midi);

            float _duration[DURATION_LENGTH] = DURATION;
            duration = _duration[rdev()%DURATION_LENGTH];

            setDuration(duration);
        }
    return _note;
}



