#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "team.h"      //<vector>, "player.h", <string>

class Game {
	public:
		Game();

		int playersPerTeam;
		int maxBalls;
		int totalPlayers;
		std::string allPlayers[11];

		bool isDraw;
		bool isFirstInnings;
		Team teamA, teamB;
		Team *battingTeam, *bowlingTeam;
		Player *batsman, *bowler;

		void welcomeMsg();
		void instructions();
		void playerPool();
		int takeIntegerInput();
		void selectPlayers();
		bool validatePlayer(int);
		void displayPlayers();
		void toss();
		void tossChoice(Team);
		void startFirstInnings();
		void initializePlayers();
		void playInnings();
		void bat();
		bool validateInningsScore();
		void showGameScoreCard();
		void startSecondInnings();
		void swapTeamPointers(Team **, Team **);
		void showWinner();
		void draw();
		void matchSummary(Team, Team);
};
