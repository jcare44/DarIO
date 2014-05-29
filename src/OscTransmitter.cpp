#include "OscTransmitter.h"
#include <iostream>
#include <pthread.h>
#include <string>
#include <map>
#include <sstream>
#include "osc/OscOutboundPacketStream.h"
#include "ip/UdpSocket.h"
#include <unistd.h>

OscTransmitter::OscTransmitter()
{
	port = 8000;
	string input;
	cout << "Address IP ? [hit enter for default : 192.168.1.22]" << endl;
	getline(cin, input);
	if(input.length() == 0){
		input = "192.168.1.22";
	}
	stringstream(input)>>ipAddress;
	
	cout << "ip address = " << ipAddress << endl;
	cout << "Port ? [hit enter for default : 8000]" << endl;
	getline(cin,input);
	if(input.length()>0){
		 stringstream(input)>>port;
	}
	cout << "port = " << port << endl;
}

void OscTransmitter::thread()
{
	UdpTransmitSocket transmitSocket(IpEndpointName(ipAddress, port));
	char buffer[OUTPUT_BUFFER_SIZE];
	osc::OutboundPacketStream pack(buffer, OUTPUT_BUFFER_SIZE);
    
	
	cout <<"Numbre of Chords : "<< piece->getNumberOfChords() << endl;
	
	Chord* c;
	map<float,int> durations;
	int tmp;
	
	for(int j=0;j<piece->getNumberOfChords();++j)
	{
		tmp = 0;
		durations.clear();
		
		c = piece->getChord(j);
		
		int nbNotes = c->getNumberOfNotes();
		cout <<"Numbre of notes of Chord " << j << " : "<< nbNotes << endl;
		int i;
		
		pack.Clear();
		
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
			pack << c->getNote(i)->getDuration()*piece->getBaseDuration();
			
			if(!durations[c->getNote(i)->getDuration()])
			{
				durations[c->getNote(i)->getDuration()] = 1;
			}
			else
			{
				++durations[c->getNote(i)->getDuration()];
			}
		}
		pack << osc::EndMessage;
		pack << osc::EndBundle;
		
		cout << "transmit" << endl;
		transmitSocket.Send( pack.Data(), pack.Size() );
		
		for(map<float,int>::iterator it=durations.begin(); it!=durations.end(); ++it)
		{
            tmp = it->second;
            if(tmp >= c->getNumberOfNotes()*1/2)
            {
				usleep(it->first*piece->getBaseDuration()*1000);
				break;
			}
		}
	}

	pthread_exit(NULL);
}

void OscTransmitter::setPiece(Piece* _piece)
{
	piece = _piece;
}

Piece* OscTransmitter::getPiece()
{
	return piece;
}

pthread_t* OscTransmitter::getThread()
{
	return &threadId;
}

void* OscTransmitter::threadCreate(void* self)
{
	((OscTransmitter*)self)->thread();
}
