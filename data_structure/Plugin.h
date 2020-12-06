#include <iostream>
#include "list"
#include "ChannelPlugin.h"

using namespace std;

class Plugin {
	private:
	//Rango que el teclado considera para introducir acordes
	int range;

    list<int> activeChannels;
    double startTime;
    double sampleRate = 44100.0;
    //
	public:
	Plugin();
	void AddInstrument(int instrument, int channel);
    void removeInstrument(int instrument);
	void setTimer();
	list<ChannelPlugin> getChannels();
	void setRange(int range);
};
