class Solution {
private:
    vector<int> array;
    vector<int> original;
public:
    Solution(vector<int>& nums) {
        array = nums;
        original = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        if(array.size() > 0){
            int i = rand() % array.size();
            int j = rand() % array.size();
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
        return array;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
