class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = s.size();
        map<char, int> m;
        for(int i = 0; i < n; i++){
            if(m.find(s[i]) == m.end()){
                m[s[i]] = 0;
            }
            m[s[i]]++;
        }
        
        for(int i = 0; i < n; i++){
            if(m.find(s[i]) == m.end()) return t[i];
            m[t[i]]--;
            if(m[t[i]] < 0) return t[i];
        }
        return t[t.size() - 1];
    }
};
//參考
class Solution {
public:
    char findTheDifference(string s, string t) {
        char v = 0;
        for (char c: s) v ^= c;
        for (char c: t) v ^= c;
        return v;
    }
};
