#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* cols;
int N;



bool promising(int level) {
	for (int i = 1; i < level; i++) {
		if (cols[i] == cols[level]) {
			return false;
		}
		else if(level-i==abs(cols[level]-cols[i])) {
			return false;
		}
		return true;
	}
}

bool queens(int level) {
	if (!promising(level)) return false;
	else if (level == N) {
		for (int i = 1; i <= N; i++)
			printf("(%d, %d)\n ", i, cols[i]);
		return true;
	}
	for (int i = 1; i <= N; i++) {
		cols[level + 1] = i;
		if (queens(level + 1))	return true;
	}
	return false;
}


//int promising(int i)    // 유망한지 체크 
//{
//	int k = 1;
//	while (k < i)
//	{
//		if (cols[i] == cols[k] || abs(cols[i] - cols[k]) == abs(i - k))    // 상하좌우, 대각선 상에 있는 지 
//			return 0;
//		k++;
//	}
//	return 1;
//}

//void queens(int level)
//{
//	int j;
//
//	if (promising(level))    // 유망하다면  
//	{
//		if (level == N)    // 마지막 행까지 선택이 끝났다면 
//		{
//			print();    // 퀸의 위치 출력 
//			return;
//		}
//		else    // 아직 끝나지 않았다면 
//		{
//			for (j = 1; j <= N; j++)    // 모든 열 탐색 
//			{
//				cols[level + 1] = j;
//				queens(level + 1);
//			}
//		}
//	}
//
//}




int main() {
	
	printf("Input N: ");
	scanf("%d", &N);
	cols = (int*)malloc(sizeof(int) * (N + 1));
	
	queens(0);
	printf("No solution");
	

}