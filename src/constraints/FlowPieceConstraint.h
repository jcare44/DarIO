#ifndef FLOW_PIECE_CONSTRAINT_H
#define FLOW_PIECE_CONSTRAINT_H

#include "../abstracts/AbstractPieceConstraint.h"
#include "../models/Piece.h"


class FlowPieceConstraint : public AbstractPieceConstraint
{
		public:
			FlowPieceConstraint();
			float eval(Piece* _piece);
};
#endif //FLOW_PIECE_CONSTRAINT_H
