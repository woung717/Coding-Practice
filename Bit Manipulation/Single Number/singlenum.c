#include <stdio.h>

int findSingle(int arr[], int n) {
	int ret = 0, i;

	for(i = 0; i < n; i++) {
		ret ^= arr[i];
	}

	return ret;
}

int main() {
	int single;
	int arr[5] = {1, 2, 2, 3, 1};

	if((single = findSingle(arr, 5)) == 3) 
		printf("#1 case : single number = %d\n", single);

	return 0;
}