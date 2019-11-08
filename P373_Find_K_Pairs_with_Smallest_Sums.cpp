class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        multimap<int , vector<int>> m;
        for(int i = 0; i < min((int)nums1.size(), k); i++){
            for(int j = 0; j < min((int)nums2.size(), k); j++){
                m.insert({nums1[i] + nums2[j], {nums1[i], nums2[j]}});
            }
        }
        vector<vector<int>> res;
        for(auto it = m.begin(); it != m.end(); it++){
            res.push_back(it->second);
            if(res.size() == k) break;
        }
        return res;
    }
};
