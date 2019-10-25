class Solution {
public:
    vector<string> ans;
    map<string,map<string,int>> mp;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto j : tickets){
            mp[j[0]][j[1]]++;
        }
        dfs("JFK", "");
        reverse(ans.begin(),ans.end());
        return ans;
    }
    void dfs(string next, string parent){
        for(auto v : mp[next]){
            if(mp[next][v.first] > 0){
                mp[next][v.first]--;
                dfs(v.first, next);
            }
        }
        ans.push_back(next);
    }
};
