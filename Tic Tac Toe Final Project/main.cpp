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
	int playerTurn = rand() % 2 + 1;
	int state = 0;
	char shape;

	vector<vector<vector<char>>> boards;

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
					name = "Misere";
					num_boards = 1;
					row = 3;
					col = 3;
					cout << "Misere Tic Tac Toe: Exactly the same as regular tic-tac-toe, but you win by forcing your opponent into getting three-in-a-row. Yes, you win by losing!" << endl;
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
					name = "Order";
					num_boards = 1;
					row = 6;
					col = 6;
					cout << "Order and Chaos: The board is a 6 x 6 grid. Both players can play as X and O. One person (Order) wants to get five-in-a-row of either shape. The other player (Chaos) tries to prevent any five-in-a-rows (so, Chaos wants a cat’s game)." << endl;
					break;
				case 6:
					name = "Nokato";
					num_boards = 3;
					row = 3;
					col = 3;
					cout << "Notakto: Played on three standard boards at once. Both players play as X. You can play on any of the boards on your turn. The first person to complete a three-in-a-row loses." << endl;
					break;
				default:
					cout << "Invalid option";
			}
			cout << "Would you like to play this version (Y/N)? ";
			cin >> play;
		}


		for (int i = 0; i < num_boards; i++) {
			vector<vector<char>> temp_board;
			for (int j = 0; j < row; j++) {
				vector<char> t;
				for (int k = 0; k < col; k++) {
					t.push_back(' ');
				}
				temp_board.push_back(t);
			}
			boards.push_back(temp_board);
		}

		while (state == 0) {
			draw();
			turn();
		}
	}

	void draw() {
		system("CLS");
		cout << endl;
		for (int i = 0; i < num_boards; i++) {
			cout << "   ";
			for (int p = 1; p <= col; p++) {
				if (p > 9)
					cout << "  " << p << "  ";
				else
					cout << "   " << p << "  ";
			}
			cout << endl;

			cout << "   -";
			for (int p = 0; p < col * 6; p++)
				cout << "-";
			cout << endl;

			for (int j = 0; j < row; j++) {
				if (j >= 9)
					cout << j+1 << " ";
				else
					cout << " " << j + 1 << " ";

				for (int k = 0; k < col; k++) {
					cout << "|  " << boards[i][j][k] << "  ";
					
				}
				cout << "|" << endl << "   -";
				for (int p = 0; p < col * 6; p++)
					cout << "-";
				cout << endl;
			}
			cout << endl;
		}
	}

	void turn() {
		int bi, ri, ci;
		bi = 0;

		cout << "Player " << playerTurn << "'s turn" << endl;
		if (num_boards > 1) {
			cout << "Input board number (First board = 1): ";
			cin >> bi;
			bi--;
		}

		if (name == "Wild" || name == "Order") {
			cout << "Input shape (X or O): ";
			cin >> shape;
		}

		cout << "Input the row: ";
		cin >> ri;
		cout << "Input the column: ";
		cin >> ci;

		ci--;
		ri--;

		if (boards[bi][ri][ci] == ' ') {
			if (name == "Wild" || name == "Order") {
				boards[bi][ri][ci] = shape;
			}
			else if (name == "Nokato") {
				boards[bi][ri][ci] = 'X';
			}
			else {
				if (playerTurn == 1)
					boards[bi][ri][ci] = 'X';
				else if (playerTurn == 2)
					boards[bi][ri][ci] = 'O';
			}

			state = checkBoard();
			switch (state) {
			case 0:
				playerTurn = (playerTurn % 2) + 1;
				break;
			case 1:
				draw();
				cout << "Player 1 wins.";
				break;
			case 2:
				draw();
				cout << "Player 2 wins.";
				break;
			case 3:
				draw();
				cout << "Tie game.";
				break;
			}
		}
	}

	int checkBoard() {
		state = 0;
		bool full = true;
		if (name == "Standard" || name == "Misere" || name == "Wild") {
			for (int i = 0; i < row; i++) {
				if ((boards[0][i][0] == 'X') && (boards[0][i][1] == 'X') && (boards[0][i][2] == 'X'))
					state = 1;
				else if ((boards[0][i][0] == 'O') && (boards[0][i][1] == 'O') && (boards[0][i][2] == 'O'))
					state = 2;
				else if ((boards[0][0][i] == 'X') && (boards[0][1][i] == 'X') && (boards[0][2][i] == 'X'))
					state = 1;
				else if ((boards[0][0][i] == 'O') && (boards[0][1][i] == 'O') && (boards[0][2][i] == 'O'))
					state = 2;
			}

			if ((boards[0][0][0] == 'X') && (boards[0][1][1] == 'X') && (boards[0][2][2] == 'X'))
				state = 1;
			else if ((boards[0][0][0] == 'O') && (boards[0][1][1] == 'O') && (boards[0][2][2] == 'O'))
				state = 2;
			else if ((boards[0][0][2] == 'X') && (boards[0][1][1] == 'X') && (boards[0][2][0] == 'X'))
				state = 1;
			else if ((boards[0][0][2] == 'O') && (boards[0][1][1] == 'O') && (boards[0][2][0] == 'O'))
				state = 2;
			
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					if (boards[0][i][j] == ' ')
						full = false;
				}
			}

			if (name == "Misere") {
				if (state == 1)
					state = 2;
				else if (state == 2)
					state = 1;
			}

			if (name == "Wild") {
				if (state == 1 || state == 2)
					state = playerTurn;
			}

			if (full && state == 0)
				state = 3;
		}
		else if (name == "Gomoku" || name == "Order") {
			int xCount = 0;
			int oCount = 0;
			for (int r = 0; r < row; r++) { // Check columns
				xCount = 0;
				oCount = 0;
				for (int c = 0; c < col; c++) {
					if (xCount == 5) {
						if (boards[0][r][c] == 'X')
							xCount = 0;
					}
					else {
						if (boards[0][r][c] == 'X')
							xCount++;
						else
							xCount = 0;
					}

					if (oCount == 5) {
						if (boards[0][r][c] == 'O')
							oCount = 0;
					}
					else {
						if (boards[0][r][c] == 'O')
							oCount++;
						else
							oCount = 0;
					}

				}
					if (xCount == 5){
						if (name == "Order")
							return playerTurn;
						return state = 1;
					}
					else if (oCount == 5) {
						if (name == "Order")
							return playerTurn;
						return state = 1;
					}
			}

			for (int c = 0; c < col; c++) { // check rows
				xCount = 0;
				oCount = 0;
				for (int r = 0; r < row; r++) {
					if (xCount == 5) {
						if (boards[0][r][c] == 'X')
							xCount = 0;
					}
					else {
						if (boards[0][r][c] == 'X')
							xCount++;
						else
							xCount = 0;
					}

					if (oCount == 5) {
						if (boards[0][r][c] == 'O')
							oCount = 0;
					}
					else {
						if (boards[0][r][c] == 'O')
							oCount++;
						else
							oCount = 0;
					}

				}
				if (xCount == 5) {
					if (name == "Order")
						return playerTurn;
					return state = 1;
				}
				else if (oCount == 5) {
					if (name == "Order")
						return playerTurn;
					return state = 1;
				}
			}

			for (int c = 0; c < col; c++) {
				int i = 0;
				int j = c;
				xCount = 0;
				oCount = 0;
					
				while ((i < row) && (j < col)) { // check top down diagonals
					if (xCount == 5) {
						if (boards[0][i][j] == 'X') {
							xCount = 0;
							i = row;
							j = col;
						}
						else {
							if (name == "Order")
								return playerTurn;
							return state = 1;
						}
					}
					else {
						if (boards[0][i][j] == 'X')
							xCount++;
						else {
							xCount = 0;
							i = row;
							j = col;
						}
					}
					i = i + 1;
					j = j + 1;
				}

				i = 0;
				j = c;

				while ((i < row) && (j < col)) {
					if (oCount == 5) {
						if (boards[0][i][j] == 'O') {
							oCount = 0;
							i = row;
							j = col;
						}
						else {
							if (name == "Order")
								return playerTurn;
							return state = 2;
						}
					}
					else {
						if (boards[0][i][j] == 'O')
							oCount++;
						else {
							oCount = 0;
							i = row;
							j = col;
						}
					}
					i = i + 1;
					j = j + 1;
				}
			}

			for (int r = 0; r < row; r++) {
				int i = r;
				int j = 0;
				xCount = 0;
				oCount = 0;

				while ((i < row) && (j < col)) { // check top down diagonals
					if (xCount == 5) {
						if (boards[0][i][j] == 'X') {
							xCount = 0;
							i = row;
							j = col;
						}
						else {
							if (name == "Order")
								return playerTurn;
							return state = 1;
						}
					}
					else {
						if (boards[0][i][j] == 'X')
							xCount++;
						else {
							xCount = 0;
							i = row;
							j = col;
						}
					}
					i = i + 1;
					j = j + 1;
				}

				i = r;
				j = 0;

				while ((i < row) && (j < col)) {
					if (oCount == 5) {
						if (boards[0][i][j] == 'O') {
							oCount = 0;
							i = row;
							j = col;
						}
						else {
							if (name == "Order")
								return playerTurn;
							return state = 2;
						}
					}
					else {
						if (boards[0][i][j] == 'O')
							oCount++;
						else {
							oCount = 0;
							i = row;
							j = col;
						}
					}
					i = i + 1;
					j = j + 1;
				}
			}

			for (int c = 0; c < col; c++) {
				int i = 0;
				int j = c;
				xCount = 0;
				oCount = 0;

				while ((i > 0) && (j < col)) { // check bottom up diagonals
					if (xCount == 5) {
						if (boards[0][i][j] == 'X') {
							xCount = 0;
							i = 0;
							j = col;
						}
						else {
							if (name == "Order")
								return playerTurn;
							return state = 1;
						}
					}
					else {
						if (boards[0][i][j] == 'X')
							xCount++;
						else {
							xCount = 0;
							i = row;
							j = col;
						}
					}
					i = i - 1;
					j = j + 1;
				}

				i = 0;
				j = c;

				while ((i > 0) && (j < col)) {
					if (oCount == 5) {
						if (boards[0][i][j] == 'O') {
							oCount = 0;
							i = 0;
							j = col;
						}
						else {
							if (name == "Order")
								return playerTurn;
							return state = 2;
						}
					}
					else {
						if (boards[0][i][j] == 'O')
							oCount++;
						else {
							oCount = 0;
							i = 0;
							j = col;
						}
					}
					i = i - 1;
					j = j + 1;
				}
			}

			for (int r = 0; r < row; r++) {
				int i = r;
				int j = 0;
				xCount = 0;
				oCount = 0;

				while ((i > 0) && (j < col)) { // check bottom up diagonals
					if (xCount == 5) {
						if (boards[0][i][j] == 'X') {
							xCount = 0;
							i = 0;
							j = col;
						}
						else {
							if (name == "Order")
								return playerTurn;
							return state = 1;
						}
					}
					else {
						if (boards[0][i][j] == 'X')
							xCount++;
						else {
							xCount = 0;
							i = row;
							j = col;
						}
					}
					i = i - 1;
					j = j + 1;
				}

				i = r;
				j = 0;

				while ((i > 0) && (j < col)) {
					if (oCount == 5) {
						if (boards[0][i][j] == 'O') {
							oCount = 0;
							i = 0;
							j = col;
						}
						else {
							if (name == "Order")
								return playerTurn;
							return state = 2;
						}
					}
					else {
						if (boards[0][i][j] == 'O')
							oCount++;
						else {
							oCount = 0;
							i = 0;
							j = col;
						}
					}
					i = i - 1;
					j = j + 1;
				}
			}

			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					if (boards[0][i][j] == ' ')
						full = false;
				}
			}

			if (full && state == 0)
				return state = 3;

		}
		else if (name == "Nokato") {
			for (int b = 0; b < num_boards; b++) {
				for (int i = 0; i < row; i++) {
					if ((boards[b][i][0] == 'X') && (boards[b][i][1] == 'X') && (boards[b][i][2] == 'X'))
						return state = (playerTurn % 2) + 1;
					else if ((boards[0][0][i] == 'X') && (boards[0][1][i] == 'X') && (boards[0][2][i] == 'X'))
						return state = (playerTurn % 2) + 1;
				}
				if ((boards[b][0][0] == 'X') && (boards[b][1][1] == 'X') && (boards[b][2][2] == 'X'))
					return state = (playerTurn % 2) + 1;
				else if ((boards[0][0][2] == 'X') && (boards[0][1][1] == 'X') && (boards[0][2][0] == 'X'))
					return state = (playerTurn % 2) + 1;

				for (int i = 0; i < row; i++) {
					for (int j = 0; j < col; j++) {
						if (boards[0][i][j] == ' ')
							full = false;
					}
				}
			}

			if (full && state == 0)
				state = 3;
		}


		return state;
	}

};

int main(void) {
	char play = 'y';
	do {
		cout << "================" << endl;
		Game game;
		cout << endl << "================" << endl << "Would you like to play again(Y / N) ? : ";
		cin >> play;
	} while (play == 'y' || play == 'Y');

	return 0;
}