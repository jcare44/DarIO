#include "Piece.h"
#include <cstdlib>

Piece::Piece()
{
	bar = rand()%(BAR_MAX-BAR_MIN)+BAR_MIN;
	tempo = rand()%(TEMPO_MAX-TEMPO_MIN)+TEMPO_MIN;
	
	for(numberOfChords=0;numberOfChords<CHORD;++numberOfChords)
	{
		chords[numberOfChords] = new Chord();
	}
}
