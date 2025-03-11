#include "game.h"     // <iostream>, <cstdlib>, <ctime>, <limits>, "team.h", <vector>, "player.h", <string>

using namespace std;

int main() {

	Game game;

	game.welcomeMsg();

	Sleep(1000);

	game.instructions();

	Sleep(1000);

	cout << "Press Enter to Continue" << flush;
	setbuf(stdout, NULL);
	fflush(stdin);
	getchar();
	cout << endl << endl << flush;

	game.playerPool();

	cout << "Press Enter to Continue" << flush;
	setbuf(stdout, NULL);
	fflush(stdin);
	getchar();
	cout << endl << endl << flush;

	game.selectPlayers();

	cout << endl << "Displaying Teams......." << endl << flush;

	Sleep(1500);

	game.displayPlayers();

	cout << endl << "Press Enter to Toss" << flush;
	setbuf(stdout, NULL);
	fflush(stdin);
	getchar();
	cout << endl << endl << flush;

	game.toss();

	Sleep(2000);

	ifDraw:
	game.startFirstInnings();

	Sleep(2000);

	cout << endl << "Press Enter to Start the Second Innings" << flush;
	fflush(stdin);
	getchar();
	cout << endl << endl << flush;

	game.startSecondInnings();

	Sleep(2000);

	game.showWinner();

	if (game.isDraw == true) {

		goto ifDraw;
	}

	return 0;
}
