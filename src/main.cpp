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
	//change parameters the Quinte chord constraint
	QuinteChordConstraint* QuinteCon = (QuinteChordConstraint*)Chord::getConstraint<QuinteChordConstraint>();
	QuinteCon->setMode(QuinteChordConstraint::MODE::MAJOR);
	QuinteCon->setCoeff(5);
	
	Maestro* m = new Maestro(256);

	OscTransmitter* transmitter = new OscTransmitter();
	transmitter->setPiece(m->process());
	Piece* tmp;
	
	while(1)
	{
		pthread_create(transmitter->getThread(), NULL,OscTransmitter::threadCreate,(void*)transmitter);
		
		m = new Maestro(256);
		tmp = m->process();
		
		pthread_join(*transmitter->getThread(),NULL);
		
		transmitter->setPiece(tmp);
	}
		
	return 0;
}
