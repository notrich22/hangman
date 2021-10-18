#include <iostream>
#include <Windows.h>
#include "Game.h"

using namespace std;

int main() {
	srand(time(NULL));
	Game game;
	_CrtDumpMemoryLeaks();
	return 0;
}