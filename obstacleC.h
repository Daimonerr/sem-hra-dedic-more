#ifndef OBSTACLEC_H
#define OBSTACLEC_H

#include "obstacleB.h"


class CObstacleC : public CObstacle {
	public:
		CObstacleC(const int & y, const int & x, const char & cChar, const int & sp);
		virtual bool moveO(CTimer & cntTime);
	private:
		int c_obstSpeed;
		int c_direction;
		int c_way;
};



#endif