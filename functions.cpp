#include <iostream>
#include <cstdlib>
using namespace std;

// array for display cell numbers
static int num_arr[27] = { 1,2,3,4,5,6,7,8,9,
					10,11,12,13,14,15,16,17,18,
					19,20,21,22,23,24,25,26,27 };

char playerSym = 'X';
char comSym = 'O';
char defaultSym = '-';


// Q1 greeting
void greetAndInstruct() {
	
	char answer;

	// printing to the console
	cout << "Hello and welcome to the Tic-Tac-Toe challenge: Player against Computer." << endl;
	cout << "The board is numbered from 1 to 27 as per the following: \n" << endl;

	// display a board
	cout << num_arr[0] << " | " << num_arr[1] << " | " << num_arr[2] << "\t" << num_arr[9] << " | " << num_arr[10] << " | " << num_arr[11] << "\t" << num_arr[18] << " | " << num_arr[19] << " | " << num_arr[20] << endl;
	cout << "------------\t------------\t------------" << endl;
	cout << num_arr[3] << " | " << num_arr[4] << " | " << num_arr[5] << "\t" << num_arr[12] << " | " << num_arr[13] << " | " << num_arr[14] << "\t" << num_arr[21] << " | " << num_arr[22] << " | " << num_arr[23] << endl;
	cout << "------------\t------------\t------------" << endl;
	cout << num_arr[6] << " | " << num_arr[7] << " | " << num_arr[8] << "\t" << num_arr[15] << " | " << num_arr[16] << " | " << num_arr[17] << "\t" << num_arr[24] << " | " << num_arr[25] << " | " << num_arr[26] << endl;


	cout << "\nPlayer starts first. Simply input the number of the cell you want to occupy. Player¡¯s moveis marked with X. Computer¡¯s move is marked with O." << endl;

	// force player to choose
	while (true) {
		cout << "Start? (y/n):" << endl;
		cin >> answer;

		if (answer == 'n') {
			cout << "Quiting..." << endl;
			exit(0);
		}
		else if (answer == 'y') {
			cout << "Starting the game..." << endl;
			break;
		}
		else {
			cout << "Please press y/n" << endl;	// if they pressed other keys, continue to ask
		}
	}


}


// Q2 disply a board
void displayBoard(char board[]) {
	char sLine[13] = { "------------" };    // seperation line of length 12
	char sepe[4] = { " | " };							// seperator
	

	// patching for row and columns
	for (int c = 0; c<7; c=c+3) {
		// row
		for (int i = 0; i < 3; i++) {
			// column
			for (int j = 0; j < 3; j++) {

				// the actual index in the array
				int index = i * 9 + j + c;

				// if the board contains default value, print number, else print board
				if (board[index] == defaultSym) {
					cout << num_arr[index];
				}
				else {
					cout << " " << board[index] ;	
				}

				// give some space every 3 columns, otherwise give seperation symbol
				if (index % 3 == 2) {
					cout << "\t";
				}
				else {
					cout << sepe;
				}

				// at the end go to a new line, print the seperation line shwere necessary
				if (index == 20 || index == 23 || index == 26) {
					cout << endl;
					if (index!=26) {
						cout << sLine << "\t" << sLine << "\t" << sLine << endl;
					}
				}
			}
		}
	}

	cout << endl;
}


// Q3 check illegal & winner
	// check illegal cell number
bool checkIfLegal(int cellNbre, char board[]) {

	 // case1: out of bound	0~26		   case2: already occupied
	if ((cellNbre < 0 || cellNbre > 26) || (board[cellNbre]!=defaultSym)) {
		return false;
	}
	return true;
}


bool checkWinner(char board[]) {
	char winSym = defaultSym;
	bool isFull = true;		// will flip to false when there is no winning and it's not full
	// show who won the game, or tie

	// winning conditions
	
	// across different planes
	//check 1,10,19; 4, 13, 22.etc
	for (int j = 0; j < 9; j++) {
		/*cout << board[j];
		cout << board[j + 9];
		cout << board[j + 18];*/
		//cout << (board[j] == (board[j + 9]) && board[j]==board[j+18]) << endl;
		if ((board[j] == (board[j + 9]) && (board[j] == board[j + 18])) ) {
			if (board[j] != defaultSym) {
				winSym = board[j];
			}
		}
	}
	

	// check diagnals on the upper
	for (int i = 2; i < 9; i = i + 3) {
		if ((board[i] == board[i + 8]) && (board[i] == board[i + 16])) {
			if (board[i] != defaultSym) {
				winSym = board[i];
			}
		}
	}
	for (int i = 0; i < 7; i = i + 3) {
		if ((board[i] == board[i + 10]) && (board[i] == board[i + 20])) {
			if (board[i] != defaultSym) {
				winSym = board[i];
			}
		}
	}

	// check diagnals on the sides
	/*1,13,25; 
	  2,14,26;
	  3,15,27;*/
	for (int i = 0; i < 3; i++) {
		if ((board[i] == board[i + 12]) && (board[i] == board[i + 24])) {
			if (board[i] != defaultSym) {
				winSym = board[i];
			}
		}
	}

	/*7,13,19;
	  8,14,20;
	  9,15,21;*/
	for (int i = 6; i < 9; i++) {
		if ((board[i] == board[i + 6]) && (board[i] == board[i + 12])) {
			if (board[i] != defaultSym) {
				winSym = board[i];
			}
		}
	}
	
	
	// check diagnals in the middle , 1,14,27; 3,14,25; 7,14,21; 9,14,19;
	if ((board[0] == board[13]) && (board[0] == board[26])) {
		if (board[0] != defaultSym) {
			winSym = board[0];
		}
	}
	else if ((board[2] == board[13]) && (board[2] == board[24])) {
		if (board[2] != defaultSym) {
			winSym = board[2];
		}
	}
	else if ((board[6] == board[13]) && (board[6] == board[20])) {
		if (board[6] != defaultSym) {
			winSym = board[6];
		}
	}
	else if ((board[8] == board[13]) && (board[8] == board[18])) {
		if (board[8] != defaultSym) {
			winSym = board[8];
		}
	}
	

	// within the plane
	// for each plane
	
	for (int i = 0; i < 19; i=i+9) {
		
		//case1: check each row inside each plane
		for (int j = 0; j < 7 ; j=j+3) {	// for each row
			if ((board[i+j] == board[i+ j + 1]) && (board[i + j] == board[i + j + 2])) {
				if (board[i + j] != defaultSym) {
					winSym = board[i + j];
				}
			}
		}
	
		//case2: check each columns inside each plane
		for (int j = 0; j < 3; j++) {	// for each row
			if ((board[i + j] == board[i + j + 3]) && (board[i + j] == board[i + j + 6])) {
				if (board[i + j] != defaultSym) {
					winSym = board[i + j];
				}
			}
		}
	
		//case3: check the diagnals inside each plane  10,14,18    12,14,16
		// front
		for (int j = 0; j < 3; j = j+2) {	// for each row; j = 1 or 3 for the first square
			if (j == 0) {
				if ((board[i + j] == board[i + j + 4]) && (board[i + j] == board[i + j + 8])) {
					if (board[i + j] != defaultSym) {
						winSym = board[i + j];
					}
				}
			}
			else {
				if ((board[i + j] == board[i + j + 2]) && (board[i + j] == board[i + j + 4])) {
					if (board[i + j] != defaultSym) {
						winSym = board[i + j];
					}
				}
			}
		}

	}

	if (winSym == playerSym) {
		cout << "Player Won!" << endl;
		return true;
	}
	else if (winSym == comSym) {
		cout << "Computer Won!" << endl;
		return true;
	}
	else {
		//check if the board is full and if there is no winner, exit(0)
		for (int i = 0; i < 27; i++) {
			if (board[i] == defaultSym) {
				isFull = false;
			}
		}
	}

	if (isFull == true) {
		cout << "Player and Computer TIE!" << endl;
		exit(0);
	}

	

					
	return false;		// catch by the main and exit
}

// Q4 deciding for the computer
void computerMove(char board[]) {
	// since board will be checked before computer moved, so there is at least one place to go

	//first find a random empty space. If there is no place that will 
	// lead to the winning of either, place to here
	// 0~26
	int n = rand() % 27;

	// loop until finding a validate move
	while (checkIfLegal(n, board) == false) {
		n = rand() % 27;
	}

	// check next winning
	// ==========================================
	//char winSym = defaultSym;
	int nextComWin = -1;
	int nextPlayWin = -1;

	// winning conditions, any combination of winning conditions will matter
	// winning is more prioritized than blocking, but still saving nextPlayWin in case need to change strategies later
	// use the last position found that will be winning or blocking (not specified)

	// note: since it's not specified in the assignment what to do if we didn't find any place to block or win, 
	//       randomly select an empty position in this case.

	// across different planes
	//check 1,10,19; 4, 13, 22.etc

	for (int j = 0; j < 9; j++) {
		if ((board[j] == board[j + 9]) && (board[j + 18] == defaultSym)) {
			if (board[j] == comSym) {
				nextComWin = j + 18;
			}
			else if (board[j] == playerSym) {
				nextPlayWin = j + 18;
			}
		}
		else if ((board[j] == board[j + 18]) && (board[j + 9] == defaultSym)) {
			if (board[j] == comSym) {
				nextComWin = j + 9;
			}
			else if (board[j] == playerSym) {
				nextPlayWin = j + 9;
			}
		}
		else if ((board[j + 18] == board[j + 9]) && (board[j] == defaultSym)) {
			if (board[j + 18] == comSym) {
				nextComWin = j;
			}
			else if (board[j + 18] == playerSym) {
				nextPlayWin = j;
			}
		}

	}


	/* check diagnals 
						on planes
						front
						1,5,9;	  3,5,7;
						10,14,18; 12,14,16;
						19,23,27; 21,23,25;

						upper
						1,11,21;  3,11,19;
						4,14,24;  6,14,22;
						7,17,27;  9,17,25;

						side
						1,13,25; 7,13,19;
						2,14,26; 8,14,20;
						3,15,27; 9,15,21;	

						middle
						1,14,27; 3,14,25;			
						7,14,21; 9,14,19;
						*/
	// check diagnals on the upper


	for (int i = 2; i < 9; i = i + 3) {
		if ((board[i] == board[i + 8]) && (board[i + 16] == defaultSym)) {
			if (board[i] == comSym) {
				nextComWin = i + 16;
			}
			else if (board[i] == playerSym) {
				nextPlayWin = i + 16;
			}
		}
		else if ((board[i] == board[i + 16]) && (board[i + 8] == defaultSym)) {
			if (board[i] == comSym) {
				nextComWin = i + 8;
			}
			else if (board[i] == playerSym) {
				nextPlayWin = i + 8;
			}
		}
		else if ((board[i + 16] == board[i + 8]) && (board[i] == defaultSym)) {
			if (board[i + 16] == comSym) {
				nextComWin = i;
			}
			else if (board[i + 16] == playerSym) {
				nextPlayWin = i;
			}
		}
	}


	for (int i = 0; i < 7; i = i + 3) {
		if ((board[i] == board[i + 10]) && (board[i + 20] == defaultSym)) {
			if (board[i] == comSym) {
				nextComWin = i + 20;
			}
			else if (board[i] == playerSym) {
				nextPlayWin = i + 20;
			}
		}
		else if ((board[i] == board[i + 20]) && (board[i + 10] == defaultSym)) {
			if (board[i] == comSym) {
				nextComWin = i + 10;
			}
			else if (board[i] == playerSym) {
				nextPlayWin = i + 10;
			}
		}
		else if ((board[i + 10] == board[i + 20]) && (board[i] == defaultSym)) {
			if (board[i + 10] == comSym) {
				nextComWin = i;
			}
			else if (board[i + 10] == playerSym) {
				nextPlayWin = i;
			}
		}
	}

	// check diagnals on the sides
	/*side
		1, 13, 25; 
		2, 14, 26; 
		3, 15, 27;
		*/

	for (int i = 0; i < 3; i++) {
		if ((board[i] == board[i + 12]) && (board[i + 24] == defaultSym)) {
			if (board[i] == comSym) {
				nextComWin = i+24;
			}
			else if (board[i] == playerSym) {
				nextPlayWin = i+24;
			}
		}else if ((board[i] == board[i + 24]) && (board[i + 12] == defaultSym)) {
			if (board[i] == comSym) {
				nextComWin = i + 12;
			}
			else if (board[i] == playerSym) {
				nextPlayWin = i + 12;
			}
		}
		else if ((board[i + 12] == board[i + 24]) && (board[i] == defaultSym)) {
			if (board[i + 12] == comSym) {
				nextComWin = i;
			}
			else if (board[i + 12] == playerSym) {
				nextPlayWin = i;
			}
		}
	}

	/*	
	 * 	7, 13, 19;
		8, 14, 20;
		9, 15, 21;*/
	for (int i = 6; i < 9; i++) {
		if ((board[i] == board[i + 6]) && (board[i + 12] == defaultSym)) {
			if (board[i] == comSym) {
				nextComWin = i + 12;
			}
			else if (board[i] == playerSym) {
				nextPlayWin = i + 12;
			}
		}
		else if ((board[i] == board[i + 12]) && (board[i + 6] == defaultSym)) {
			if (board[i] == comSym) {
				nextComWin = i + 6;
			}
			else if (board[i] == playerSym) {
				nextPlayWin = i + 6;
			}
		}
		else if ((board[i + 6] == board[i + 12]) && (board[i] == defaultSym)) {
			if (board[i + 6] == comSym) {
				nextComWin = i;
			}
			else if (board[i + 6] == playerSym) {
				nextPlayWin = i;
			}
		}
	}


	// check diagnals in the middle , 1,14,27; 3,14,25; 7,14,21; 9,14,19;
	if ((board[0] == board[13]) && ( board[26]==defaultSym)) {
		if (board[0] == comSym) {
			nextComWin = 26;
		}
		else if (board[0] == playerSym) {
			nextPlayWin = 26;
		}
	}else if ((board[0] == board[26]) && (board[13] == defaultSym)) {
		if (board[0] == comSym) {
			nextComWin = 13;
		}
		else if (board[0] == playerSym) {
			nextPlayWin = 13;
		}
	}else if((board[26] == board[13]) && (board[0] == defaultSym)) {
		if (board[26] == comSym) {
			nextComWin = 0;
		}
		else if (board[26] == playerSym) {
			nextPlayWin = 0;
		}
	}

	else if ((board[2] == board[13]) && (board[24] == defaultSym)) {
		if (board[2] == comSym) {
			nextComWin = 24;
		}
		else if (board[2] == playerSym) {
			nextPlayWin = 24;
		}
	}
	else if ((board[2] == board[24]) && (board[13] == defaultSym)) {
		if (board[2] == comSym) {
			nextComWin = 13;
		}
		else if (board[2] == playerSym) {
			nextPlayWin = 13;
		}
	}
	else if ((board[13] == board[24]) && (board[2] == defaultSym)) {
		if (board[13] == comSym) {
			nextComWin = 2;
		}
		else if (board[13] == playerSym) {
			nextPlayWin = 2;
		}
	}

	else if ((board[6] == board[13]) && (board[20]==defaultSym)) {
		if (board[6] == comSym) {
			nextComWin = 20;
		}
		else if (board[6] == playerSym) {
			nextPlayWin = 20;
		}
	}
	else if ((board[6] == board[20]) && (board[13] == defaultSym)) {
		if (board[6] == comSym) {
			nextComWin = 13;
		}
		else if (board[6] == playerSym) {
			nextPlayWin = 13;
		}
	}
	else if ((board[20] == board[13]) && (board[6] == defaultSym)) {
		if (board[20] == comSym) {
			nextComWin = 6;
		}
		else if (board[20] == playerSym) {
			nextPlayWin = 6;
		}
	}



	else if ((board[8] == board[13]) && (board[18] == defaultSym)) {
		if (board[8] == comSym) {
			nextComWin = 18;
		}
		else if (board[8] == playerSym) {
			nextPlayWin = 18;
		}
	}
	else if ((board[8] == board[18]) && (board[13] == defaultSym)) {
		if (board[8] == comSym) {
			nextComWin = 13;
		}
		else if (board[8] == playerSym) {
			nextPlayWin = 13;
		}
	}
	else if ((board[18] == board[13]) && (board[8] == defaultSym)) {
		if (board[18] == comSym) {
			nextComWin = 8;
		}
		else if (board[18] == playerSym) {
			nextPlayWin = 8;
		}
	}

	

	// within the plane
	// for each plane
	for (int i = 0; i < 19; i = i + 9) {

		//case1: check each row inside each plane
		for (int j = 0; j < 7; j = j + 3) {	// for each row
			if ((board[i + j] == board[i + j + 1]) && (board[i + j + 2] == defaultSym)) {
				if (board[i + j] == comSym) {
					nextComWin = i + j + 2;
				}
				else if (board[i + j] == playerSym) {
					nextPlayWin = i + j + 2;
				}
			}
			else if ((board[i + j] == board[i + j + 2]) && (board[i + j + 1] == defaultSym)) {
				if (board[i + j] == comSym) {
					nextComWin = i + j + 1;
					//cout << "here: " << nextComWin;
				}
				else if (board[i + j] == playerSym) {
					nextPlayWin = i + j + 1;
				}
			}
			else if ((board[i + j + 1] == board[i + j + 2]) && (board[i + j] == defaultSym)) {
				if (board[i + j + 1] == comSym) {
					nextComWin = i + j;
				}
				else if (board[i + j + 1] == playerSym) {
					nextPlayWin = i + j;
				}
			}
		}
		//case2: check each columns inside each plane
		for (int j = 0; j < 3; j++) {	// for each row
			if ((board[i + j] == board[i + j + 3]) && (board[i + j + 6] == defaultSym)) {
				if (board[i + j] == comSym) {
					nextComWin = i + j + 6;
				}
				else if (board[i + j] == playerSym) {
					nextPlayWin = i + j + 6;
				}
			}
			else if ((board[i + j] == board[i + j + 6]) && (board[i + j + 3] == defaultSym)) {
				if (board[i + j] == comSym) {
					nextComWin = i + j + 3;
				}
				else if (board[i + j] == playerSym) {
					nextPlayWin = i + j + 3;
				}
			}
			else if ((board[i + j + 6] == board[i + j + 3]) && (board[i + j] == defaultSym)) {
				if (board[i + j + 6] == comSym) {
					nextComWin = i + j;
				}
				else if (board[i + j + 6] == playerSym) {
					nextPlayWin = i + j;
				}
			}
		}

		//case3: check the diagnals inside each plane
		for (int j = 0; j < 3; j = j + 2) {	// for each row; j = 1 or 3 for the first square

			if(j==0){
				// first diagnal (1, 4, 6)
				if ((board[i + j] == board[i + j + 4]) && (board[i + j + 8] == defaultSym)) {
					if (board[i + j] == comSym) {
						nextComWin = i + j + 8;
					}
					else if (board[i + j] == playerSym) {
						nextPlayWin = i + j + 8;
					}
				}
				else if ((board[i + j] == board[i + j + 8]) && (board[i + j + 4] == defaultSym)) {
					if (board[i + j] == comSym) {
						nextComWin = i + j + 4;
					}
					else if (board[i + j] == playerSym) {
						nextPlayWin = i + j + 4;
					}
				}
				else if ((board[i + j + 4] == board[i + j + 8]) && (board[i + j] == defaultSym)) {
					if (board[i + j + 4] == comSym) {
						nextComWin = i + j;
					}
					else if (board[i + j + 4] == playerSym) {
						nextPlayWin = i + j;
					}
				}
			}
			else {
				// the other diagnal (3, 5, 7)		0,2,4; 3,5,7
				if ((board[i + j] == board[i + j + 2]) && (board[i + j + 4] == defaultSym)) {
					if (board[i + j] == comSym) {
						nextComWin = i + j + 4;
					}
					else if (board[i + j] == playerSym) {
						nextPlayWin = i + j + 4;
					}
				}
				else if ((board[i + j] == board[i + j + 4]) && (board[i + j + 2] == defaultSym)) {
					if (board[i + j] == comSym) {
						nextComWin = i + j + 2;
					}
					else if (board[i + j] == playerSym) {
						nextPlayWin = i + j + 2;
					}
				}
				else if ((board[i + j + 2] == board[i + j + 4]) && (board[i + j] == defaultSym)) {
					if (board[i + j + 2] == comSym) {
						nextComWin = i + j;
					}
					else if (board[i + j + 2] == playerSym) {
						nextPlayWin = i + j;
					}
				}
			
			}
			
		}


	}
	//======================================================

	// find out if we found a position or not
	if (nextComWin != -1) {
		// found a place to win
		board[nextComWin] = comSym;
		return;
	}
	else if (nextPlayWin != -1) {
		// no place to win but found a place to block
		board[nextPlayWin] = comSym;
		return;
	}
	else {
		// no place to win and no place to block
		board[n] = comSym;
	}


}






















