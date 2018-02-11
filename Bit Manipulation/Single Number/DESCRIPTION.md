# Single Number 

Given an array of integers, every element appears twice except for one. Find that single one.  

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

## Examples

```
Input : [1 2 2 3 1]
Output : 3
```

## Reference

<https://www.interviewbit.com/problems/single-number/>

## Approaches

Xor twice with same number removes first number from the result. So, If we xor all  the number in array, only the number which couldn't be xored twice will be leave as result. 

## Code

```c
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
```
