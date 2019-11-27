class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() > t.size()) return false;
        vector<int> dp(t.size(),0);
        int j = 0;
        for(int i = 0; i < t.size(); i++){
            if(t[i] == s[j]) j++;
            if(j == s.size()) return true;
        }
        if(j == s.size()) return true;
        return false;
    }
};
