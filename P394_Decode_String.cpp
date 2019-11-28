class Solution {
public:
    string decodeString(string s) {
        stack<string> temp_strings;
        stack<int> times;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] <= '9' && s[i] >= '0'){
                int temp_times = 0;
                while(s[i] != '['){
                    temp_times *= 10;
                    temp_times += (s[i] - '0');
                    i++;
                }
                i--;
                times.push(temp_times);
            }
            else if(s[i] == ']'){
                string temp;
                while(temp_strings.top() != "["){
                    temp.insert(0, temp_strings.top());
                    temp_strings.pop();
                }
                temp_strings.pop();
                string temp1;
                int t = times.top();
                cout << t;
                times.pop();
                for(int q = 0; q < t; q++){
                    temp1 += temp;
                }
                temp_strings.push(temp1);
            }
            else{
                string c;
                c += s[i];
                temp_strings.push(c);
            }
        }
        string ans;
        while(!temp_strings.empty()){
            ans.insert(0, temp_strings.top());
            temp_strings.pop();
        }
        return ans;
    }
};
