#pragma once
#include "Property.h"
#include "Special.h"
#include "Tile.h"
#include "Player.h"
#include "Chance.h"
#include "ComChest.h"
#include "Railroad.h"
#include "Tax.h"
#include "Utility.h"
#include <ctime>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iomanip>
#include <algorithm>

using namespace std;

int diceRoll() {
	cout << "\n*Rolling*\n";
	int num;
	num = (1 + (rand() % 6));
	return num;
}

void action(Player * a, Tile* board[], std::vector<Player*> players) {
	board[a->getCurPos()]->performAction(a, players);
}


void purchase(Player * a, std::string propName, int price) {
	//a.purchase(propName, price);
}

void getOutOfJail(std::vector<Player *> players, Player * a, Tile* board[]) {

	cout << "\nYou have to roll doubles and then be let out of jail. \n";
	int diceOne = diceRoll();
	int diceTwo = diceRoll();

	cout << "Roll one = " << diceOne << ", " << diceTwo;
	a->newDoubleTry();
	if (diceOne == diceTwo) {
		cout << "\nSuccess! You are free!";
		cout << "You move " << diceOne + diceTwo << " spaces.";
		a->setCurPos(a->getCurPos() + diceOne + diceTwo);
		action(a, board, players);
		a->doubleTryClear();
	}

	else {
		cout << "\nUnfortunately, none of your rolls were doubles. You are still in jail. \nBetter luck next time!";
		if (a->getDoubleTry() >= 3) {
			cout << "\nBecause you did not get doubles in 3 tries, the bank will take $50 from your account.";
			a->addMoney(-50);
		}
		else {
			cout << "You have no get out of jail free cards.";
		}
	}
}

void createBoardDisplay(std::string displayBoard[]) {
	for (int i = 0; i < 40; i++) {
		displayBoard[i] = "[ ]";
	}
	displayBoard[0] = "[x]";
}

void displayBoard(std::string displayBoard[]) {
	for (int i = 0; i < 11; i++) {
		cout << displayBoard[i];
	}

	cout << "\n" << displayBoard[39] << setw(30) << displayBoard[11];
	cout << "\n" << displayBoard[38] << setw(30) << displayBoard[12];
	cout << "\n" << displayBoard[37] << setw(30) << displayBoard[13];
	cout << "\n" << displayBoard[36] << setw(30) << displayBoard[14];
	cout << "\n" << displayBoard[35] << setw(30) << displayBoard[15];
	cout << "\n" << displayBoard[34] << setw(30) << displayBoard[16];
	cout << "\n" << displayBoard[33] << setw(30) << displayBoard[17];
	cout << "\n" << displayBoard[32] << setw(30) << displayBoard[18];
	cout << "\n" << displayBoard[31] << setw(30) << displayBoard[19] << "\n";

	for (int i = 30; i > 19; i--) {
		cout << displayBoard[i];
	}
	cout << "\n";
}

void updateBoard(std::string board[], Player * player, std::vector<Player *> players) {
	for (int i = 0; i < 40; i++) {
		board[i] = "[ ]";
	}
	for (Player * x : players) {
		board[x->getCurPos()] = "[x]";
	}
	displayBoard(board);
	
}

void move(Player * player, Tile* board[], std::vector<Player *> players, std::string displayBoard[])
{
	system("CLS");
	int counter = 0;
	int die1 = 0;
	int die2 = 0;
	int sum;
	int newPos;
	string wasted = "";

	die1 = diceRoll();
	cout << die1 << endl;
	die2 = diceRoll();
	cout << die2 << endl;

	sum = (die1 + die2);
	cout << "\nYou will move " << sum << " spaces." << endl;
	if (player->getCurPos() + sum > 39) {
		player->setCurPos(player->getCurPos() + sum - 39);
		player->addMoney(200);
		cout << "\nFor passing/landing on Go, you are given $200!.";
	}
	else{
		player->setCurPos(player->getCurPos() + sum);
	}
	while ((die1 == die2) && (counter < 4))
	{
		updateBoard(displayBoard, player, players);
		action(player, board, players);
		cout << "You rolled doubles, therefore you get another turn!";
		die1 = diceRoll();
		die2 = diceRoll();
		sum = (die1 + die2);

		counter += 1;

		if (player->getCurPos() + sum > 39) {
			player->setCurPos(player->getCurPos() + sum - 39);
			player->addMoney(200);
			cout << "\nFor passing/landing on Go, you are given $200!.\n";
		}
		else {
			player->setCurPos(player->getCurPos() + sum);
		}
		
		while (die1 == die2 && counter < 3) {
			updateBoard(displayBoard, player, players);
			action(player, board, players);
			cout << "\nYou get to roll again!\n";
			die1 = diceRoll();
			die2 = diceRoll();
			sum = (die1 + die2);
			if (player->getCurPos() + sum > 39) {
				player->setCurPos(player->getCurPos() + sum - 39);
				player->addMoney(200);
				cout << "\nFor passing/landing on Go, you are given $200!.\n";
			}
			else {
				player->setCurPos(player->getCurPos() + sum);
			}
			counter += 1;
		}

		if ((counter == 3) && (die1 == die2))
		{
			player->jail();
		}
		
	}
	updateBoard(displayBoard, player, players);
	action(player, board, players);
}

string welcome() {

	string welcome = "\n /$$      /$$                                                   /$$          ";
	welcome += "\n| $$$    /$$$                                                  | $$          ";
	welcome += "\n| $$$$  /$$$$  /$$$$$$  /$$$$$$$   /$$$$$$   /$$$$$$   /$$$$$$ | $$ /$$   /$$";
	welcome += "\n| $$ $$/$$ $$ /$$__  $$| $$__  $$ /$$__  $$ /$$__  $$ /$$__  $$| $$| $$  | $$";
	welcome += "\n| $$  $$$| $$| $$  \\ $$| $$  \\ $$| $$  \\ $$| $$  \\ $$| $$  \\ $$| $$| $$  | $$";
	welcome += "\n| $$\\  $ | $$| $$  | $$| $$  | $$| $$  | $$| $$  | $$| $$  | $$| $$| $$  | $$";
	welcome += "\n| $$ \\/  | $$|  $$$$$$/| $$  | $$|  $$$$$$/| $$$$$$$/|  $$$$$$/| $$|  $$$$$$$";
	welcome += "\n|__/     |__/ \\______/ |__/  |__/ \\______/ | $$____/  \\______/ |__/ \\____  $$";
	welcome += "\n                                           | $$                     /$$  | $$";
	welcome += "\n                                           | $$                    |  $$$$$$/";
	welcome += "\n                                           |__/                     \\______/ \n";

	return welcome;
}

void bOption(Player * player, std::vector<Player *> players) {
	string playerChoice;
	int trade;
	int tradeFor;
	cout << "\n\nPlayers: \n";
	for (int i = 0; i < players.size(); i++) {
		cout << players[i]->getName() << "\n";
	}
	cout << "\nWhich player would you like to trade with? ";
	cin >> playerChoice;
	Player * x = player;
	for (Player* g : players) {
		if (g->getName() == playerChoice) {
			x = g;
		}
		else {

		}
	}

	cout << x->getName() << "'s Inventory:\n";
	for (int i = 0; i < x->inv.size(); i++) {
		cout << i + 1 << x->inv[i]->getName() << "\n";
	}

	cout << "\n\nYour Inventory:\n";
	for (int i = 0; i < player->inv.size(); i++) {
		cout << i + 1 << ") " << player->inv[i]->getName() << "\n";
	}

	cout << "\n\nEnter the number of the property that you would like to trade: ";
	cin >> trade;
	cout << "\n\nEnter the number of the property that you would like to receive: ";
	cin >> tradeFor;

	Tile * temp = player->inv[trade - 1];
	player->inv[trade - 1] = x->inv[tradeFor - 1];
	x->inv[tradeFor - 1] = temp;

	cout << x->getName() << "'s new Inventory:\n";
	for (int i = 0; i < x->inv.size(); i++) {
		cout << i + 1 << x->inv[i]->getName() << "\n";
	}

	cout << "\n\nYour new Inventory:\n";
	for (int i = 0; i < player->inv.size(); i++) {
		cout << i + 1 << ") " << player->inv[i]->getName() << "\n";
	}
}

void cOption(std::vector <Player *> players, Player * player) {
	string playerChoice;
	string propChoice;
	int amount;
	cout << "Players; \n";
	for (int i = 0; i < players.size(); i++) {
		cout << players[i]->getName() << "\n";
	}
	cout << "\nWhich player would you like to sell a property to? ";
	cin >> playerChoice;
	Player * x = player;
	for (Player* g : players) {
		if (g->getName() == playerChoice) {
			x = g;
		}
		else {

		}
	}
	cout << "\n\nWhich property would you like to sell? ";
	for (Tile* x : player->inv) {
		cout << x->getName() << "\n";
	}
	cin >> propChoice;

	for (Tile* h : player->inv) {
		if (h->getName() == propChoice) {
			cout << "How much would you like to sell this property for? ";
			cin >> amount;
			player->addMoney(amount);
			x->inv.push_back(h);
			x->subMoney(amount);

		}
		else {
			cout << "\nThat property does not exist. (They are case sensitive)";
		}
	}
}

void dOption(Player * player) {
	string ans;
	cout << "\nYou have chosen to mortgage your properties!\n";
	int answer;
	player->getInventory();
	for (int a = 0; a < player->inv.size(); a++) {
		cout << a + 1 << ") " << player->inv[a]->getName();
	}
	if (player->inv.size() > 0) {
		cout << "\nWhich one would you like to mortgage? (Enter number): ";
		cin >> answer;
		if (player->inv[answer - 1]->owned != 2) {
			player->inv[answer - 1]->owned = 2;
			cout << "\nValue of space = " << player->inv[answer - 1]->value;
			player->addMoney(player->inv[answer - 1]->value);
			cout << "\nYour balance is now " << player->getBalance();
		}
		else {
			cout << "\nThis property is already mortgaged.\n";
		}
	}
	else {
		cout << "\nYou have no properties to mortgage.\n";
	}
	
}

void eOption(Player * player) {
	std::vector<Tile*> temp;
	string answ;
	if (player->inv.size() > 0) {
		cout << "\nYour mortgaged properties: \n";

		for (int j = 0; j < player->inv.size(); j++) {
			if (player->inv[j]->owned == 2) {
				temp.push_back(player->inv[j]);
				cout << "\nAdded " << player->inv[j]->getName() << "\n";
				;
			}
			for (int num = 0; num < temp.size(); num++) {
				cout << "\n" << num + 1 << ") " << temp[num]->getName() << "\n";
			}
		}
		int ans;
		cout << "\nWhich property would you like to buy back? (Enter the number): ";
		cin >> ans;
		cout << temp.size();
		if (temp.size() > ans - 1 || temp.size() == ans - 1) {
			cout << "\n\nin if statement\n\n";
			if (temp[ans - 1]->owned == 2) {
				player->subMoney(temp[ans - 1]->value);
				temp[ans - 1]->owned = 1;
				cout << "Your balance is now " << player->getBalance() << "\n";
			}
		}

	}
	else {
		cout << "\nYou have no mortgaged properties";
	}
}

int main() {
	// This is for the diceRoll function
	srand(time(NULL));

	Tile* board[40];

	//Put this in main
	Property br1("brown", "Mediteranean Avenue", 60); Property br2("brown", "Baltic Avenue", 60);
	Property lb1("light-blue", "Oriental Avenue", 100); Property lb2("light-blue", "Vermont Avenue", 100); Property lb3("light-blue", "Connecticut Avenue", 120);
	Property p1("purple", "St.Charles place", 140); Property p2("purple", "States Avenue", 140); Property p3("purple", "Virginia Avenue", 160);
	Property o1("orange", "St.James place", 180); Property o2("orange", "Tennessee Avenue", 180); Property o3("orange", "New York Avenue", 280);
	Property r1("red", "Kentucky Avenue", 220); Property r2("Red", "Indiana Avenue", 220); Property r3("Red", "Illinois Avenue", 240);
	Property y1("yellow", "Atlantic Avenue", 260); Property y2("yellow", "Ventor Avenue", 260); Property y3("yellow", "Marvin Gardens", 280);
	Property g1("green", "Pacific Avenue", 300); Property g2("green", "North Carolina Avenue", 300); Property g3("green", "Pennsylvania Avenue", 320);
	Property b1("blue", "Park place", 350); Property b2("blue", "Board Walk", 400);

	// special
	Special s1("Go"); Special s2("Just Visiting / jail"); Special s3("Free Parking"); Special s4("Go directly to Jail");

	// community chests
	ComChest cc1("Community Chest"); ComChest cc2("Community Chest"); ComChest cc3("Community Chest");

	// chance
	Chance c1("Chance"); Chance c2("Chance"); Chance c3("Chance");

	// Tax
	Tax t1("Income Tax"); Tax t2("Luxary Tax");

	// utilities
	Utility u1("Electric Company", 150); Utility u2("Water Works", 150);

	// railroads
	Railroad rr1("Reading Railroad", 200); Railroad rr2("Pennsylvania Railroad", 200); Railroad rr3("B & O Railroad", 200); Railroad rr4("Shortline Railroad", 200);

	// create board
	board[0] = &s1; board[1] = &br1; board[2] = &cc1; board[3] = &br2; board[4] = &t1; board[5] = &rr1; board[6] = &lb1; board[7] = &c1; board[8] = &lb2; board[9] = &lb3;
	board[10] = &s2; board[11] = &p1; board[12] = &u1; board[13] = &p2; board[14] = &p3; board[15] = &rr2; board[16] = &o1; board[17] = &cc2; board[18] = &o2; board[19] = &o3;
	board[20] = &s3; board[21] = &r1; board[22] = &c2; board[23] = &r2; board[24] = &r3; board[25] = &rr3; board[26] = &y1; board[27] = &y2; board[28] = &u2; board[29] = &y3;
	board[30] = &s4; board[31] = &g1; board[32] = &g2; board[33] = &cc3; board[34] = &g3; board[35] = &rr4; board[36] = &c3; board[37] = &b1; board[38] = &t2; board[39] = &b2;

	// Create the board
	static std::string displayableBoard[40];
	createBoardDisplay(displayableBoard);

	// Welcome 
	cout << welcome();

	// Gets number of players
	int numOfPlayers;
	cout << "Welcome to the c++ Monopoly game\n";
	cout << "Enter the number of players: ";
	cin >> numOfPlayers;

	// Instantiates Player objects
	Player playOne("a", "[1]");
	Player playTwo("b", "[2]");
	Player playThree("c", "[3]");
	Player playFour("d", "[4]");
	Player playFive("e", "[5]");
	Player playSix("f", "[6]");

	// Creates vector for players
	vector<Player *> players;

	// Adds players to vector
	players.push_back(&playOne);
	players.push_back(&playTwo);
	players.push_back(&playThree);
	players.push_back(&playFour);
	players.push_back(&playFive);
	players.push_back(&playSix);

	// Removes players that aren't playing
	for (int i = 6; i > numOfPlayers; i--) {
		players.pop_back();
	}

	// Gets and sets player names
	string name;
	for (int i = 0; i < players.size(); i++) {
		cout << "\nWhat is the name of player " << i + 1 << "? ";
		cin >> name;
		players[i]->setName(name);
	}

	// Clear screen
	system("CLS");

	// Prints player names
	cout << "Players:\n";
	for (Player* x : players) {
		cout << x->getName() << "\n";
	}

	char choices[7] = { 'A', 'B', 'C', 'D' ,'E', 'F','G' };

	string menu = "\nA) Check inventory\nB) Trade with player\nC) Sell property to player\nD) Mortage property\nE) Buy back mortgaged property\nF) Display current balance\nG) Move\n";
	char ans = 'G';


	int moveVal;

	// Player turns
	while (players.size() > 1) {
		for (int i = 0; i < players.size(); i++) {
			if (players[i]->isJailed() == 0) {
				moveVal = 0;
				while (moveVal < 1) {
					system("CLS");
					displayBoard(displayableBoard);
					cout << "\n" << players[i]->getName() << "'s turn.\n";

					cout << "Choose your next move from this menu: \n" << menu;
					cin >> ans;
					if (ans == 'A' || ans == 'a') {
						cout << "\nYour Inventory: \n";
						players[i]->getInventory();
					}
					else if (ans == 'B' || ans == 'b') {
						bOption(players[i], players);
					}

					// Selling properties to other players
					else if (ans == 'C' || ans == 'c') {
						cOption(players, players[i]);
					}
					else if (ans == 'D' || ans == 'd') {
						dOption(players[i]);
					}
					else if (ans == 'E' || ans == 'e') {
						eOption(players[i]);
					}
					else if (ans == 'F' || ans == 'f') {
						cout << "\nYour current balance is $" << players[i]->getBalance() << "\n";
					}

					// Player chooses to move
					else if (ans == 'G' || ans == 'g') {
						// Checks to see if they have already moved this turn
						if (moveVal > 0) {
							cout << "\nYou cannot move again.\n";
						}
						// Checks to see if they are on a railroad (for railroad travel)
						if (players[i]->getCurPos() == 5 || players[i]->getCurPos() == 15 || players[i]->getCurPos() == 25 || players[i]->getCurPos() == 35) {
							string choice;
							cout << "\nYou are on a Railroad space. \nWould you like to travel to another railroad? (y/n)";
							cin >> choice;
							if (choice == "y") {
								string answ;
								string option = "*****************************\na) Reading Railroad (Tile 5)\nb) Pennsylvania Railroad (Tile 15)\nc) B. & O. Railroad (Tile 25)\nd) Short Line (Tile 35)\n*****************************";
								cout << "\nYou have opted to travel by railroad.";
								cout << "\nWhich station would you like to travel to? " << "\n" << option << " :";
								cin >> answ;
								if (answ == "a") {
									players[i]->setCurPos(5);
									moveVal += 1;
								}
								else if (answ == "b") {
									players[i]->setCurPos(15);
									moveVal += 1;
								}
								else if (answ == "c") {
									players[i]->setCurPos(25);
									moveVal += 1;
								}
								else if (answ == "d") {
									players[i]->setCurPos(35);
									moveVal += 1;
								}
								else {
									cout << "\nYou have entered an invalid symbol.\n";
								}

							}
							else
							{
								move(players[i], board, players, displayableBoard);
								moveVal += 1;
							}
						}
						else {
							move(players[i], board, players, displayableBoard);
							moveVal += 1;
						}

						// Checks to see if player is bankrupt
						if (players[i]->getBalance() < 0) {
							string ans;
							while (players[i]->getBalance() < 0 && ans != "n") {
								//string ans;
								cout << "\nYou are bankrupt\n";
								cout << "Would you like to mortgage your properties? (y/n): ";
								cin >> ans;
								if (ans == "y") {
									int answer;
									players[i]->getInventory();
									cout << "\nWhich one would you like to mortgage? : ";
									cin >> answer;
									players[i]->inv[answer - 1]->owned = 2;
									players[i]->addMoney(players[i]->inv[answer - 1]->value);
									cout << "\nYour balance is now " << players[i]->getBalance() << "\n";
								}

								else {
									players.erase(players.begin() + i);
								}
							}
						}
					}
					system("pause");
				}
			}

			// Player is in jail
			else {
				cout << "You are in jail.";
				cout << "\nYou have " << players[i]->getJailCards() << " get out of jail free cards";
				if (players[i]->getJailCards() >= 1) {
					string ans;
					cout << "Would you like to use a get out of jail free card? (y/n):";
					cin >> ans;
					if (ans == "y" || ans == "Y") {
						cout << "You are now out of jail.";
						cout << "\nYou must wait until your next turn to move";
						players[i]->setJail(0);
						players[i]->removeJailCard();
					}
					else {
						getOutOfJail(players, players[i], board);

					}
				}
				else {
					getOutOfJail(players, players[i], board);
				}
			}
		}

	}
	// Pause
	system("pause");
}


