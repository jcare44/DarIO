#include "../src/abstracts/AbstractChordConstraint.h"
#include "../src/abstracts/AbstractPieceConstraint.h"
#include <vector>

#include "../src/constraints/TierceChordConstraint.h"

using namespace std;

vector<AbstractChordConstraint*> chordConstraints = new vector<AbstractChordConstraint*>({
	new TierceChordConstraint()
});