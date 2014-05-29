#include "../src/abstracts/AbstractPieceConstraint.h"
#include "../src/models/Piece.h"
#include <vector>

#include "../src/constraints/FlowPieceConstraint.h"

AbstractPieceConstraint* tt[] {
	new FlowPieceConstraint()
};
vector<AbstractPieceConstraint*> Piece::constraints (tt,tt+sizeof(tt)/sizeof(AbstractPieceConstraint*));
