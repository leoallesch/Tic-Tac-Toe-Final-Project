#include <iostream>
#include <vector>

using namespace std;

void printOptions() {
	cout << "Welcome to Tic Tac Toe!" << endl;
	cout << "Game Options: " << endl;
	cout << "1. Standard" << endl << "2. Misere Tic Tac Toe" << endl << "3. Gomoku" << endl
		<< "4. Wild Tic Tac Toe" << endl << "5. Order and Chaos" << endl << "6. Nokatu" << endl;
	cout << "Choose game to see description: ";
}

class Game {
public:
	int row = 0;
	int col = 0; 
	int num_boards = 0;
	string name;

	Game() {
		int choice;
		char play = ' ';
		while (play != 'y' && play != 'Y') {
			printOptions();
			cin >> choice;
			switch (choice) {
				case 1:
					name = "Standard";
					num_boards = 1;
					row = 3;
					col = 3;
					cout << "Standard Tic Tac Toe: a game in which two players seek in alternate turns to complete a row, a column, or a diagonal with either three O's or three X\'s drawn in the spaces of a grid of nine squares." << endl;
					break;
				case 2:
					name = "Misère";
					num_boards = 1;
					row = 3;
					col = 3;
					cout << "Misère Tic Tac Toe: Exactly the same as regular tic-tac-toe, but you win by forcing your opponent into getting three-in-a-row. Yes, you win by losing!" << endl;
					break;
				case 3:
					name = "Gomoku";
					num_boards = 1;
					row = 15;
					col = 15;
					cout << "Gomoku: The board is 15 x 15 and you must get exactly five-in-a-row to win. Six-in-a-row doesn\'t count!" << endl;
					break;
				case 4:
					name = "Wild";
					num_boards = 1;
					row = 3;
					col = 3;
					cout << "Wild Tic Tac Toe: Uses a standard board, but both players can play as X and O. First to make a three-in-a-row using either shape wins." << endl;
					break;
				case 5:
					name = "Order and Chaos";
					num_boards = 1;
					row = 6;
					col = 6;
					cout << "Order and Chaos: The board is a 6 x 6 grid. Both players can play as X and O. One person (Order) wants to get five-in-a-row of either shape. The other player (Chaos) tries to prevent any five-in-a-rows (so, Chaos wants a cat’s game)." << endl;
					break;
				case 6:
					name = "Nokato";
					num_boards = 3;
					cout << "Notakto: Played on three standard boards at once. Both players play as X. You can play on any of the boards on your turn. The first person to complete a three-in-a-row loses." << endl;
					break;
				default:
					cout << "Invalid option";
			}
			cout << "Would you like to play this version (Y/N)? ";
			cin >> play;
		}
	}
};

int main(void) {
	Game game;

	cout << game.name << endl << game.row << endl << game.col << endl << game.num_boards << endl;

	return 0;
}