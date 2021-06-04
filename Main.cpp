#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

class TicTacToe {

	char symbol;
	std::vector<int> filled = {10};

public:
	bool gameover = false; //used later for escaping the main loop

	bool checkiffilled(int pos) { 
		for (int i : filled) {
			if (i == pos) {
				return false;
				break;
			}
		}
	}

	char board[5][5] = {
		{' ', '|', ' ', '|', ' '},
		{'-', '+', '-', '+', '-'},
		{' ', '|', ' ', '|', ' '},
		{'-', '+', '-', '+', '-'},
		{' ', '|', ' ', '|', ' '}
	};

	void buildBoard() {
		for (int r = 0; r <= 4; r++) {
			for (int c = 0; c <= 4; c++) {
				std::cout << board[r][c];
			};
			std::cout << "\n";
		};
	}

	void Move(int pos, std::string player) {

		
		if (player == "player") 
		{
			symbol = 'X';
		} else if (player == "CPU")
		{
			symbol = 'O';
		}

		//this is really dumb
		if (checkiffilled(pos) != false) {
			switch (pos) {
			case 1:
				board[0][0] = symbol;
				filled.push_back(pos);
				buildBoard();
				break;
			case 2:
				board[0][2] = symbol;
				filled.push_back(pos);
				buildBoard();
				break;
			case 3:
				board[0][4] = symbol;
				filled.push_back(pos);
				buildBoard();
				break;
			case 4:
				board[2][0] = symbol;
				filled.push_back(pos);
				buildBoard();
				break;
			case 5:
				board[2][2] = symbol;
				filled.push_back(pos);
				buildBoard();
				break;
			case 6:
				board[2][4] = symbol;
				filled.push_back(pos);
				buildBoard();
				break;
			case 7:
				board[4][0] = symbol;
				filled.push_back(pos);
				buildBoard();
				break;
			case 8:
				board[4][2] = symbol;
				filled.push_back(pos);
				buildBoard();
				break;
			case 9:
				board[4][4] = symbol;
				filled.push_back(pos);
				buildBoard();
				break;
			default:
				std::cout << "Not a valid number! Lose a turn!\n";
				break;
			};
		};

		std::cout << "******************\n";

	}

	void Play() {
		int play;
		std::cout << "Pick a position (1-9)\n";
		std::cin >> play;
		Move(play, "player");
		Checkwin("player", 'X');
	};

	void CPU() {
		int choice = rand() % 8 + 1; //Random choice from 1 to 9
		Move(choice, "CPU");
		Checkwin("CPU", 'O');
	}

	void Win(std::string player) {
		std::cout << player << " wins!\n";
		gameover = true;
	}


	void Checkwin(std::string player, char c) { //this is cancer
		if (board[0][0] == c && board[0][2] == c && board[0][4] == c) { //top row
			Win(player);
		}
		else if (board[2][0] == c && board[2][2] == c && board[2][4] == c) { //middle row
			Win(player);
		}
		else if (board[4][0] == c && board[4][2] == c && board[4][4] == c) { //bottom row
			Win(player);
		}
		else if (board[0][0] == c && board[2][0] == c && board[4][0] == c) { //left column
			Win(player);
		}
		else if (board[0][2] == c && board[2][2] == c && board[4][2] == c) { //middle column
			Win(player);
		}
		else if (board[0][4] == c && board[2][4] == c && board[4][4] == c) { //right column
			Win(player);
		}
		else if (board[0][0] == c && board[2][2] == c && board[4][4] == c) { //left-to-right diagonal
			Win(player);
		}
		else if (board[0][4] == c && board[2][2] == c && board[4][0] == c) {// right-to-left diagonal
			Win(player);
		};
	};

	
};


int main() {
	

	std::cout << "Welcome to my Tic Tac Toe game!\n" << "******************\n" << "Have fun! Or don't...\n";
	TicTacToe Test;
	Test.buildBoard();
	while (Test.gameover == false) {
		Test.Play();
		Test.CPU();
	};

	system("pause");


}