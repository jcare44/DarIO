#ifndef ABSTRACT_CHORD_CONSTRAINT_H
#define ABSTRACT_CHORD_CONSTRAINT_H

#include "../models/Chord.h"

class AbstractChordConstraint
{
	public:
		virtual bool eval(Chord* _chord) = 0;
};

#endif //ABSTRACT_CHORD_CONSTRAINT_H
