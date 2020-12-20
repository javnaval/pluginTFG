#include "Plugin.h"

Plugin::Plugin() {
	cout <<"Plugin test"<<endl;
}
void Plugin::setTimer() {
	cout <<"Timer test"<<endl;
}

void Plugin::processMIDIMessage(juce::MidiMessage m) {
	int n = m.getNoteNumber();
	cout << m.getMidiNoteName(n, true, true, 3);
	// PROBANDO COMMIT
}
