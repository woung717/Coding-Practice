# LRU Cache

The task is to design and implement methods of an LRU cache. The class has two methods get and set which are defined as follows.  
&nbsp;&nbsp;**get(x)**   : Gets the value of the key x if the key exists in the cache otherwise returns -1  
&nbsp;&nbsp;**set(x,y)** : inserts the value if the key x is not already present. If the cache reaches its capacity it should invalidate the least recently used item before inserting the new item.  
In the constructor of the class the size of the cache should be intitialized.  

**Input:**  
The first line of input contain an integer T denoting the no of test cases. Then T test case follow. Each test case contains 3 lines. The first line of input contains an integer N denoting the capacity of the cache and then in the next line is an integer Q denoting the no of queries Then Q queries follow. A Query can be of two types.  
**1. SET x y** : sets the value of the key x with value y  
**2. GET x** : gets the key of x if present else returns -1.  

**Output:**  
For each test case in a new line output will be space separated values of the query.  

## Contraints

```  
1 <= T <= 100 
1 <= N <= 10 
1 <= Q <= 100
```

## Examples

```
Input
2
2
2
SET 1 2 GET 1
2
7
SET 1 2 SET 2 3 SET 1 5 SET 4 5 SET 6 7 GET 4 GET 1

Output
2
5 -1
```

## Approaches

According to the mechanism of LRU Caching algorithm, update age counter on every accesses (set, get). When the cache is full, replace least recent value (lowest age) to input.
If the key is exist, value and its age should be updated.

## Code 

```cpp
typedef struct CacheContent {
    int value;
    int age;
} CacheContent;

int ageCounter;
int cacheMax;

map<int, CacheContent> cache;

LRUCache::LRUCache(int N)
{
    ageCounter = 0;
    cacheMax = N;
    
    cache.clear();
}

/*Sets the key x with value y in the LRU cache */
void LRUCache::set(int x, int y) 
{
    CacheContent cont;
    
    cont.value = y;
    cont.age = ageCounter++;
    
    if(cache.find(x) == cache.end()) {  // not found
        if(cache.size() >= cacheMax) {
            int minAge = INT_MAX, minKey = 0;
            
            map<int, CacheContent>::iterator i;
            
            for(i = cache.begin(); i != cache.end(); i++) {
                if(i->second.age < minAge) {
                    minAge = i->second.age;
                    minKey = i->first;
                }
            }
            
            cache.erase(minKey);
        }
    }
    
    cache[x] = cont;
}

/*Returns the value of the key x if 
present else returns -1 */
int LRUCache::get(int x)
{
    if(cache.find(x) != cache.end()) {  // exists
        int ret = cache[x].value;
        
        cache[x].age = ageCounter++;
        
        return ret;
    } 
    
    return -1;
}

```