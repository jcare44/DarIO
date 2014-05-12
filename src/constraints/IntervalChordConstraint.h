#ifndef INTERVAL_CHORD_CONSTRAINT_H
#define INTERVAL_CHORD_CONSTRAINT_H

#include "../abstracts/AbstractChordConstraint.h"
#include "../models/Chord.h"

class IntervalChordConstraint : public AbstractChordConstraint
{
	private:
		int nbNotes;
	public:
		IntervalChordConstraint(int _nbNotes);
		bool eval(Chord* _chord);
};

#endif //INTERVAL_CHORD_CONSTRAINT_H
