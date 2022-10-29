#ifndef __Snake__
#define __Snake__
#include "Game.h"

enum Direction
{
	NONE,
	DOWN,
	UP,
	RIGHT,
	LEFT
};

class Snake : private Game
{
public:
	Snake();
	~Snake();
	SDL_Rect head{ 500,500,10,10 };
	//void DrawHead();
	void Movement();
	SDL_Event ev;
	bool run;
	int size;


private:
	

};

#endif /* defined(__Game__) */