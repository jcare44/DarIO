#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MIDI_PAUSE 0 //La valeur midi de la pause
#define MIDI_PAUSE_RATIO 0.01
#define MIDI_MIN 36
#define MIDI_MAX 95
#define TIME {0.25,0.5,1,2,4} //De la double croche à la ronde
#define TIME_LENGTH 5
#define BAR_MIN 99
#define BAR_MAX 100
#define TEMPO_MIN 119
#define TEMPO_MAX 120
#define NOTE_MIN 1
#define NOTE_MAX 5
#define CHORD 20

typedef struct Note Note;
typedef struct Chord Chord;
typedef struct Piece Piece;

struct Note
{
	int midi;
	float time;
};

struct Chord
{
	int numberOfNotes;
	Note notes[NOTE_MAX];
};

struct Piece
{
	int bar;
	float tempo;
	int numberOfChords;
	Chord chords[CHORD];
};

Note generateNote()
{
	Note n;
	if((rand()%100)/100 < MIDI_PAUSE_RATIO)
	{
		n.midi = MIDI_PAUSE;
	}
	else
	{
		n.midi = rand()%(MIDI_MAX-MIDI_MIN)+MIDI_MIN;
	}
	
	float time[TIME_LENGTH] = TIME;
	n.time = time[rand()%TIME_LENGTH];
	
	return n;
}

Chord generateChord()
{
	Chord c;
	int max = rand()%(NOTE_MAX-NOTE_MIN)+NOTE_MIN;
	
	for(c.numberOfNotes=0;c.numberOfNotes<max;++c.numberOfNotes)
	{
		c.notes[c.numberOfNotes] = generateNote();
	}
	
	return c;
}

/**
 * @todo check last chord is in bar
 */
Piece generatePiece()
{
	Piece p;
	p.bar = rand()%(BAR_MAX-BAR_MIN)+BAR_MIN;
	p.tempo = rand()%(TEMPO_MAX-TEMPO_MIN)+TEMPO_MIN;
	
	for(p.numberOfChords=0;p.numberOfChords<CHORD;++p.numberOfChords)
	{
		p.chords[p.numberOfChords] = generateChord();
	}
	
	return p;
}

int main(int argc, char *argv[])
{
	srand(1);
	generatePiece();
	
	return 0;
}
