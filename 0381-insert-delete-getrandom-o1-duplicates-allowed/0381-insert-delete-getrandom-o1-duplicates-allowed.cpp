class RandomizedCollection {
public:
    unordered_map<int,unordered_set<int>> mp; // num--> indices in array
    vector<int> v;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        v.push_back(val);
        mp[val].insert(v.size()-1);
        return mp[val].size() <=1;
    }
    
    bool remove(int val) {
        if(mp[val].size() == 0) return false;
        int index = *mp[val].begin();
        mp[val].erase(index);

        int num = v.back();
        int n = v.size()-1;
        swap(v[index],v[n]);
        mp[num].insert(index);
        mp[num].erase(v.size()-1);
        v.pop_back();
        return true;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */