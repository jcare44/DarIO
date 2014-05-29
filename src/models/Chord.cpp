#include "Chord.h"
#include <cstdlib>
#include <time.h>
#include "../abstracts/AbstractChordConstraint.h"
#include <iostream>
#include <random>

Chord::Chord()
{
	std::random_device rdev;

	int max = rdev()%(NOTE_MAX-NOTE_MIN)+NOTE_MIN;

	for(numberOfNotes=0;numberOfNotes<max;++numberOfNotes)
	{
		notes[numberOfNotes] = new Note();
	}
}

Chord::Chord(Chord* _c)
{
	mark = _c->getMark();
	
	for(numberOfNotes=0;numberOfNotes<_c->getNumberOfNotes();++numberOfNotes)
	{
		notes[numberOfNotes] = new Note(_c->getNote(numberOfNotes));
	}
}

void Chord::grade()
{
	mark = 0;
	for(int i = 0;i < constraints.size();++i)
	{
		mark += constraints[i]->eval(this);
	}
}

void Chord::setNumberOfNotes(int _numberOfNotes)
{
	numberOfNotes = _numberOfNotes;
}

int Chord::getNumberOfNotes()
{
	return numberOfNotes;
}

Note* Chord::getNote(int _i)
{
	return notes[_i];
}

int Chord::getMark()
{
	return mark;
}

void Chord::setMark(int _mark)
{
	mark = _mark;
}

void Chord::setNote(int _i, Note* _note)
{
    if(_i < numberOfNotes)
	{
		notes[_i] = _note;
	}
}

void Chord::mutate()
{
    for(int i =0; i<numberOfNotes; ++i)
    {
        std::random_device rd;
        if (rd()%100 < MUTATE_RATE)
        {
            getNote(i)->mutate();
        }
    }
}
