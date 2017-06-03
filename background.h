
#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <cstdlib>
#include <unistd.h>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <stdio.h>
#include "ship.h"

using namespace std;

struct LOADLEVEL{
	LOADLEVEL(): y(0), x(0), time(0), sp(0)
	{}
	LOADLEVEL(const int & a, const int & tik, const int & speedo, const char & typeO)
	{
		y=3;
		x=a;
		time=tik;
		sp = speedo;
		type=typeO;
	}
	int y;
	int x;
	int time;
	int sp;
	char type;
};

class CBack {
	public:
		CBack();
		void drawMap()const;
		void startMenu(vector<LOADLEVEL> & fileVect, int & cntFileObjs);
		void printUtilities(const int & score, 
							const int & remainObst, 
							const int & health,
							CTimer & timer, 
							const bool & isReloading, 
							const int & mag, 
							const int & bonus);

		void gameEnding(const int & score);
		void pauseGame();

	private:
		bool getFile(vector<LOADLEVEL> & fileVect, int & cntFileObjs);
		void drawSquare(const int & height, 
						const int & width, 
						const int & startY, 
						const int & startX, 
						const char & printChar)const;
		///////////////
		char c_nickname[20],c_mapName[20];
};






#endif