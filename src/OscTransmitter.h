#ifndef OSC_TRANSMITER_H
#define OSC_TRANSMITER_H

#include "models/Piece.h"

#define OUTPUT_BUFFER_SIZE 1024

class OscTransmitter
{
	private:
		char ipAddress[16];
		int port;
		Piece* piece;
		pthread_t threadId;
	public:	
		OscTransmitter();
		void setPiece(Piece* _piece);
		Piece* getPiece();
		void thread();
		pthread_t* getThread();
		static void* threadCreate(void* arg);
};

#endif //OSC_TRANSMITER_H
