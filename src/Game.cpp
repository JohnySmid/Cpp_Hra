#include "Game.h"
#include "Snake.h"

Snake hadik;

Game::Game() 
{
	window = nullptr;
	renderer = nullptr;
};

Game::~Game() {};

void Game::Running() 
{
	Init("Snape", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 1000, 0);
	GameLoop();
}

void Game::Init(const char* title, int posx, int posy, int w, int h, Uint32 flags)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow(title, posx, posy, w, h, flags);
	renderer = SDL_CreateRenderer(window, -1, 0);
	is_Running = true;
}

void Game::GameLoop()
{
	
	while (hadik.run && is_Running) {
		HandleEvents();
		Bgrd();
		Draw();
		//hadik.DrawHead();
	}
		

	Clean();

}

void Game::HandleEvents() 
{
	//

	/*if(evnt.type == SDL_QUIT)
		is_Running = false;*/

	//// snake movement
	//if (evnt.type == SDL_KEYDOWN) {
	//	//std::cout << (char)evnt.key.keysym.sym << "\n";
	//	if (evnt.key.keysym.sym == SDLK_DOWN) { dir = DOWN; }
	//	if (evnt.key.keysym.sym == SDLK_UP) { dir = UP; }
	//	if (evnt.key.keysym.sym == SDLK_RIGHT) { dir = RIGHT; }
	//	if (evnt.key.keysym.sym == SDLK_LEFT) { dir = LEFT; }
	//}
	hadik.Movement();
	


	
}

void Game::SpawnApples()
{
	for (int i = 0; i < 100; i++) {		
		apples.insert(apples.end(), { rand()%100*10,rand() % 100 * 10,10,10 });
	}

}

void Game::Draw() 
{
	//std::cout << "kreslim hlavu";
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &hadik.head);
	SDL_RenderPresent(renderer);
	SDL_Delay(25);

	
}

void Game::Bgrd() 
{
	SDL_SetRenderDrawColor(renderer, 86, 77, 77, 255);	//green
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	
}

void Game::Clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}