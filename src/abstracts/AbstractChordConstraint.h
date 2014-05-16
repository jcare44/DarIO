#ifndef ABSTRACT_CHORD_CONSTRAINT_H
#define ABSTRACT_CHORD_CONSTRAINT_H

#include "../models/Chord.h"

class AbstractChordConstraint
{
	private:
		int coeff;
	
	public:
		int getCoeff();
		void setCoeff(int _coeff);
		virtual int eval(Chord* _chord) = 0;
};

#endif //ABSTRACT_CHORD_CONSTRAINT_H
