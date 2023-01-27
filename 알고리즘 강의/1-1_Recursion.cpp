#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void func_1(int k) {
	if (k <= 0) return;
	else {
		printf("Hello\n");
		func_1(k - 1);
	}
}

int func_2(int n) {
	if (n == 0) return 0;
	else return n + func_2(n - 1);
}

int factorial(int n) {
	if (n == 0) return 1;
	else return n * factorial(n - 1);
}

double power(double x, int n) {
	if (n == 0) return 1;
	else return x * power(x, n - 1);
}

int fibonacci(int n) {
	if (n < 2) return n;
	else return fibonacci(n - 1) + fibonacci(n - 2);
}

double gcd(int m, int n) {
	if (m < n) {
		int tmp = m; m = n; n = tmp;	// swap m and n
	}
	if (m % n == 0) return n;
	else
		return gcd(n, m % n);
}

int easy_gcd(int p, int q) {
	if (q == 0) return p;
	else
		return easy_gcd(q, p % q);
}

int main() {

	func_1(5);
	printf("\nfunc_2 : %d\n", func_2(4));
	printf("\nfactorial : %d\n", factorial(4));
	printf("\npower : %lf\n", power(4,3));
	printf("\nfibonacci : %d\n", fibonacci(10));
	printf("\ngcd : %lf\n", gcd(8, 6));
	printf("\neasy_gcd : %d\n", easy_gcd(8, 6));

}