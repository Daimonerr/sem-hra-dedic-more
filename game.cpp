#include "game.h"

CGame::CGame(): c_cntBullets(0), c_score(0), c_crntObst(0), c_health(3), c_remainObst(0), c_cntFileObjs(0)
{
	initscr();	
}


CGame::~CGame()
{
	nodelay(stdscr, false);
	for (auto it = 	obstacles.begin() ; it != obstacles.end(); ++it)
		{ delete (*it); }
    obstacles.clear();
    ammo.clear();
	endwin();
}

void CGame::moveBullets()
{
	for (int i = 0; i < c_cntBullets; i++)
	{
		if ( ! ammo[i].moveO())
		{
			deleteBullet(i);
			i--;
		}
		
	}	
}

void CGame::runGame()
{

	background.startMenu(file, c_cntFileObjs);
	c_remainObst = c_cntFileObjs;
	background.drawMap();

	noecho();
	curs_set(0);
	nodelay(stdscr,true);
	keypad(stdscr, true);

	

	while( ! gameOver())
	{

		BattleShip.printO();
		spawnObstacles();

		moveBullets();
		moveObstacles();
		
		refresh();
		checkShip();
		checkBullets();
		if (timer.getPlaytime() == 200 )
			break;


//////////////////////////////////////////////
		usleep(20000);
//////////////////////////////////////////////
		BattleShip.clearO();
		gameControll();
		background.printUtilities(c_score, c_remainObst, c_health, timer);
		timer.addTime();
	}

	background.gameEnding(c_score);
}

void CGame::checkShip()
{

	vector<YXPART> shipCPoints(BattleShip.giveCollisionPoints());

	for ( int i = 0; i < 21; i++)
	{
		if (hitShip(shipCPoints[i]))
			return;
	}
}
bool CGame::hitShip(YXPART & shipCPoint)
{
	for( int j = 0; j < c_crntObst; j++)
	{
		if (obstacles[j]->collide(shipCPoint.offsY,shipCPoint.offsX))
		{
			deleteObst(j);
			c_health--;	
			return true;
		}
	}
	return false;
}

void CGame::checkBullets()
{
	for ( int i = 0; i < c_cntBullets; i++)
	{
		YXPART bullet(ammo[i].giveCorePoint());
		
		if( hitBullet(bullet, i))
			return;
	}	
}

bool CGame::hitBullet(YXPART & bullet, const int & cnt)
{
	for( int j = 0; j < c_crntObst; j++)
	{
		if (obstacles[j]->collide(bullet.offsY,bullet.offsX))
		{	
			deleteBullet(cnt);
			deleteObst(j);

			c_score += 20;
			return true;
		}
	}
	return false;
}


void CGame::gameControll()
{
	switch (getch())
	{
		case KEY_UP:
			BattleShip.moveUp();
			break;

		case KEY_DOWN:
			BattleShip.moveDown();
			break;

		case KEY_LEFT:
			BattleShip.moveLeft();
			break;

		case KEY_RIGHT:
			BattleShip.moveRight();
			break;
		
		case 'f':
			ammo.push_back(BattleShip.newBullet());
			c_cntBullets++;
			break;
		case 'l':

			background.pauseGame();
			break;
	}

}



void CGame::moveObstacles()
{

	for (int i = 0; i < c_crntObst; i++)
	{
		if( ! obstacles[i]->moveO(timer))
		{
			deleteObst(i);
			i--;
		}
	}
}


void CGame::deleteObst(const int & i)
{
	auto it = (obstacles.begin()+i);
	delete (*it);
	obstacles.erase(obstacles.begin()+i);

	c_crntObst--;
}



void CGame::deleteBullet(const int & i)
{
	ammo.erase(ammo.begin()+i);
	c_cntBullets--;
}

void CGame::spawnObstacles()
{
	for (int i = 0; i < c_cntFileObjs; i++)
	{
		if ( file[i].time == timer.getPlaytime() && timer.getMsec() == 0 )
		{
	
			switch (file[i].type)
			{
				case 'A':
					obstacles.push_back(new CObstacleA(file[i].y,file[i].x, '#',file[i].sp));
					break; 
				case 'B':
					obstacles.push_back(new CObstacleB(file[i].y,file[i].x, '#',file[i].sp));			
					break;
				case 'C':
					obstacles.push_back(new CObstacleC(file[i].y,file[i].x, '#',file[i].sp));			
					break;
			}

			c_crntObst++;
			c_remainObst--;
		}
	}

}


bool CGame::gameOver()
{
	if ( c_health == 0)
		return true;
	return false;
}
