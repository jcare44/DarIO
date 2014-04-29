
#include "QuinteChordConstraint.h"

QuinteChordConstraint::QuinteChordConstraint()
{
	
}

bool QuinteChordConstraint::eval(Chord* _chord)
{
	bool valid = false;
	int nbNotes = 3;
	if(_chord->getNumberOfNotes() == nbNotes){
		int midi[nbNotes];
		int i;
		
		valid = true;
		
		for(i=0;i<nbNotes;i++){
			midi[i] = _chord->getNote(i)->getMidi();
		}		
		
		for(i=0;i<nbNotes-1;i++){
			if((midi[i+1] - midi[i]) != 4)
			{
				valid = false;
			}
		}
	}
	
	return valid;
}
