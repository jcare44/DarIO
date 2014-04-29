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

/*void Piece::grading()
{
	// A chord J will be evaluated thanks to a comparison with J-1 and J+1
	int j = 1;
	int i = 0;
	while (j < numberOfChords)
	{
		// Harmony constraints block, each will have two evaluations (j-1 and j+1), get the SUM of both evaluations and
		// divide it by the total of constraints

		// First constraint
				// Midi average of each Chord for the first constraint
		int avgMidiJ = 0;
		for(i=0; i < chords[j]->numberOfNotes; i++)
		{
		   avgMidiJ = chords[j]->notes[i]->midi;
		}

		avgMidiJ = avgMidiJ / chords[j]->numberOfNotes;

		int avgMidiJMinus = 0;
		for(i=0; i < chords[j-1]->numberOfNotes; i++)
		{
		   avgMidiJMinus = chords[j-1]->notes[i]->midi;
		}

		avgMidiJMinus = avgMidiJMinus / chords[j-1]->numberOfNotes;

		int avgMidiJPlus = 0;
		for(i=0; i < chords[j+1]->numberOfNotes; i++)
		{
		   avgMidiJPlus = chords[j+1]->notes[i]->midi;
		}

		avgMidiJPlus = avgMidiJPlus / chords[j+1]->numberOfNotes;

		chords[j]->mark += avgMidiJ / avgMidiJMinus * 50 ;
		chords[j]->mark += avgMidiJ / avgMidiJPlus * 50 ;

		// X constraints

		// Chord evaluation
		chords[j].mark = chords[j]->mark / NUMBER_OF_CONSTRAINTS ;
		mark += chords[j]->mark;

		j++;

		}

		if(j = numberOfChords)
		{
			// And everything here again because I don't know how to handle this case
		}

	// Evaluation of the Piece thanks to the SUM of the chords
	mark = mark / numberOfChords;
}*/
