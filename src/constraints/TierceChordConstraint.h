#ifndef TIERCE_CHORD_CONSTRAINT_H
#define TIERCE_CHORD_CONSTRAINT_H

#include "../abstracts/AbstractChordConstraint.h"
#include "../models/Chord.h"

class TierceChordConstraint : public AbstractChordConstraint
{
	public:
		TierceChordConstraint();
		bool eval(Chord* _chord);
};

#endif //TIERCE_CHORD_CONSTRAINT_H
