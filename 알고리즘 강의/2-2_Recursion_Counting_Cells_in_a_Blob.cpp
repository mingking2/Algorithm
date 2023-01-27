#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

const int BACKGROUND_COLOR = 0;
const int IMAGE_COLOR = 1;
const int ALREADY_COUNTED = 2;

int N = 8;
int count = 0;
int grid[8][8] = {
		{1,0,0,0,0,0,0,1},
		{0,1,1,0,0,1,0,0},
		{1,1,0,0,1,0,1,0},
		{0,0,0,0,0,1,0,0},
		{0,1,0,1,0,1,0,0},
		{0,1,0,1,0,1,0,0},
		{1,0,0,0,1,0,0,1},
		{0,1,1,0,0,1,1,1}
};

void printGrid() {
	printf("\n----- Grid -----\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", grid[i][j]);
		}
		printf("\n");
	}
	printf("\n count = %d\n",count);
}

int countCells(int x, int y) {
	
	if (x < 0 || x >= N || y < 0 || y >= N)
		return 0;
	else if (grid[x][y] != IMAGE_COLOR)
		return 0;
	else {
		grid[x][y] = ALREADY_COUNTED;
		count++;
		return 1 + countCells(x - 1, y + 1) + countCells(x, y + 1)
			+ countCells(x + 1, y + 1) + countCells(x - 1, y)
			+ countCells(x + 1, y) + countCells(x - 1, y - 1)
			+ countCells(x, y - 1) + countCells(x + 1, y - 1);
	}
}

int main() {
	int a, b;
	printGrid();
	while (1) {
		scanf("%d %d", &a, &b);
		countCells(a, b);
		printGrid();
		count = 0;
	}
	
}