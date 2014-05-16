#include "Piece.h"
#include "../abstracts/AbstractPieceConstraint.h"
#include <cstdlib>
#include <cmath>

Piece::Piece()
{
	bar = rand()%(BAR_MAX-BAR_MIN)+BAR_MIN;
	tempo = rand()%(TEMPO_MAX-TEMPO_MIN)+TEMPO_MIN;
	
	for(numberOfChords=0;numberOfChords<CHORD;++numberOfChords)
	{
		chords[numberOfChords] = new Chord();
	}
}

void Piece::grade()
{
	int i;
	mark = 0;
	for(i = 0;i<numberOfChords;++i)
	{
		mark += chords[i]->getMark();
	}
	mark = floor(mark/numberOfChords);
	
	for(i = 0;i < constraints.size();++i)
	{
		mark += constraints[i]->eval(this);
	}
}

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
