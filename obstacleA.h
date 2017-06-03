#ifndef OBSTACLEA_H
#define OBSTACLEA_H

//#include <vector>
//#include <ncurses.h>
#include "obstacle.h"


class CObstacleA : public CObstacle {
	public:
		CObstacleA(const int & y, const int & x, const char & cChar, const int & sp);
		virtual bool moveO(CTimer & cntTime);
	private:
		int c_obstSpeed;
};






#endif