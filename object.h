#ifndef OBJECT_H
#define OBJECT_H

//#include "bullet.h"

#include <vector>
#include <ncurses.h>
#include "timer.h"
#include <vector>

using namespace std;

struct YXPART{
	YXPART(const int & y, const int & x, const char & c);
	int offsY;
	int offsX;
	char offsChar;
};

class CObject {
	public:
		CObject();
		CObject(const int & y, const int & x, const char & coreC);
		virtual ~CObject(){};
		void buildOffset(const int & y,const int & x,const char & oChar);
		void printO()const;
		void clearO()const;
		vector<YXPART> giveCollisionPoints();
		YXPART giveCorePoint();

		virtual bool isCollision()=0;
		virtual bool moveO();
		virtual bool moveO(CTimer & cntTime);
		
	protected:
		int c_posY;
		int c_posX;
		int c_coreChar;
		vector<YXPART> offset;
		int c_offsLen;
};






#endif