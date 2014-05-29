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

Chord* Chord::mutate(Chord* _chord)
{
    for(int i =0; i<numberOfNotes; ++i)
    {
        std::random_device rd;
        if (rd()%100 < MUTATE_RATE)
        {
            _chord->setNote(i, _chord->getNote(i)->mutate(_chord->getNote(i)));
        }
    }
    return _chord;
}

template <class E>
AbstractChordConstraint* Chord::getConstraint()
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
