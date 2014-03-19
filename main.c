#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MIDI_PAUSE 0 //La valeur midi de la pause
#define MIDI_MIN 36
#define MIDI_MAX 95
#define TIME {0.25,0.5,1,2,4} //De la double croche à la ronde
#define BAR_MIN 100
#define BAR_MAX 100
#define TEMPO_MIN 120
#define TEMPO_MAX 120

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
	Note notes[];
};

struct Piece
{
	int bar;
	float tempo;
	int numberOfChords;
	Chord chords[];
};

int main(int argc, char *argv[])
{
	
	
	return 0;
}
