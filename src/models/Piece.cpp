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
		for(i=0; i < chords[j]->getNumberOfNotes(); i++)
		{
		   avgMidiJ = chords[j]->getNote(i)->getMidi();
		}

		avgMidiJ = avgMidiJ / chords[j]->getNumberOfNotes();

		int avgMidiJMinus = 0;
		for(i=0; i < chords[j-1]->getNumberOfNotes(); i++)
		{
		   avgMidiJMinus = chords[j-1]->getNote(i)->getMidi();
		}

		avgMidiJMinus = avgMidiJMinus / chords[j-1]->getNumberOfNotes();

		int avgMidiJPlus = 0;
		for(i=0; i < chords[j+1]->getNumberOfNotes(); i++)
		{
		   avgMidiJPlus = chords[j+1]->getNote(i)->getMidi();
		}

		avgMidiJPlus = avgMidiJPlus / chords[j+1]->getNumberOfNotes();

		chords[j]->setMark(chords[j]->getMark() + avgMidiJ / avgMidiJMinus * 50);
		chords[j]->setMark(chords[j]->getMark() + avgMidiJ / avgMidiJPlus * 50);

		// X constraints

		// Chord evaluation
		chords[j]->setMark(chords[j]->getMark() / NUMBER_OF_CONSTRAINTS);
		mark += chords[j]->getMark();

		j++;

	}

	if(j = numberOfChords)
	{
		// And everything here again because I don't know how to handle this case
	}

	// Evaluation of the Piece thanks to the SUM of the chords
	mark = mark / numberOfChords;
}*/

int Piece::getBar()
{
	return bar;
}

void Piece::setBar(int _bar)
{
	bar = _bar;
}

float Piece::getTempo()
{
	return tempo;
}

void Piece::setTempo(float _tempo)
{
	tempo = _tempo;
}

int Piece::getNumberOfChords()
{
	return numberOfChords;
}

void Piece::setNumberOfChords(int _numberOfChords)
{
	numberOfChords = _numberOfChords;
}

Chord* Piece::getChord(int _i)
{
	return chords[_i];
}

int Piece::getMark()
{
	return mark;
}

void Piece::setMark(int _mark)
{
	mark = _mark;
}

template <class E>
AbstractPieceConstraint* Piece::getConstraint()
{
	for(int i = 0;i < constraints.size();++i)
	{
		if(dynamic_cast<E*>(constraints[i])!=NULL)
		{
			return constraints[i];
		} 
	}
	
	return NULL;
}