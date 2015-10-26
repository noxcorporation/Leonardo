#include "Time.h"


Duration::Duration(auto in) {
	value = in;
}

void Duration::operator =(auto in) {
	value = in;
}

bool Duration::operator ==(auto in) {
	return value.count() == in;
}

bool Duration::operator !=(auto in) {
	return value.count() != in;
}

bool Duration::operator >(auto in) {
	return value.count() > in;
}

bool Duration::operator <(auto in) {
	return value.count() < in;
}

bool Duration::operator >=(auto in) {
	return value.count() >= in;
}

bool Duration::operator <=(auto in) {
	return value.count() <= in;
}

float operator /(int A, Duration B) {
	return A / B.value.count();
}





TimePoint::TimePoint() {
	value = steady_clock::now();
}

Duration operator -(TimePoint A, TimePoint B) {
	return duration_cast<milliseconds>(A.value - B.value);
}





Clock::Clock(float actionsPerSecond) {
	updatesPerSecond = actionsPerSecond;
}

bool Clock::update() {
	TimePoint now;
	Duration currentDelay = now - lastUpdate;
	
	if (currentDelay >= (1000 / updatesPerSecond)) {
		lastUpdate = now;
		updateDelay = currentDelay;
		return true;
	} else
		return false;
}

int Clock::getActionsPerSecond() {
	return 1000 / updateDelay;
}
