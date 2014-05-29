#include <cmath>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <sstream>
#include "osc/OscOutboundPacketStream.h"
#include "ip/UdpSocket.h"

#include "models/Maestro.h"

#define ADDRESS "127.0.0.1"
#define PORT 8000

#define OUTPUT_BUFFER_SIZE 1024

using namespace std;

int main(int argc, char *argv[])
{
	Maestro* m = new Maestro(32);
	m->process();

	char address[] = "192.168.1.22";
	int port = 8000;
	string input;
	cout << "Address IP ? [hit enter for default : 192.168.1.22]" << endl;
	getline(cin, input);
	if(input.length()>0){
		 stringstream(input)>>address;
	}
	cout << "address = " << address << endl;
	cout << "Port ? [hit enter for default : 8000]" << endl;
	getline(cin,input);
	if(input.length()>0){
		 stringstream(input)>>port;
	}
	cout << "port = " << port << endl;
	
	UdpTransmitSocket transmitSocket( IpEndpointName( address, port ) );
	char buffer[OUTPUT_BUFFER_SIZE];
    osc::OutboundPacketStream pack( buffer, OUTPUT_BUFFER_SIZE ); 
	
	srand(time(NULL));
	Piece* p = new Piece();
	cout <<"Numbre of Chords : "<< p->getNumberOfChords() << endl;
	Chord* c = p->getChord(1);
	int nbNotes = c->getNumberOfNotes();
	cout <<"Numbre of notes of Chord 1 : "<< nbNotes << endl;
	int i;
	
	pack << osc::BeginBundleImmediate
	<< osc::BeginMessage( "/pitch" );
		for(i = 0;i<nbNotes;i++){
			cout <<"note "<<i<<"---------------"<<endl;
			cout <<"midi : "<<c->getNote(i)->getMidi() << endl;
			cout <<"time : "<<c->getNote(i)->getDuration() << endl;
			pack << c->getNote(i)->getMidi();	
		}
	pack << osc::EndMessage;
	pack << osc::BeginMessage("/duration");
		for(i = 0;i<nbNotes;i++){
			pack << c->getNote(i)->getDuration()*1000;	
		}
	pack << osc::EndMessage;
	pack << osc::EndBundle;
	

     //      << 65 << 23 << osc::EndMessage
     // << osc::BeginMessage( "/test2" ) 
     //    << 5 << 24 << (float)10.8 << "world" << osc::EndMessage
     //<< osc::EndBundle;
    
    transmitSocket.Send( pack.Data(), pack.Size() );
		
	return 0;
}
