# Min XOR value

Given an array of N integers, find the pair of integers in the array which have minimum XOR value. Report the minimum XOR value.

## Reference

<https://www.interviewbit.com/problems/min-xor-value/>

## Examples

```
Input 
0 2 5 7 
Output 
2 (0 XOR 2)
```

```
Input 
0 4 7 9 
Output 
3 (4 XOR 7)
```

## Constraints 

2 <= N <= 100 000  
0 <= A[i] <= 1 000 000 000

## Approaches

Obviously, in the given numbers, two consecutive pair has minimum XOR value rather than non-consecutive pairs.
If given numbers are sorted, it takes O(n) to find minmum XOR vaule, but if not, it will take O(nlogn) that includes sorting time.

## Code

```c
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
```
