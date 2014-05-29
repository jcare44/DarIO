#include <cmath>
#include <iostream>
#include <cstdlib>
#include <pthread.h>

#include "constraints/QuinteChordConstraint.h"
#include "models/Maestro.h"
#include "OscTransmitter.h"

using namespace std;

int main(int argc, char *argv[])
{
	QuinteChordConstraint* QuinteCon = (QuinteChordConstraint*)Chord::getConstraint<QuinteChordConstraint>();
	QuinteCon->setMode(QuinteChordConstraint::MODE::MAJOR);
	Maestro* m = new Maestro(256);

	OscTransmitter* transmitter = new OscTransmitter();
	transmitter->setPiece(m->process());
	
	pthread_create(transmitter->getThread(), NULL,OscTransmitter::threadCreate,(void*)transmitter);
	
	pthread_join(*transmitter->getThread(),NULL);
		
	return 0;
}
