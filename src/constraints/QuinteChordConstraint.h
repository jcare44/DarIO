#ifndef QUINTE_CHORD_CONSTRAINT_H
#define QUINTE_CHORD_CONSTRAINT_H

#include "../abstracts/AbstractChordConstraint.h"
#include "../models/Chord.h"

class QuinteChordConstraint : public AbstractChordConstraint
{
	enum MODE{ANY,MAJOR,MINOR};
	private:
		MODE mode;
	public:
		QuinteChordConstraint();
		int eval(Chord* _chord);
		void setMode(MODE _mode);
		MODE getMode();
};

#endif //QUINTE_CHORD_CONSTRAINT_H
