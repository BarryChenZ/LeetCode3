class Solution {
private:
    struct {
        bool operator()(vector<int> a, vector<int> b) const
        {   
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        }   
    } Rule;
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int ans = 0;
        if(envelopes.size() <= 1) return envelopes.size();
        sort(envelopes.begin(), envelopes.end(), Rule);
        set<int> s;
        for (int i = 0; i < envelopes.size(); ++i) {
            if (s.count(envelopes[i][1])) continue;
            s.insert(envelopes[i][1]);
            auto it = s.upper_bound(envelopes[i][1]);
            if (it != s.end()) {
                s.erase(*it);
            }
        }
        return s.size();

    }
};
