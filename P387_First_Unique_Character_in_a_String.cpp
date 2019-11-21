class Solution {
public:
    int firstUniqChar(string s) {
        map<char, vector<int>> m;
        for(int i = 0; i < s.size(); i++){
            if(m.find(s[i]) == m.end()){
                m[s[i]] = {};    
            }
            m[s[i]].push_back(i);
        }
        
        int result = INT_MAX;
        
        map<char,vector<int>>::iterator it;
        for(it = m.begin(); it != m.end(); it++){
            if(it->second.size() == 1){
                if(it->second[0] < result) result = it->second[0];
            }
        }
        return result == INT_MAX ? -1 : result;
    }
};
