#include "Track.h"

Track::Track(tm* t, int dur, string name) {
	createDate = t;
	this->name = name;
	duration = dur;
}