#include <iostream>
#include "FlowPieceConstraint.h"

FlowPieceConstraint::FlowPieceConstraint()
{
	setCoeff(1);
}

float FlowPieceConstraint::eval(Piece* _piece)
{
	float rate;
	int counter,diffMidi;
	Chord *c1,*c2;
	counter = 0;
	for(int i = 1; i < _piece->getNumberOfChords(); ++i)
	{
		//calcule de la difference de midi entre l'accord n et n+1
		c1 = _piece->getChord(i);
		c2 = _piece->getChord(i-1);
		diffMidi = std::abs(c1->getNote(0) - c2->getNote(0));
		//cout <<"diff midi : " << diffMidi << endl;
		if(diffMidi < 12)
		{
			++counter;
		}
	}
	rate = ((float)counter / _piece->getNumberOfChords())*10;
	//cout << "rate " << rate << endl;
}
