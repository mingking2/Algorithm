#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printInBinary(int n) {
	if (n < 2) printf("%d",n);
	else {
		printInBinary(n / 2);
		printf("%d", n % 2);
	}
}

int sum(int n, int data[]) {
	if (n <= 0) return 0;
	else return sum(n - 1, data) + data[n - 1];
}

int main() {
	int data[] = { 1,2,3,4,5 };

	printf("printInBinary : ");
	printInBinary(10);
	printf("\nsum : %d\n",sum(5,data));

}