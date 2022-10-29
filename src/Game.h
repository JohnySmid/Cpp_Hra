#ifndef __Game__
#define __Game__

#include <SDL.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>







class Game
{
public:
	Game();
	~Game();
	void Running();
	

private:
	void Init(const char* title, int posx, int posy, int w, int h, Uint32 flags);
	void GameLoop();
	void HandleEvents();
	void Draw();
	void Bgrd();
	std::deque<SDL_Rect> rq;
	std::vector<SDL_Rect> apples;
	
	void SpawnApples();
	

protected:
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool is_Running = false;
	int dir;
	void Clean();
	
};

#endif /* defined(__Game__) */