class RandomizedSet {
private: 
    unordered_map<int, int> m;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        m.clear();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m.find(val) != m.end()){
            return false;        
        }
        else{
            m[val] = val;
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(m.find(val) != m.end()){
            m.erase(val);
            return true;
        }
        else{
            return false;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int size = m.size();
        int randNum = rand() % size;
        auto iter = m.begin();
        advance(iter, randNum); 
        
        return iter->second;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
