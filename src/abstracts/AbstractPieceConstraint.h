#ifndef ABSTRACT_PIECE_CONSTRAINT_H
#define ABSTRACT_PIECE_CONSTRAINT_H

#include "../models/Piece.h"

class AbstractPieceConstraint
{
	private:
		int coeff;
	
	public:
		int getCoeff();
		void setCoeff(int _coeff);
		virtual float eval(Piece* _chord) = 0;
};

#endif //ABSTRACT_PIECE_CONSTRAINT_H
