#ifndef TIMER_H
#define TIMER_H

#include <string>
using namespace std;



class CTimer {
	public:
		CTimer();
		void addTime();
		void resetTime();
		string printTime();
		int getMsec();
		int getPlaytime();

	private:
		int c_min;
		int c_sec;
		int c_msec;
		int c_playtime;
};






#endif