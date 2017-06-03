#ifndef OBSTACLEB_H
#define OBSTACLEB_H

#include "obstacleA.h"


class CObstacleB : public CObstacle {
	public:
		CObstacleB(const int & y, const int & x, const char & cChar, const int & sp);
		virtual bool moveO(CTimer & cntTime);
	private:
		int c_obstSpeed;
		int c_direction;
		int c_flip;
};






#endif