class Solution {
public:
    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;
        while(left < right){
            if(isVowels(s[left]) && isVowels(s[right])){
                swap(s[left++],s[right--]);
            }
            else if(isVowels(s[left])){
                right--;
            }
            else{
                left++;
            }
        }
        return s;
    }
    bool isVowels(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};
