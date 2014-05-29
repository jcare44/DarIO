#ifndef SEVENTH_CHORD_CONSTRAINT_H
#define SEVENTH_CHORD_CONSTRAINT_H

#include "../abstracts/AbstractChordConstraint.h"
#include "../models/Chord.h"

class SeventhChordConstraint : public AbstractChordConstraint
{
	public:
		SeventhChordConstraint();
		float eval(Chord* _chord);
};

#endif //SEVENTH_CHORD_CONSTRAINT_H
