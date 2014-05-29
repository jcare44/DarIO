#ifndef NOTE_H
#define NOTE_H

#define MIDI_PAUSE 0 //La valeur midi de la pause
#define MIDI_PAUSE_RATIO 0.01
#define MIDI_MIN 36
#define MIDI_MAX 95
#define DURATION {0.25,0.5,1,2,4} //De la double croche à la ronde
#define DURATION_LENGTH 5
#define MUTATE_RATE 10 //%

class Note
{
	private:
		int midi;
		float duration;

	public:
		Note();
		Note(Note* _n);
		int getMidi();
		void setMidi(int _midi);
		float getDuration();
		void setDuration(float _duration);
		void mutate();
};

#endif //NOTE_H
