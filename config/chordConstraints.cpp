#include "../src/abstracts/AbstractChordConstraint.h"
#include "../src/models/Chord.h"
#include <vector>

#include "../src/constraints/TierceChordConstraint.h"
#include "../src/constraints/QuinteChordConstraint.h"

using namespace std;

AbstractChordConstraint* t[] {
	new TierceChordConstraint(),
	new QuinteChordConstraint()
};
vector<AbstractChordConstraint*> Chord::constraints (t,t+sizeof(t)/sizeof(AbstractChordConstraint*));
