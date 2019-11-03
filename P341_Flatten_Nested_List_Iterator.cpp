/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    deque<int> ourQueue_;
    NestedIterator(vector<NestedInteger> &nestedList) {
            addAll(nestedList);
    }
    void addAll(vector<NestedInteger>& nestedlist){
        for(auto& entry : nestedlist){
            if(entry.isInteger()){
                ourQueue_.push_back(entry.getInteger());
            }
            else{
                addAll(entry.getList());
            }
        }
        return;
    }
    
    int next() {
        int result = ourQueue_.front();
        ourQueue_.pop_front();
        return result;
    }

    bool hasNext() {
        return !ourQueue_.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
