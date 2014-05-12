#include "IntervalChordConstraint.h"

IntervalChordConstraint::IntervalChordConstraint(int _nbNotes)
{
	// 2 notes : Third chord
	// 3 notes : Fifth chord
	// 4 notes : Seventh chord
	if( _nbNotes >= 2 && _nbNotes <= 4)
	{
		nbNotes = _nbNotes;
	}else
	{
		//default values, a third chord
		nbNotes = 2;
	}
}

bool IntervalChordConstraint::eval(Chord* _chord)
{
	bool valid = false;
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

