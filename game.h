
#ifndef GAME_H
#define GAME_H

#include <cstdlib>
#include <unistd.h>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "background.h"

using namespace std;

#define BONUSAMMO 1
#define BONUSINDESTRUCT 2
#define BONUSGUNS 3


class CGame {
	public:
		CGame();
		~CGame();
		void runGame();
		void moveBullets();
		void gameControll();
		void checkShip();
		void checkBullets();
		void checkReloading();
		void checkBonuses();
		void rollBonus();
	private:
		void reloadMag();
		void moveObstacles();
		void deleteObst(const int & i);
		void deleteBullet(const int & i);
		void spawnObstacles();
		bool gameOver();
		bool hitBullet(YXPART & bullet, const int & cnt);
		bool hitShip(YXPART & shipCPoint);


		vector<CObstacle*> obstacles;
		vector<CBullet> ammo;

		int c_cntBullets;
		int c_score, c_crntObst, c_health, c_remainObst,c_mag;
		CTimer timer;
		CShip BattleShip;
		CBack background;	
		bool c_isReloading;
		int c_reloadT;

		int c_bonus;
		int c_bonusTime;

		///////////////
		vector<LOADLEVEL> file;
		int c_cntFileObjs;
};






#endif