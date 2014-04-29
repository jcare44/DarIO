#ifndef QUINTE_CHORD_CONSTRAINT_H
#define QUINTE_CHORD_CONSTRAINT_H

#include "../abstracts/AbstractChordConstraint.h"
#include "../models/Chord.h"

class QuinteChordConstraint : public AbstractChordConstraint
{
	public:
		QuinteChordConstraint();
		bool eval(Chord* _chord);
};

#endif //TIERCE_CHORD_CONSTRAINT_H
