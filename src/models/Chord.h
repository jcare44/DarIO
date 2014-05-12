#ifndef CHORD_H
#define CHORD_H

#include <vector>

using namespace std;

#include "Note.h"

#define NOTE_MIN 1
#define NOTE_MAX 5

class AbstractChordConstraint;

class Chord
{
	private:
		int numberOfNotes;
		Note* notes[NOTE_MAX];
		int mark;
		static vector<AbstractChordConstraint*> constraints;

	public:
		Chord();
		int getNumberOfNotes();
		void setNumberOfNotes(int _numberOfNotes);
		Note* getNote(int _i);
		int getMark();
		void setMark(int _mark);
		void grade();
		template <class E>
		static AbstractChordConstraint* getConstraint();
};

#endif //CHORD_H
