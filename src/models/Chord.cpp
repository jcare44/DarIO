#include "Chord.h"
#include <cstdlib>

Chord::Chord()
{
	int max = rand()%(NOTE_MAX-NOTE_MIN)+NOTE_MIN;
	
	for(numberOfNotes=0;numberOfNotes<max;++numberOfNotes)
	{
		notes[numberOfNotes] = new Note();
	}
}
