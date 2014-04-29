#ifndef CHORD_H
#define CHORD_H

#include "Note.h"

#define NOTE_MIN 1
#define NOTE_MAX 5

class Chord
{
	private:
		int numberOfNotes;
		Note* notes[NOTE_MAX];

	public:
		Chord();
        int getNumberOfNotes();
        void setNumberOfNotes(int _numberOfNotes);
};

#endif //CHORD_H
