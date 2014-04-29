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
		int mark;

	public:
		Chord();
		int getNumberOfNotes();
		void setNumberOfNotes(int _numberOfNotes);
		Note* getNote(int _i);
		int getMark();
		void setMark(int _mark);
};

#endif //CHORD_H
