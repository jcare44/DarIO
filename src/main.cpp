#include <cmath>
#include <iostream>
#include <cstdlib>
#include <time.h>

#include "models/Piece.h"

int main(int argc, char *argv[])
{
	srand(time(NULL));
	Piece* p = new Piece();
	cout <<"Numbre of Chords : "<< p->getNumberOfChords() << endl;
	Chord* c = p->getChord(1);
	int nbNotes = c->getNumberOfNotes();
	cout <<"Numbre of notes of Chord 1 : "<< nbNotes << endl;
	int i;
	for(i = 0;i<nbNotes;i++){
		cout <<"note "<<i<<"---------------"<<endl;
		cout <<"midi : "<<c->getNote(i)->getMidi() << endl;
		cout <<"time : "<<c->getNote(i)->getDuration() << endl;
			
	}
	
		
		
	
	return 0;
}
