#ifndef SHIP_H
#define SHIP_H

#include "bullet.h"

using namespace std;

class CShip : public CObject {
	public:
		CShip();
		CBullet newBullet();
		CBullet newBullet(const int & offsetY, const int & offsetX);
		void moveLeft();
		void moveRight();
		void moveUp();
		void moveDown();
		void printShield(const char & pChar);
		virtual bool isCollision();
};






#endif