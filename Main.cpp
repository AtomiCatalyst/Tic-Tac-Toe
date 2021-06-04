#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> //for rand()

class TicTacToe {

	char symbol; //Initialize for X and O, I DON'T CARE THAT IT ISN'T INITIALIZED YET, COMPILER
	
	std::vector<int> filled = {10}; //When a spot is filled, adds the corresponding position value to this vector.
					//Idk why but compiler doesn't like it when this is empty so I put an impossible number in it
public:
	bool gameover = false; //used later for escaping the main loop

	bool checkiffilled(int pos) { //used for checking if a spot has 
		for (int i : filled) { //already been filled with X or O
			if (i == pos) {
				return false;
				break;
			}
		}
	}

	char board[5][5] = { //Le board
		{' ', '|', ' ', '|', ' '},
		{'-', '+', '-', '+', '-'},
		{' ', '|', ' ', '|', ' '},
		{'-', '+', '-', '+', '-'},
		{' ', '|', ' ', '|', ' '}
	};

	void buildBoard() { //read the function name lol
		for (int r = 0; r <= 4; r++) {
			for (int c = 0; c <= 4; c++) {
				std::cout << board[r][c];
			};
			std::cout << "\n";
		};
	}

	void Move(int pos, std::string player) { //defines what a "player" does in a move

		
		if (player == "player") //yes these are predetermined, who tf chooses "O" willingly anyways?
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
				board[0][0] = symbol; //adds X or O to board
				filled.push_back(pos); //adds the position of X/O to vector
				buildBoard(); //rebuilds the board with given symbol added
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
				std::cout << "Not a valid number! Lose a turn!\n"; //I couldn't figure out how to loop the function, sue me
				break;
			};
		};

		std::cout << "******************\n"; //fancy line cause fancy

	}

	void Play() { //Human interaction
		int play;
		std::cout << "Pick a position (1-9)\n";
		std::cin >> play;
		Move(play, "player");
		Checkwin("player", 'X');
	};

	void CPU() { //Computer does beep boop
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
	while (Test.gameover == false) { //loop I was talking about earlier
		Test.Play();
		Test.CPU();
	};

	system("pause"); //<--- Don't do this, this is bad, but as you can see, I don't care


}
