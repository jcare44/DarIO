#ifndef ABSTRACT_PIECE_CONSTRAINT_H
#define ABSTRACT_PIECE_CONSTRAINT_H

#include "../models/Piece.h"

class AbstractPieceConstraint
{
	public:
		virtual bool eval(Piece* _chord) = 0;
};

#endif //ABSTRACT_PIECE_CONSTRAINT_H
