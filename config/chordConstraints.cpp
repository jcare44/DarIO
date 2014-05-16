#include "../src/abstracts/AbstractChordConstraint.h"
#include "../src/abstracts/AbstractPieceConstraint.h"
#include "../src/models/Chord.h"
#include <vector>

#include "../src/constraints/TierceChordConstraint.h"

using namespace std;

AbstractChordConstraint* t[] {
	new TierceChordConstraint()
};
vector<AbstractChordConstraint*> Chord::constraints (t,t+sizeof(t)/sizeof(AbstractChordConstraint*));
