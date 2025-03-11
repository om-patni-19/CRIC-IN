#include "game.h"

using namespace std;

Game::Game() {

	playersPerTeam = 4;
	maxBalls = 6;
	totalPlayers = 11;

	allPlayers[0] = "Virat";
	allPlayers[1] = "Rohit";
	allPlayers[2] = "Dhawan";
	allPlayers[3] = "Krunal";
	allPlayers[4] = "Karthik";
	allPlayers[5] = "KLRahul";
	allPlayers[6] = "Jadeja";
	allPlayers[7] = "Hardik";
	allPlayers[8] = "Bumrah";
	allPlayers[9] = "BKumar";
	allPlayers[10] = "Ishant";

	isDraw = false;
	isFirstInnings = false;
	teamA.teamName = "Team-A";
	teamB.teamName = "Team-B";
};

void Game::welcomeMsg() {
	cout << "-------------------------------------------------------" << endl << flush;
	cout << "|=======================CRIC-IN=======================|" << endl << flush;
	cout << "|                                                     |" << endl << flush;
	cout << "|         Welcome to the Virtual Cricket Game         |" << endl << flush;
	cout << "|         Where its your game and your pitch!         |" << endl << flush;
	cout << "-------------------------------------------------------" << endl << flush;
	cout << endl << endl << flush;

}

void Game::instructions() {
	cout << "Let's look at some instructions to play the game" << endl << endl << flush;

	Sleep(1000);

	cout << "-----------------------------------------------------------------------" << endl << flush;
	cout << "|=============================INSTRUCTIONS============================|" << endl << flush;
	cout << "|                                                                     |" << endl << flush;
	Sleep(1000);
	cout << "|1. Create 2 teams (Team-A and Team-B with 4 players each) from a     |" << endl << flush;
	cout << "|   given pool of of 11 players.                                      |" << endl << flush;
	Sleep(4000);
	cout << "|2. Lead the toss and decide the choice of play.                      |" << endl << flush;
	Sleep(2000);
	cout << "|3. Each innings will be of 6 balls.                                  |" << endl << flush;
	Sleep(2000);
	cout << "|4. In each innings, only one bowler from the bowling team will bowl  |" << endl << flush;
	cout << "|   all 6 deliveries and at a time one batsman from the batting team  |" << endl << flush;
	cout << "|   will bat  until he is declared out.                               |" << endl << flush;
	Sleep(7000);
	cout << "|5. The first player from the bowling team will always be selected to |" << endl << flush;
	cout << "|   bowl first and the first player from the batting team will always |" << endl << flush;
	cout << "|   be selected to bat first.                                         |" << endl << flush;
	Sleep(5000);
	cout << "|6. When a batsman is OUT, the next batsman from the batting team in  |" << endl << flush;
	cout << "|   sequence will start batting.                                      |" << endl << flush;
	Sleep(3000);
	cout << "|7. In each delivery, possible runs can be scored from 0 to 6.       |" << endl << flush;
	cout << "-----------------------------------------------------------------------" << endl << flush;

	cout << endl << endl << flush;
}

void Game::playerPool() {

	cout << "-----------------------------------------------" << endl << flush;
	cout << "|===============POOL OF PLAYERS===============|" << endl << flush;
	cout << "-----------------------------------------------" << endl << flush;
	cout << endl << flush;

	for (int pl = 0; pl < totalPlayers; pl++) {
		Sleep(1000);
		cout << "\t\t[" << pl << "]. " << allPlayers[pl] << endl << flush;
	}

	cout << endl << flush;
}

int Game::takeIntegerInput() {
    int n;
    while (true) {
        cin >> n;
        if (!cin.fail()) break; // Valid input
        cin.clear(); // Reset error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        cout << "Invalid input! Please try again: " << flush;
    }
    return n;
}


bool Game::validatePlayer(int playerIndex) {

	int n;
	vector<Player>players;

	players = teamA.players;
	n = players.size();
	for (int i = 0; i < n; i++) {
		if (teamA.players[i].id == playerIndex) {
			return false;
		}
	}

	players = teamB.players;
	n = players.size();
	for (int i = 0; i < n; i++) {
		if (teamB.players[i].id == playerIndex) {
			return false;
		}
	}

	return true;
}

void Game::selectPlayers() {

	cout << endl << endl;
	cout << "----------------------------------------------------------------" << endl << flush;
	cout << "|================== CREATE TEAM-A AND TEAM-B ==================|" << endl << flush;
	cout << "----------------------------------------------------------------" << endl << endl << flush;

	for (int i = 0; i < playersPerTeam; i++) {

		// Selecting Players for Team-A
		teamASelection:
			cout << "Select player " << i+1 << " for Team-A: ";
			setbuf(stdout, NULL);
			int playerIndexTeamA = takeIntegerInput();
			cout << endl << flush;

			if (playerIndexTeamA < 0 || playerIndexTeamA > 10) {
				cout << endl << "Please select from the given players" << endl << flush;
				goto teamASelection;
			}
			else if (!(validatePlayer(playerIndexTeamA))) {
				cout << "Player already Selected. Please select another Player" << endl << flush;
				goto teamASelection;
			}
			else {
				Player teamAPlayer;
				teamAPlayer.id = playerIndexTeamA;
				teamAPlayer.name = allPlayers[playerIndexTeamA];

				teamA.players.push_back(teamAPlayer);
			}



		// Selecting Players for Team-B
		teamBSelection:
			cout << "Select player " << i+1 << " for Team-B: ";
			setbuf(stdout, NULL);
			int playerIndexTeamB = takeIntegerInput();
			cout << endl << flush;

			if(playerIndexTeamB < 0 || playerIndexTeamB > 10) {
				cout << endl << "Please select from the given players" << endl << flush;
				goto teamBSelection;
			}
			else if (!(validatePlayer(playerIndexTeamB))) {
				cout << "Player already Selected. Please select another Player" << endl << flush;
				goto teamBSelection;
				}
			else {
				Player teamBPlayer;
				teamBPlayer.id = playerIndexTeamB;
				teamBPlayer.name = allPlayers[playerIndexTeamB];

				teamB.players.push_back(teamBPlayer);
			}
	}
}

void Game::displayPlayers() {

	vector<Player> teamAPlayers = teamA.players;
	vector<Player> teamBPlayers = teamB.players;

	cout << endl << endl << flush;
	cout << "--------------------------\t\t--------------------------" << endl << flush;
	cout << "|=========Team-A=========|\t\t|=========Team-B=========|" << endl << flush;
	cout << "--------------------------\t\t--------------------------" << endl << flush;
	for (int i = 0; i < playersPerTeam; i++) {

		cout << "|\t" << "[" << i << "]" <<teamAPlayers[i].name << "\t |"
				<< "\t\t"
				<< "|\t" << "[" << i << "]" << teamBPlayers[i].name << "\t |" << endl << flush;
	}
	cout << "--------------------------\t\t--------------------------" << endl << endl << flush;
}

void Game::toss() {

	cout << "--------------------------------------" << endl << flush;
	cout << "|=============Let's Toss=============|" << endl << flush;
	cout << "--------------------------------------" << endl << flush;
	cout << endl << flush;

	Sleep(1000);
	cout << "Tossing the Coin........" << endl << endl << flush;
	Sleep(1500);

	srand(time(NULL));
	int toss = rand() % 2;

	switch(toss) {
		case 0:
			cout << "Team-A won the Toss" << endl << endl << flush;
			tossChoice(teamA);
			break;
		case 1:
			cout << "Team-B won the Toss" << endl << endl << flush;
			tossChoice(teamB);
			break;
	}
}

void Game::tossChoice(Team tossWinner) {

	cout << "Enter 1 to bat or 2 to bowl first. " << endl
			<< "1. Bat" << endl
			<< "2. Bowl" << endl
			<< "Choice: " << flush;

	int tossInput = takeIntegerInput();

	fflush(stdin);

	switch (tossInput) {
		case 1:
			cout << endl<< tossWinner.teamName << " won the toss and decided to bat first" << endl << endl << flush;
			if(tossWinner.teamName.compare("Team-A") == 0) {
				battingTeam = &teamA;
				bowlingTeam = &teamB;
			}
			else {
				battingTeam = &teamB;
				bowlingTeam = &teamA;
			}
			break;

		case 2:
			cout << endl << tossWinner.teamName << " won the toss and decided to bowl first" << endl << endl << flush;
			if(tossWinner.teamName.compare("Team-A") == 0) {
				bowlingTeam = &teamA;
				battingTeam = &teamB;
			}
			else {
				bowlingTeam = &teamB;
				battingTeam = &teamA;
			}
			break;

		default:
			cout << endl << "Invalid Input! Please try Again!!!" << endl << endl << flush;
			tossChoice(tossWinner);
			break;
	}
}

void Game::startFirstInnings() {

	cout << endl << "\t\t ||| FIRST INNINGS STARTS |||" << endl << endl << flush;
	isFirstInnings = true;

	initializePlayers();

	playInnings();
}

void Game::initializePlayers() {

	batsman = &battingTeam -> players[0];
	bowler = &bowlingTeam -> players[0];

	cout << battingTeam -> teamName << " - " << batsman -> name << " is batting" << endl << flush;
	cout << bowlingTeam -> teamName << " - " << bowler -> name << " is bowling" << endl << endl << flush;
}

void Game::playInnings() {

	for (int i = 0; i < maxBalls; i++) {

		cout << "Press Enter to Bowl....." << flush;
		getchar();
		cout << "Bowling..." << endl << endl << flush;
		bat();

		if(!validateInningsScore()) {
			break;
		}
	}
}

void Game::bat() {

	srand(time(NULL));

	int runs = rand() % 7;

	batsman -> runsScored = batsman -> runsScored + runs;
	battingTeam -> totalRunsScored = battingTeam -> totalRunsScored + runs;
	batsman -> ballsPlayed = batsman -> ballsPlayed + 1;

	bowler -> ballsBowled = bowler -> ballsBowled +1;
	bowler -> runsGiven = bowler -> runsGiven + runs;
	bowlingTeam -> totalBallsBowled = bowlingTeam -> totalBallsBowled + 1;

	if (runs != 0) {
		cout << endl << bowler -> name << " to " << batsman -> name << " " << runs << " runs!" << endl << endl << flush;
	}
	else {
		cout << endl << bowler -> name << " to " << batsman -> name << " OUT!" << endl << endl << flush;
		battingTeam -> wicketsLost = battingTeam -> wicketsLost + 1;
		bowler -> wicketsTaken = bowler -> wicketsTaken + 1;

		int nextPlayerIndex = battingTeam -> wicketsLost;
		batsman = &battingTeam -> players[nextPlayerIndex];
	}

	showGameScoreCard();
}

bool Game::validateInningsScore() {

	if(isFirstInnings) {
		if (battingTeam -> wicketsLost == playersPerTeam || bowlingTeam -> totalBallsBowled == maxBalls) {

			cout << "\t\t ||| FIRST INNINGS ENDS |||" << endl << endl << flush;

			cout << battingTeam -> teamName << " \t" << battingTeam -> totalRunsScored
					<< " - " << battingTeam -> wicketsLost << " (" << bowlingTeam -> totalBallsBowled
					<< ")" << endl << flush;
			cout << bowlingTeam -> teamName << " needs " << battingTeam -> totalRunsScored + 1
					<< " runs to win the match" << endl << endl << flush;

			return false;
		}
	}
	else {
		if (battingTeam -> wicketsLost == playersPerTeam || bowlingTeam -> totalBallsBowled == maxBalls || battingTeam -> totalRunsScored > bowlingTeam -> totalRunsScored) {

			cout << "\t\t ||| SECOND INNINGS ENDS |||" << endl << endl << flush;

			return false;
		}
	}

	return true;
}

void Game::showGameScoreCard() {

	cout << "------------------------------------------------------------------------------------" << endl << flush;
	cout << "\t " << battingTeam -> teamName << " " <<  battingTeam -> totalRunsScored
			<< " - " << battingTeam -> wicketsLost << " (" << bowlingTeam -> totalBallsBowled << ") "
			<< "\t|\t" << batsman -> name << "\t" << batsman -> runsScored << " (" << batsman -> ballsPlayed
			<< ")\t\t" << bowler -> name << "  " << bowler -> ballsBowled << " - " << bowler -> runsGiven
			<< " - " << bowler -> wicketsTaken << endl << flush;
	cout << "------------------------------------------------------------------------------------\n" << endl << flush;
}

void Game::startSecondInnings() {

	cout << endl << "\t\t||| SECOND INNINGS STARTS |||" << endl << endl << flush;

	isFirstInnings = false;
	swapTeamPointers(&battingTeam, &bowlingTeam);

	initializePlayers();

	playInnings();
}

void Game::swapTeamPointers(Team **bat, Team **bowl) {

	Team *tempTeam = *bat;
	*bat = *bowl;
	*bowl = tempTeam;
}

void Game::showWinner() {

	cout << endl << "Calculating Winner...." << endl << endl << flush;

	if(bowlingTeam -> totalRunsScored > battingTeam -> totalRunsScored) {
		cout << bowlingTeam -> teamName << " won the batch by " << bowlingTeam -> totalRunsScored - battingTeam -> totalRunsScored << " runs!!" << endl << endl << flush;
		Sleep(2000);
		cout << "\t\t ||| MATCH ENDS |||" << endl << endl << flush;
		cout << "Press Enter to get the match summary..." << endl << endl << flush;
		fflush(stdin);
		getchar();
		cout << endl << endl << flush;
		matchSummary(teamA, teamB);
		matchSummary(teamB, teamA);
	}
	else if(battingTeam -> totalRunsScored > bowlingTeam -> totalRunsScored) {
		cout << battingTeam -> teamName << " won the match by " << playersPerTeam - battingTeam -> wicketsLost << " wickets" << endl << endl << flush;
		Sleep(2000);
		cout << "\t\t ||| MATCH ENDS |||" << endl << endl << flush;
		cout << "Press Enter to get the match summary..." << endl << endl << flush;
		fflush(stdin);
		getchar();
		cout << endl << endl << flush;
		matchSummary(teamA, teamB);
		matchSummary(teamB, teamA);
	}
	else {

		isDraw = true;

		cout << "It's a Draw!!" << endl << endl << flush;

		matchSummary(teamA, teamB);
		matchSummary(teamB, teamA);

		cout << endl << endl << "Let's play another over..." << endl << flush;

		draw();
	}
}

void Game::draw() {

	battingTeam -> totalBallsBowled = 0;
	bowlingTeam -> totalBallsBowled = 0;
	battingTeam -> totalRunsScored = 0;
	bowlingTeam -> totalRunsScored = 0;
	battingTeam -> wicketsLost = 0;
	bowlingTeam -> wicketsLost = 0;

	for (int i = 0; i < playersPerTeam; i++) {
		battingTeam -> players[i].ballsBowled = 0;
		battingTeam -> players[i].ballsPlayed = 0;
		battingTeam -> players[i].runsGiven = 0;
		battingTeam -> players[i].runsScored = 0;
		battingTeam -> players[i].wicketsTaken = 0;

		bowlingTeam -> players[i].ballsBowled = 0;
		bowlingTeam -> players[i].ballsPlayed = 0;
		bowlingTeam -> players[i].runsGiven = 0;
		bowlingTeam -> players[i].runsScored = 0;
		bowlingTeam -> players[i].wicketsTaken = 0;
	}
}

void Game::matchSummary(Team currentTeam, Team oppTeam) {

	cout << currentTeam.teamName << " " << currentTeam.totalRunsScored << " - " << currentTeam.wicketsLost << " (" << oppTeam.totalBallsBowled << ")" << endl << flush;
	cout << "==========================================" << endl << flush;
	cout << "| Player \t Batting \tBowling  |" << endl;

	for (int i = 0; i < playersPerTeam; i++) {
		cout << "|----------------------------------------|" << endl << flush;
		cout << "| [" << i << "] " << currentTeam.players[i].name
				<< "\t " << currentTeam.players[i].runsScored << "(" << currentTeam.players[i].ballsPlayed << ")"
				<< "\t\t" << currentTeam.players[i].ballsBowled << "-" << currentTeam.players[i].runsGiven << "-" << currentTeam.players[i].wicketsTaken << "\t |" << endl << flush;
	}
	cout << "==========================================" << endl << endl << flush;
}
