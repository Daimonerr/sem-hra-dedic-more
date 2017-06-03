#ifndef SHIP_H
#define SHIP_H

#include "bullet.h"

using namespace std;

class CShip : public CObject {
	public:
		CShip();
		CBullet newBullet();
		void moveLeft();
		void moveRight();
		void moveUp();
		void moveDown();
		virtual bool isCollision();
//	private:
//		vector<YXPART> ship;
//		vector<CBullet> ammo;
//		void buildPart(const int & y,const int & x,const char & part);

//		int cntBullets;
//		int shipLength;
};






#endif