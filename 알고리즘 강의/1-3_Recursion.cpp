#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>

int search_for(int data[], int n, int target) {
	for (int i = 0; i < n; i++) {
		if (data[i] == target)
			return i;
	}
	return -1;
}

int search(int data[], int begin, int end, int target) {
	if (begin > end) return -1;
	else if (target == data[begin]) return begin;
	else return search(data, begin + 1, end, target);
}

int search_re(int data[], int begin, int end, int target) {
	if (begin > end) return -1;
	else if (target == data[end]) return end;
	else return search_re(data, begin, end - 1, target);
}

int search_mid(int data[], int begin, int end, int target) {
	if (begin > end) return -1;
	else {
		int middle = (begin + end) / 2;
		if (data[middle] == target) return middle;
		int index = search_mid(data, begin, middle - 1, target);
		if (index != -1) return index;
		else return search_mid(data, middle + 1, end, target);
	}
}

int findMax(int data[], int begin, int end) {
	if (begin == end) return data[begin];
	else return fmax(data[begin], findMax(data, begin + 1, end));
}

int findMax_ver(int data[], int begin, int end) {
	if (begin == end) return data[begin];
	else {
		int middle = (begin + end) / 2;
		int max1 = findMax_ver(data, begin, middle);
		int max2 = findMax_ver(data, middle + 1, end);
		return fmax(max1, max2);
	}
}

int binarySearch(char* items[], char* target, int begin, int end) {
	if (begin > end) return -1;
	else {
		int middle = (begin + end) / 2;
		int compResult = strcmp(target, items[middle]);
		if (compResult == 0) return middle;
		else if (compResult < 0) return binarySearch(items, target, begin, middle - 1);
		else return binarySearch(items, target, middle + 1, end);
	}
}

int main() {
	int data[] = { 1,2,3,4,5,6,7,8,9,10 };


	printf("\nsearch_for : %d\n", search_for(data, 10, 9));
	printf("\nsearch : %d\n", search(data, 0, 10, 9));
	printf("\nsearch_re : %d\n", search_re(data, 0, 10, 9));
	printf("\nsearch_mid : %d\n", search_mid(data, 0, 10, 9));
	printf("\nfindMax : %d\n", findMax(data, 0, 9));
	printf("\nfindMax_ver : %d\n", findMax_ver(data, 0, 9));
	//printf("\nbinarySearch : %s\n", binarySearch(items, target, 0, 6));

}