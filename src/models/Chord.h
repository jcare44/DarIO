#ifndef CHORD_H
#define CHORD_H

#include <cstdlib>
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
		float mark;
		static vector<AbstractChordConstraint*> constraints;

	public:
		Chord();
		Chord(Chord* _c);
		int getNumberOfNotes();
		void setNumberOfNotes(int _numberOfNotes);
		Note* getNote(int _i);
		void setNote(int _i, Note* _note);
		float getMark();
		void setMark(float _mark);
		void grade();
		void mutate();
		template <class E>
		static AbstractChordConstraint* getConstraint();
};

template <class E>
AbstractChordConstraint* Chord::getConstraint()
{
	for(int i = 0;i < constraints.size();++i)
	{
		if(dynamic_cast<E*>(constraints[i])!=NULL)
		{
			return constraints[i];
		}
	}

	return NULL;
}

#endif //CHORD_H
