#ifndef PIECE_H
#define PIECE_H

#include <cstdlib>
#include "Chord.h"

#define BAR_MIN 99
#define BAR_MAX 100
#define TEMPO_MIN 119
#define TEMPO_MAX 120
#define CHORD 20
#define CROSSING_RATE 10 //%


class AbstractPieceConstraint;

class Piece
{
	private:
		int bar;
		float tempo;
		int numberOfChords;
		Chord* chords[CHORD];
		float mark;
		static vector<AbstractPieceConstraint*> constraints;

	public:
		Piece();
		Piece(Piece* _p);
		void grade();
		int getBar();
		void setBar(int _bar);
		float getTempo();
		void setTempo(float _tempo);
		int getNumberOfChords();
		void setNumberOfChords(int _numberOfChords);
		Chord* getChord(int _i);
		void setChord(int _i, Chord* _c);
		float getMark();
		void setMark(float _mark);
		Piece* mutate(Piece* _piece);
		template <class E>
		static AbstractPieceConstraint* getConstraint();
		void crossing(Piece* p);
};

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

#endif //PIECE_H
