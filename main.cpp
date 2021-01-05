// 322_A1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "functions.cpp"
using namespace std;

char board[27] = 		// default board template to copy from
{ 
'-','-','-', 
'-','-','-', 
'-','-','-', 

'-','-','-', 
'-','-','-', 
'-','-','-', 

'-','-','-', 
'-','-','-', 
'-','-','-'
};

int main()
{
	srand(time(NULL));		// seed the random generator for the move
							/* note: the move will be random if there is no winner
									for the next move since it's not specified
									in the assignment
							*/
	
	greetAndInstruct();

	// user inputs
	int playerMove=-99;
	char again;

	char board_cur[27];		//copy an array for play so that board can be initialized again
	for (int i = 0; i < 27; i++) {
		board_cur[i] = board[i];
	}

	//enter loop until exit
	while (true) {
		
		
		// player round
		//get player move
		cout << "Please select a cell: " << endl;;
		
		//check validity, force selection
		while ((!checkIfLegal((playerMove-1), board_cur))) {
			
			// check if input is an integer
			if(!(cin >> playerMove)){	
				cout << "Please enter an integer: " << endl;
				cin.clear();
				cin.ignore(1000,'\n');
				playerMove = -99;	// reset to a impossible value
				continue;
			}
			
			cout << "Cell already occupied or integer out of range." << endl << "please select another integer from 1 to 27: " << endl;
			cin.clear();
			cin.ignore(1000,'\n');
		}

		board_cur[playerMove-1] = playerSym;
		displayBoard(board_cur);
		if(checkWinner(board_cur)){
			displayBoard(board_cur);
			cout << "Do you want to play again? y to continus, any key to exit" << endl;
			cin >> again;
			if (again == 'y') {
				for (int i = 0; i < 27; i++) {
					board_cur[i] = board[i];
				}
				continue;
			}
			else {
				exit(0);
			}
		}

		// computer round
		cout << "Computer's Round: " << endl;
		computerMove(board_cur);
		displayBoard(board_cur);

		if (checkWinner(board_cur)) {
			cout << "Do you want to play again? y to continus, any key to exit" << endl;
			cin >> again;
			if (again == 'y') {
				for (int i = 0; i < 27; i++) {
					board_cur[i] = board[i];
				}
				continue;
			}
			else {
				exit(0);
			}
		}

		// go to next player round
	}

	

}
