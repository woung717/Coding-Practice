/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*The structure of the class is as follows 
class LRUCache
{
public:
    LRUCache(int );
    int get(int );
    void set(int , int );
};*/
/*You are required to complete below methods */
/*Inititalize an LRU cache with size N */

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
        cache[x].age = ageCounter++;
        
        return cache[x].value;
    } 
    
    return -1;
}