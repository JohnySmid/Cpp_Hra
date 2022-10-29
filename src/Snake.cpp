#include "Snake.h"
#include <SDL.h>


Snake::Snake() 
{ 
	run = true; 
	size = 1; 
};

Snake::~Snake() {};

//void Snake::DrawHead() 
//{
//	std::cout << "kreslim hlavu";
//	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
//	SDL_RenderFillRect(renderer, &head);
//	SDL_RenderPresent(renderer);
//	SDL_Delay(25);
//}

void Snake::Movement()
{
	SDL_PollEvent(&ev);
	if (ev.type == SDL_QUIT) {
		run = false;
		//Game::Clean();
	}
		
		
	// snake movement
	if (ev.type == SDL_KEYDOWN) {
		//std::cout << (char)evnt.key.keysym.sym << "\n";
		if (ev.key.keysym.sym == SDLK_DOWN) { dir = DOWN; }
		if (ev.key.keysym.sym == SDLK_UP) { dir = UP; }
		if (ev.key.keysym.sym == SDLK_RIGHT) { dir = RIGHT; }
		if (ev.key.keysym.sym == SDLK_LEFT) { dir = LEFT; }
	}
	switch (dir)
	{
	case DOWN:
		head.y += 10;
		std::cout << "DOWN\n";
		break;
	case UP:
		head.y -= 10;
		std::cout << "UP\n";
		break;
	case RIGHT:
		head.x += 10;
		std::cout << "RIGHT\n";
		break;
	case LEFT:
		head.x -= 10;
		std::cout << "LEFT\n";
		break;
	}
}