# Maximum XOR using K numbers from 1 to n

Given an positive integer n and k. Find maximum xor of 1 to n using at most k numbers.  
Xor sum of 1 to n is defined as 1 ^ 2 ^ 3 ^ … ^ n.

## Examples

'''
Input :  n = 4, k = 3  
Output : 7  
Explanation  
Maximum possible xor sum is 1 ^ 2 ^ 4 = 7.  
'''

'''
Input : n = 11, k = 1  
Output : 11  
Explanation  
Maximum Possible xor sum is 11.  
'''

## Reference

<https://www.geeksforgeeks.org/maximum-xor-using-k-numbers-1-n/>

## Approaches

If k is 1, the maximum XOR must be n since, there is no numbers to XOR except n itself.  
However, if k is greater than or equal to 2, we can make the maximum xor which is consist of all 1s with any k.  
For instance, when n = 4, maximum xor is 111(2) = 7. And 111(2) can be one of 100(2) ^ 11(2), 100(2) ^ 10(2) ^ 1(2), etc..  
Also we can assume that k would be at most the number of 1 of maximum xor.  
To make the number with all 1s, find a number which closest to and greater than n but only MSB is 1, then subtract 1. e.g.) 1000(2) - 1 = 111(2)

## Code

```c
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
```