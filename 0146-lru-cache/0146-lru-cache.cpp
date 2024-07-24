class LRUCache {
public:
    list<int> dll;
    map<int,pair<list<int>::iterator,int>> mp;
    int n;
    LRUCache(int capacity) {
        n=capacity;
    }
    void makeRecentlyUsed(int key){
        dll.erase(mp[key].first);

        dll.push_front(key);// make recently used

        mp[key].first = dll.begin();
    }
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        makeRecentlyUsed(key);
        return mp[key].second;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            mp[key].second =value;
            makeRecentlyUsed(key);
            return;
        }
        dll.push_front(key);
        mp[key] = {dll.begin(),value};
        n--;
        if(n<0)
        {
            int deleteKey = dll.back();
            mp.erase(deleteKey);
            dll.pop_back();
            n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */