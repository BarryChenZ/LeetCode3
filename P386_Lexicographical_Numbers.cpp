class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        dfs(result, 0, n);
        return result;
    }
    void dfs(vector<int>& result, int num, int n){
        int j = 0;
        if(num == 0){
            num++;
            j++;
        }
        while(j < 10){
            if(num <= n) {
                result.push_back(num);
            }
            else{
                break;
            }
            
            dfs(result, num * 10, n);
            num++;
            j++;
        }
    }
};
