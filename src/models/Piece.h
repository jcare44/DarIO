#ifndef PIECE_H
#define PIECE_H

#include "Chord.h"

#define BAR_MIN 99
#define BAR_MAX 100
#define TEMPO_MIN 119
#define TEMPO_MAX 120
#define CHORD 20

class AbstractPieceConstraint;

class Piece
{
	private:
		int bar;
		float tempo;
		int numberOfChords;
		Chord* chords[CHORD];
		int mark;
		static vector<AbstractPieceConstraint*> constraints;
	
	public:
		Piece();
		void grade();
		int getBar();
		void setBar(int _bar);
		float getTempo();
		void setTempo(float _tempo);
		int getNumberOfChords();
		void setNumberOfChords(int _numberOfChords);
		Chord* getChord(int _i);
		int getMark();
		void setMark(int _mark);
		template <class E>
		static AbstractPieceConstraint* getConstraint();
};

#endif //PIECE_H
