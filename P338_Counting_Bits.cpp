class Solution {
public:
    vector<int> countBits(int num) {
        if(num == 0) return {0};
        vector<int> ans;
        ans.push_back(0);
        int power_of_two = 1;
        for(int i = 1; i <= num; i++){
            if(i == power_of_two){
                ans.push_back(1 + ans[i - power_of_two]);
                power_of_two *= 2;
            }
            else{//2 ---> j-1
                ans.push_back(1 + ans[i - power_of_two/2]);
            }
        }
        return ans;
    }
};
