class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        for(int i = 0; i < nums.size(); i++){  //map<nums,次數>
            if(m.find(nums[i]) == m.end()){
                m[nums[i]] = 0;
            }
            m[nums[i]]++;
        }
        
        vector<int> ans;
        priority_queue<pair<int, int>> pq; // <次數,nums>
        for(std::map<int,int>::iterator it = m.begin(); it != m.end(); ++it){
            pq.push(make_pair(it->second, it->first));
        }
        
        for(int i = 0; i < k; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
