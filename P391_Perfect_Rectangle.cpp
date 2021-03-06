class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_set<string> p;
        int x1 = INT_MAX, y1 = INT_MAX, x2 = INT_MIN, y2 = INT_MIN, erea = 0;
        for(auto& e : rectangles){
            x1 = min(x1, e[0]);
            y1 = min(y1, e[1]);
            x2 = max(x2, e[2]);
            y2 = max(y2, e[3]);
            erea += abs(e[0]-e[2])*abs(e[1]-e[3]);
            if(!p.erase(to_string(e[0])+"#"+to_string(e[1]))) p.insert(to_string(e[0])+"#"+to_string(e[1]));
            if(!p.erase(to_string(e[0])+"#"+to_string(e[3]))) p.insert(to_string(e[0])+"#"+to_string(e[3]));
            if(!p.erase(to_string(e[2])+"#"+to_string(e[1]))) p.insert(to_string(e[2])+"#"+to_string(e[1]));
            if(!p.erase(to_string(e[2])+"#"+to_string(e[3]))) p.insert(to_string(e[2])+"#"+to_string(e[3]));
        }
        if(p.size() != 4) return false;
        
        if(p.find(to_string(x1)+"#"+to_string(y1)) == p.end()) return false;
        if(!p.count(to_string(x1)+"#"+to_string(y2))) return false;
        if(!p.count(to_string(x2)+"#"+to_string(y1))) return false;
        if(!p.count(to_string(x2)+"#"+to_string(y2))) return false;
        return abs(x1-x2)*abs(y1-y2) == erea;
    }
};
