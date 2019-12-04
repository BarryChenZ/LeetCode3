class Solution {
public:
    int findNthDigit(int n) {
        // 超過時間
        // if(n < 10) return n;
        // int num = 10;
        // int i = 9;
        // int j = 1; //count 位數
        // while(i < n){
        //     if(num >= pow(10, j)) j++;
        //     i += j;
        //     num++;
        // }
        // num --; i -= j;
        // cout << num << " " << i;
        // int tmp = n - i;
        // vector<int> ans;
        // for(int k = 0; k < j; k++){
        //     ans.push_back(num % 10);
        //     num = num / 10;
        // }
        // return ans[ans.size() - tmp];
        int i = 1;
        long long s = 9;
        int pre = 0;
        
        while(n > s)
        {
            i++;
            pre = s;
            s += 9*pow(10, i-1)*i;
        }
        //從頭開始算 一個num算i - 1個位數
        int num = (n - pre - 1) / i + pow(10, i - 1);
        string temp = to_string(num);
        int pos = (n - pre - 1) % i;
        return temp[pos] - '0';
    }
};
