class Solution {
public:
    void wiggleSort(vector<int>& nums) {
       vector<int> sortNum(nums);
        sort(sortNum.begin(), sortNum.end());
        int n = nums.size();
        int mid = (n + 1) / 2;
        int front = 0;
        int i = n - 1;
        while(i >= 0){
           if (i % 2 == 1) {
                nums[i] = sortNum[mid++];
            }
            else {
                nums[i] = sortNum[front++];
            }
            i--; 
        }
    }
};
