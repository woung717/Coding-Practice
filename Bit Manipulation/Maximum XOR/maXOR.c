#include <stdio.h>

int maXOR(int n, int k) {
	int i = 0;

	if(k == 1) return n;

	while(i <= n) i <<= 1;

	return i - 1; 
}

int main() {
	int max;

	if((max = maXOR(4, 3)) == 7)
		printf("n = %d, k = %d, maxXOR = %d\n", 4, 3, max);
	if((max = maXOR(11, 1)) == 11)
		printf("n = %d, k = %d, maxXOR = %d\n", 11, 1, max);

	return 0;
}