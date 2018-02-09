#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int minXOR(int arr[], int n) {
	int i;

	// assume that given numbers are not sorted 
	sort(arr, arr + n);

	int min = INT_MAX;
	int tmp = 0;

	for(i = 0; i < n - 1; i++) {
		tmp = arr[i] ^ arr[i - 1];
		min = (tmp <= min) ? tmp : min;
	}

	return min;
}

int main() {
	int min;

    int i[4] = {0, 2, 5, 7};
    int j[4] = {0, 4, 7, 9};

    if((min = minXOR(i, 4)) == 2)
        printf("Array i : minXOR = %d\n", min);
    if((min = minXOR(j, 4)) == 3)
        printf("Array j :  minXOR = %d\n", min);

	return 0; 
}