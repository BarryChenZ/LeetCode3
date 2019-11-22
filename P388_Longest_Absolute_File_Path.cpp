class Solution {
public:
    int lengthLongestPath(string input) {
        int maxlen = 0, current = 0, level = 0, dirlen = 0;
        bool file = false;
        vector<int> s;
        for(int i = 0; i <= input.size(); i++){
            if(input[i] == '\n' || i == input.size()){
                if(file){
                    maxlen = max(maxlen, current + dirlen);
                }
                else{
                    s.resize(level);
                    s.push_back(current);
                }
                dirlen = level = current = file = 0;
            }
            else if(input[i] == '\t'){
                dirlen += s[level] + 1;
                //one tab => one level length
                level++;
            }
            else{//not n, not t
                if(input[i] == '.') file = 1;
                current++;
            }
        }
        return maxlen;
    }
};
