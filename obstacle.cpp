#include "obstacle.h"


CObstacle::CObstacle(const int & y, const int & x, const char & cChar):CObject(y,x,cChar)
{}

bool CObstacle::moveO(CTimer & cntTime)
{
	return true;
}


bool CObstacle::isCollision()
{
	if(c_posY == 44)
	{
		clearO();
		return true;	
	}
	return false;
}


bool CObstacle::collide(const int & y, const int & x)
{
	if (c_posY == y && c_posX == x)
	{
		clearO();
		return true;
	}

	for (int i = 0; i < c_offsLen; i++)
	{
		if ( (c_posY + offset[i].offsY) == y && (c_posX + offset[i].offsX ) == x)
			{
				clearO();
				return true;
			}
	}

	return false;
}