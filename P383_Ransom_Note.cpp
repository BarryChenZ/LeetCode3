class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(magazine.size() < ransomNote.size()) return false;
        map<char, int> m;
        
        for(int i = 0; i < ransomNote.size(); i++){
            if(m.find(ransomNote[i]) == m.end()){
                m[ransomNote[i]] = 0;
            }
            m[ransomNote[i]]++;
        }
        
        for(int i = 0; i < magazine.size(); i++){
            if(m.find(magazine[i]) != m.end()){
                m[magazine[i]]--;
            }
        }
        
        map<char, int>::iterator it;
        for(it = m.begin(); it != m.end(); it++){
            if(it->second > 0) return false;
        }
        return true;
    }
};
