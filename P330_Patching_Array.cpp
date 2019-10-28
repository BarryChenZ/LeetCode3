class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long miss = 1;
        int res = 0;
        int i = 0;
        while(miss <= n){
            if(i < nums.size() && nums[i] <= miss){
                miss += nums[i];
                i++;
            }
            else{
                miss += miss;
                res++;
            }
        }
        return res;
    }
};

//從1開始試，如果nums[i] <= miss 就是可以表達(sorted)
//找到miss無法表達 就miss + miss (意思是加入miss值, res + 1)
//直到miss >= n 結束
