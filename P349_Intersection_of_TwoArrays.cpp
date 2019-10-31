class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        set<int> s1;
        set<int> s2;
    
        vector<int> ans;
    
        for(int i = 0; i < n; i++) {
            s1.insert(nums1[i]);
        }
        for(int i = 0; i < m; i++) {
            s2.insert(nums2[i]);
        }
    
        auto it1 = s1.begin();
        while(it1 != s1.end()) {
            if(s2.count(*it1) > 0) {
                ans.push_back(*it1);
            }
            it1++;
        }
    
        return ans;
        }
};
