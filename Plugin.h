#include <iostream>
#include <JuceHeader.h>
#include "list"
//#include "ChannelPlugin.h"

using namespace std;

class Plugin	:	public juce::Component,
					private juce::MidiKeyboardStateListener {
	private:
	//Rango que el teclado considera para introducir acordes
	int range;

    list<int> activeChannels;
    double startTime;
    bool isAddingFromMidiInput = false;
    double sampleRate = 44100.0;

	juce::MidiKeyboardState keyboardState;
    juce::MidiKeyboardComponent keyboardComponent;
    //

	void handleNoteOn (juce::MidiKeyboardState*, int midiChannel, int midiNoteNumber, float velocity) override
    {
        if (! isAddingFromMidiInput)
        {
            auto m = juce::MidiMessage::noteOn (midiChannel, midiNoteNumber, velocity);
            m.setTimeStamp (juce::Time::getMillisecondCounterHiRes() * 0.001);
            // TRATAR EL MENSAJE m
        }
    }

    void handleNoteOff (juce::MidiKeyboardState*, int midiChannel, int midiNoteNumber, float /*velocity*/) override
    {
        if (! isAddingFromMidiInput)
        {
            auto m = juce::MidiMessage::noteOff (midiChannel, midiNoteNumber);
            m.setTimeStamp (juce::Time::getMillisecondCounterHiRes() * 0.001);
            // TRATAR EL MENSAJE m
        }
    }

	public:
	Plugin()
		: keyboardComponent (keyboardState, juce::MidiKeyboardComponent::horizontalKeyboard),
    	  startTime (juce::Time::getMillisecondCounterHiRes() * 0.001)
	{

	
		addAndMakeVisible (keyboardComponent);
    	keyboardState.addListener (this);

		setSize (600, 400);
	}
	
	~Plugin()
	{
		keyboardState.removeListener (this);
	}

	void addInstrument(int instrument, int channel);
    void removeInstrument(int instrument);
	void setTimer();
	//list<ChannelPlugin> getChannels();
	void setRange(int range);

	void processMIDIMessage(juce::MidiMessage m);
};
