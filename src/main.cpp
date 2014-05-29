#include <cmath>
#include <iostream>
#include <cstdlib>
#include <time.h>

#include "models/Maestro.h"

int main(int argc, char *argv[])
{
	Maestro* m = new Maestro(32);
	m->process();
	
	return 0;
}
