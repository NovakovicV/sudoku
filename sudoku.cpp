#include <iostream>

void printBoard(int matrix[9][9]) {
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void getColumn(int *colArray, int *colNum, int matrix[9][9]) {
	for (int i = 0; i < 9; ++i) {
		colArray[i] = matrix[i][*colNum];
	}
} 

bool isEntryValid(int xPos, int yPos, int num, int matrix[9][9]) { 
	//Check if the number is in the row or the column 
	int col[9]; 
	getColumn(col, &xPos, matrix);

	int *row = matrix[yPos];
	
	bool entryIsValid = true;
	for (int i = 0; i < 9; ++i) {
		if (col[i] == num || row[i] == num) {
			entryIsValid = false;
			break;
		}
	}

	//Check if the number is in the square
	if (entryIsValid) {
		int xSquare = (xPos / 3) * 3;
		int ySquare = (yPos / 3) * 3;

		for (int y = ySquare; y < ySquare + 3; ++y) {
			for (int x = xSquare; x < xSquare + 3; ++x) {
				if (matrix[y][x] == num) {
					entryIsValid = false;
					break;
				}
			}
		}
	}

	return entryIsValid;
}


//This does not work, it is just a barebones example
int fillSudokuBoard(int matrix[9][9]) {
	bool boardFull = true;
	for (int y = 0; y < 9; ++y) {
		for (int x = 0; x < 9; ++x) {
			if (matrix[y][x] == 0) {
				boardFull = false;
				for (int posNum = 1; posNum < 10; ++posNum) {
					if (isEntryValid(x, y, posNum, matrix)) {
						matrix[y][x] = posNum;
						fillSudokuBoard(matrix);		
						matrix[y][x] = 0;
					}
				}
				return 0;
			}
		}
	}

	printBoard(matrix);
	std::cout << "Check for more solutions? Press Enter";
	std::cin.get();
	return 1;
}


int main (void) {
	int x, y, num;

	int matrix[9][9] = 
		{{0,2,0,0,1,6,0,3,0},
		 {0,0,5,3,0,0,0,0,4},
		 {0,0,9,8,0,0,2,0,1},
		 {0,0,1,5,3,0,0,8,0},
		 {5,0,6,2,0,1,7,0,3},
		 {0,3,0,0,6,4,1,0,0},
		 {1,0,3,0,0,8,4,0,0},
		 {7,0,0,0,0,9,3,0,0},
		 {0,6,0,1,7,0,0,2,0}};

	fillSudokuBoard(matrix);
}


