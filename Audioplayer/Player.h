#pragma once
#include "Track.h"
#include <string>
#include <iostream>
#include <vector>
#include <time.h>
#include <random>
#include <iomanip>

enum status {
	play,
	pause,
	stop,
};


class Player
{
	vector <Track> tracks;
	Track* current;
	status stat = status::stop;
	time_t t;
	int duration;
public:
	Player();
	void stop();
	void play();
	void play(Track *track);
	void next();
	void pause();
	void engine();

};

