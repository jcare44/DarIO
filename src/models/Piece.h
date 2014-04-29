#ifndef PIECE_H
#define PIECE_H

#include "Chord.h"

#define BAR_MIN 99
#define BAR_MAX 100
#define TEMPO_MIN 119
#define TEMPO_MAX 120
#define CHORD 20

class Piece
{
	private:
		int bar;
		float tempo;
		int numberOfChords;
		Chord* chords[CHORD];
	
	public:
		Piece();
};

#endif //PIECE_H
