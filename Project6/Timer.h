#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>
#include <fstream>
#include <chrono>

class Timer {
public:
	Timer();
	void StartTimer();
	double EndTimer();
	double GetElapsedTime();
private:
	std::chrono::high_resolution_clock::time_point startTime;
	double elapsedTime;
	
};

#endif // TIMER_H
