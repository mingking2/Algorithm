#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

const int PATHWAY_COLOUR = 0;		// white
const int WALL_COLOUR = 1;		// blue
const int BLOCKED_COLOUR = 2;		// red
const int PATH_COLOUR = 3;		// green

int N = 8;
int maze[8][8] = {
		{0,0,0,0,0,0,0,1},
		{0,1,1,0,1,1,0,1},
		{0,0,0,1,0,0,0,1},
		{0,1,0,0,1,1,0,0},
		{0,1,1,1,0,0,1,1},
		{0,1,0,0,0,1,0,1},
		{0,0,0,1,0,0,0,1},
		{0,1,1,1,0,1,0,0}
};

void printMaze() {
	printf("\n----- Maze -----\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", maze[i][j]);
		}
		printf("\n");
	}
}

bool findMazePath(int x, int y) {
	if (x < 0 || y < 0 || x >= N || y >= N)
		return false;
	else if (maze[x][y] != PATHWAY_COLOUR)
		return false;
	else if (x == N - 1 && y == N - 1) {
		maze[x][y] = PATH_COLOUR;
		return true;
	}
	else {
		maze[x][y] = PATH_COLOUR;
		if (findMazePath(x - 1, y) || findMazePath(x, y + 1) || findMazePath(x + 1, y) || findMazePath(x, y - 1)) {
			return true;
		}
		maze[x][y] = BLOCKED_COLOUR;
		return false;
	}
}

int main() {
	printMaze();
	findMazePath(0,0);
	printMaze();

}