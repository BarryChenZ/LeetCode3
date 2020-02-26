class SummaryRanges {
private:
    map<int, int> intervals;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
            
    }
    
    void addNum(int val) {
        intervals[val]++;
        intervals[val + 1]--;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> gaps;
        int curState = 0, preState, start;
        
        for(auto& i : intervals){
            preState = curState;
            curState += i.second;
            
            if(preState == 0 && curState >= 1){
                start = i.first;    
            }
            if(preState >= 1 && curState == 0){
                gaps.push_back({start, i.first-1});
            }
        }
        return gaps;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
