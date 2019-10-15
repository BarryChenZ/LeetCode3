class NumArray {
public:
    vector<int> sum;
    NumArray(vector<int>& nums) {
        int tmp = 0;
        for(int i = 0; i < nums.size(); i++){
            tmp += nums[i];
            sum.push_back(tmp);
        }
    }
    
    void update(int i, int val) {
        //sum[i] - sum[i - 1] =  nums[i]
        int old = (i == 0)? sum[i] : sum[i] - sum[i - 1];
        for(int j = i; j < sum.size(); j++){
            sum[j] = sum[j] - old + val;
        }
    }
    
    int sumRange(int i, int j) {
        int num = (i == 0)? 0 : sum[i - 1];
        return sum[j] - num;
    }
};
