#include "TierceChordConstraint.h"

TierceChordConstraint::TierceChordConstraint()
{
	
}

bool TierceChordConstraint::eval(Chord* _chord)
{
	if(_chord->getNumberOfNotes() == 2){

		int midi[2];
		midi[0] = _chord->getNote(0)->getMidi();
		midi[1] = _chord->getNote(1)->getMidi();
		
		if((midi[1] - midi[0]) == 4)
		{
				return true;
		}
	}
	
	return false;
}
