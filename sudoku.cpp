#include <iostream>

void printBoard(int matrix[9][9]) {
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main (void) {
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

   	printBoard(matrix);
	return 1;
}

