class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>count(26);
        deque<bool>used(26);
        string s1 = "";
        for(auto c : s) count[c - 'a']++;
        for(auto c : s){
            count[c - 'a']--;
            if(used[c - 'a']) continue;
            while(s1.length() > 0 && c < s1[s1.length() - 1] && count[s1[s1.length() - 1] - 'a'] > 0){
                used[s1[s1.length() - 1] - 'a'] = false;
                s1.erase(s1.length() - 1);
            }
            s1 += c;
            used[c-'a']=true;
        }
        return s1;
    }
};
