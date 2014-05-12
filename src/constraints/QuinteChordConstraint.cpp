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
		int interval13, interval12, interval23;
		
		for(i=0;i<nbNotes;i++){
			midi[i] = _chord->getNote(i)->getMidi();
		}		
		
		interval13 = midi[2] - midi[0];//beetween the firth and the last note
		interval12 = midi[1] - midi[0];//beetween the firth and the second note
		interval23 = midi[2] - midi[1];//beetween the second and the last note
		
		switch(mode)
		{
			case ANY : 
							if(	interval13 == 7 && (interval12 == 4 || interval12 == 3))
							{
								valid = true;
							}
			break;
			case MAJOR :
							if(interval13 == 7 && interval12 == 4)
							{
								valid = true;
							}
			break;
			case MINOR :
							if(interval13 == 7 && interval12 == 3)
							{
								valid = true;
							}
			break;
		}
		
		
		
	}
	
	return valid;
}

void QuinteChordConstraint::setMode(MODE _mode)
{
	mode = _mode;
}

QuinteChordConstraint::MODE QuinteChordConstraint::getMode()
{
	return mode;
}
