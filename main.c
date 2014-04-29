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
#define NUMBER_OF_CONSTRAINTS 2
#define NUMBER_OF_PIECES 100

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
    int mark;
};

struct Piece
{
	int bar;
	float tempo;
	int numberOfChords;
	Chord chords[];
	int mark;
};

void grading(Piece* _piece)
{
    // A chord J will be evaluated thanks to a comparison with J-1 and J+1
    int j = 1;
    int i = 0;
    while (j < _piece->numberOfChords)
    {

        // Harmony constraints block, each will have two evaluations (j-1 and j+1), get the SUM of both evaluations and
        // divide it by the total of constraints

        // First constraint
                // Midi average of each Chord for the first constraint
        int avgMidiJ = 0;
        for(i=0; i < _piece->chords[j]->numberOfNotes; i++)
        {
           avgMidiJ = _piece->chords[j]->notes[i]->midi;
        }

        avgMidiJ = avgMidiJ / _piece->chords[j]->numberOfNotes;

        int avgMidiJMinus = 0;
        for(i=0; i < _piece->chords[j-1]->numberOfNotes; i++)
        {
           avgMidiJMinus = _piece->chords[j-1]->notes[i]->midi;
        }

        avgMidiJMinus = avgMidiJMinus / _piece->chords[j-1]->numberOfNotes;

        int avgMidiJPlus = 0;
        for(i=0; i < _piece->chords[j+1]->numberOfNotes; i++)
        {
           avgMidiJPlus = _piece->chords[j+1]->notes[i]->midi;
        }

        avgMidiJPlus = avgMidiJPlus / _piece->chords[j+1]->numberOfNotes;

        _piece->chords[j]->mark += avgMidiJ / avgMidiJMinus * 50 ;
        _piece->chords[j]->mark += avgMidiJ / avgMidiJPlus * 50 ;

        // X constraints

        // Chord evaluation
        _piece->chords[j].mark = _piece->chords[j]->mark / NUMBER_OF_CONSTRAINTS ;
        _piece->mark += _piece->chords[j]->mark;

        j++;

        }

        if(j = _piece->numberOfChords)
        {
            // And everything here again because I don't know how to handle this case
        }


    // Evaluation of the Piece thanks to the SUM of the chords
    _piece->mark = _piece->mark / _piece->numberOfChords;


}

int main(int argc, char *argv[])
{

	return 0;
}
