#include "../Leonardo.h"


// This class is a custom type.
// Defines a custom duration type similar to std::chrono::milliseconds.
class Duration {
	public:
		milliseconds value;
		
		Duration() {};
		
		// Assignment operator overload.
		Duration(auto);
		void operator=(auto);
		
		// Comparison operator overload.
		bool operator==(auto);
		bool operator!=(auto);
		bool operator>(auto);
		bool operator<(auto);
		bool operator>=(auto);
		bool operator<=(auto);
};

float operator /(int, Duration);



// This class is a custom type.
// Defines a custom time point similar to std::chrono::time_point.
class TimePoint {
	public:
		time_point<steady_clock> value;
		
		TimePoint();
};

Duration operator-(TimePoint, TimePoint);



class Clock {
	private:
		int updatesPerSecond;
		TimePoint lastUpdate;
		Duration updateDelay;
	public:
		Clock(int);
		bool update();
		int getActionsPerSecond();
};
