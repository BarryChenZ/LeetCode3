struct TrieNode{
    TrieNode* children[26];
    vector<int> indexes;
    int index;
    TrieNode () : index(-1){
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
    } 
};
class Solution {
private:
    TrieNode* root;
    bool isPail(string& s, int i, int j){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        root = new TrieNode();
        int j = 0;
        for(auto word : words){
            TrieNode* cur = root;
            for(int i = word.length() - 1; i >= 0; i--){
                if(isPail(word, 0, i))
                    cur->indexes.push_back(j);
                if(cur->children[word[i] - 'a'] == NULL)
                    cur->children[word[i] - 'a'] = new TrieNode();
                cur = cur->children[word[i] - 'a'];
            }
            cur->index = j;
            cur->indexes.push_back(j);
            j++;
        }
        
        for(int k = 0; k < words.size(); k++){
            TrieNode* cur = root;
            bool done = true;
            for(int i = 0; i < words[k].size(); i++){
                if(cur->index >= 0 && cur->index != k && isPail(words[k], i, words[k].length() - 1)){
                    ans.push_back(vector<int>{k, cur->index});
                }
                cur = cur->children[words[k][i] - 'a'];
                if(cur == NULL){
                    done = false;
                    break;
                }
            }
            if(done){
                for(auto m : cur->indexes){
                    if(m == k)
                        continue;
                    ans.push_back(vector<int>{k, m});       
                }
            }
        }
        return ans;
    }
};
