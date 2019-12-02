class Solution {
private:
    vector<int>& num_array;
public:
    Solution(vector<int>& nums) : num_array(nums) {};
    
    int pick(int target) {
        int num = 0;
        for(int i : num_array){
            if(i == target) num++;
        }
        
        for(int i = 0; i < num_array.size(); i++){
            if(num_array[i] == target){
                if(rand()%num == 0) return i;
                num--;    
            }
        }
        return -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
