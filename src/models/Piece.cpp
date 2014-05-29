#include "Piece.h"
#include "../abstracts/AbstractPieceConstraint.h"
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <random>

Piece::Piece()
{
	std::random_device rdev;

	bar = rdev()%(BAR_MAX-BAR_MIN)+BAR_MIN;
	tempo = rdev()%(TEMPO_MAX-TEMPO_MIN)+TEMPO_MIN;

	for(numberOfChords=0;numberOfChords<CHORD;++numberOfChords)
	{
		chords[numberOfChords] = new Chord();
	}
}

Piece::Piece(Piece* _p)
{
	bar = _p->getBar();
	tempo = _p->getTempo();
	
	for(numberOfChords=0;numberOfChords<_p->getNumberOfChords();++numberOfChords)
	{
		chords[numberOfChords] = new Chord(_p->getChord(numberOfChords));
	}
}

void Piece::grade()
{
	int i;
	mark = 0;
	for(i = 0;i<numberOfChords;++i)
	{
		chords[i]->grade();
		mark += chords[i]->getMark();
	}
	mark = floor(mark/numberOfChords);

	for(i = 0;i < constraints.size();++i)
	{
		mark += constraints[i]->eval(this);
	}
}

void Piece::crossing(Piece* _p)
{
	std::random_device rd;
	int x = floor(CHORD/2);
	int i;
	Chord* tmp;

	if(rd()%100 < CROSSING_RATE)
	{
		x = rd()%CHORD+1;
	}

	for(i=0;i<x;++i)
	{
		tmp = chords[i];
		chords[i] = _p->getChord(i);
		_p->setChord(i,tmp);
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

void Piece::setChord(int _i, Chord* _c)
{
	if(_i < numberOfChords)
	{
		chords[_i] = _c;
	}
}

int Piece::getMark()
{
	return mark;
}

void Piece::setMark(int _mark)
{
	mark = _mark;
}

Piece* Piece::mutate(Piece* _piece)
{

    for(int i =0; i<numberOfChords; ++i)
    {
        std::random_device rd;
        if (rd()%100 < MUTATE_RATE)
        {
            _piece->setChord(i, _piece->getChord(i)->mutate(_piece->getChord(i)));
        }
    }

    return _piece;
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
