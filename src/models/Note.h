#ifndef NOTE_H
#define NOTE_H

#define MIDI_PAUSE 0 //La valeur midi de la pause
#define MIDI_PAUSE_RATIO 0.01
#define MIDI_MIN 36
#define MIDI_MAX 95
#define TIME {0.25,0.5,1,2,4} //De la double croche à la ronde
#define TIME_LENGTH 5

class Note
{
	private:
		int midi;
		float time;
	
	public:
		Note();
		int getMidi();
		void setMidi(int _midi);
		float getTime();
		void setTime(float _time);
};

#endif //NOTE_H
