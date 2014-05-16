#include "../src/abstracts/AbstractPieceConstraint.h"
#include "../src/models/Piece.h"
#include <vector>

#include "../src/constraints/TierceChordConstraint.h"

AbstractPieceConstraint* tt[] {

};
vector<AbstractPieceConstraint*> Piece::constraints (tt,tt+sizeof(tt)/sizeof(AbstractPieceConstraint*));
