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

int cacheMax;

list<int> recentMap;
map<int, int> cache;

LRUCache::LRUCache(int N)
{
    cacheMax = N;
    
    recentMap.clear();
    cache.clear();
}

/*Sets the key x with value y in the LRU cache */
void LRUCache::set(int x, int y) 
{
    if(cache.find(x) != cache.end()) {  // update case
        recentMap.remove(x);    
    } else {    // insert case
        if(cache.size() >= cacheMax) {
            cache.erase(recentMap.front());
            recentMap.pop_front();
        }
    }

    recentMap.push_back(x);
    cache[x] = y;
}

/*Returns the value of the key x if 
present else returns -1 */
int LRUCache::get(int x)
{
    if(cache.find(x) != cache.end()) {  // exists
        recentMap.remove(x);
        recentMap.push_back(x);

        return cache[x];
    } 
    
    return -1;
}