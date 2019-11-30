class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.length() < k) return 0;
        if(k == 1) return s.length();
        
        vector<int> c(26, 0);
        int unique_char = 0;
        //統計
        for(int i = 0; i < s.length(); i++){
            if(c[s[i]-'a'] == 0) unique_char++;
            c[s[i]-'a']++;
        }
        int max_len = 0;
        for(int i = 1; i <= unique_char; i++){
            max_len = max(max_len, longest(s,i,k));
        }
        return max_len;
    }
    int longest(string s, int unique, int k){
        vector<int> c(26, 0);
        int start = 0;
        int end = 0;
        int chars = 0;
        int k_greater = 0;
        int max_len = 0;
        while(end < s.length()){
            if(c[s[end] - 'a'] == 0) chars++;
            c[s[end] - 'a']++;
            if(c[s[end] - 'a'] == k) k_greater++;
            
            while(chars > unique){
                if(c[s[start]-'a'] - 1 == 0) chars--;
                c[s[start]-'a']--;
                if(c[s[start]-'a'] + 1 == k) k_greater--;
                start++;
            }
            //剩餘都符合
            if(unique == chars && k_greater == chars){
                max_len = max(max_len, end - start + 1);
            }
            end++;
        }
        return max_len;
    }
};
