class Solution {
public:
    int maxProduct(vector<string>& words) {
        if(words.size() == 0) return 0;
        vector<int> hash(words.size(), 0);
        
        for(int i = 0; i < words.size(); i++){
            for(char c : words[i]){
                hash[i] |= (1 << c - 'a');
            }
        }
        int ans = 0;
        for(int i = 0; i < words.size(); i++){
            for(int j = i + 1; j < words.size(); j++){
                if((hash[i] & hash[j]) == 0) {
                    ans = max(ans, (int)words[i].size() * (int)words[j].size());
                }
            }
        }
        return ans;
    }
};
