class RandomizedCollection {
private:
    unordered_map<int, int> m;
    int k = 0;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        m.clear();
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        k++;
        if(m.find(val) != m.end()){
            m[val]++;
            return false;        
        }
        else{
            m[val] = 1;
            return true;
        }
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(m.find(val) != m.end()){
            if(m[val] != 1){
                m[val]--;
            }
            else{
                m.erase(val);
            }
            k--;
            return true;
        }
        else{
            return false;
        }
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int size = k;
        int randNum = rand() % k;
        unordered_map<int, int>::iterator iter;
        for(iter = m.begin(); iter != m.end(); iter++){
            int cur_size = iter->second;
            if((randNum - cur_size) < 0) break;
            randNum = randNum - cur_size;
        }
        return iter->first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
