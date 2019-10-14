class Solution {
public:
    bool isAdditiveNumber(string num) {
        if(num.size() < 3) return false;
        for(int i = 1; i <= num.size() / 2; i++){
            if(num[0] == '0' && i > 1) return false;
            for(int j = 1; j <= (num.size() - i) / 2; j++){
                if(num[i] == '0' && j > 1) break;
                string str1 = num.substr(0, i);
                string str2 = num.substr(i, j);
                if(dfs(num, i+j, str1, str2)) return true;
            }
        }
        return false;
    }
    bool dfs(string &num, int start, string str1, string str2){
        if(start == num.size()) return true;
        long t1 = stol(str1);
        long t2 = stol(str2);
        string str = to_string(t1 + t2);
        if(num.size() - start < str.size()) return false;
        
        for(int i = start, j = 0; j < str.size(); i++, j++){
            if(num[i] != str[j]) return false;
        }
        return dfs(num, start + str.size(), str2, str);
    }
};
