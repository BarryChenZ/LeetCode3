class Solution {
    typedef pair<int,pair<int, int>> pi;
    priority_queue<pi, vector<pi>, greater<pi> > min_heap;
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int r = matrix.size(), c = matrix[0].size();
        
        min_heap.push(make_pair(matrix[0][0], make_pair(0,0)));
        k = k - 1;
        while(k > 0){
            int tmpi = min_heap.top().second.first;
            int tmpj = min_heap.top().second.second;
            min_heap.pop();
            if(tmpi + 1 < c){
                if(matrix[tmpi + 1][tmpj] != matrix[0][0] - 1)
                min_heap.push(make_pair(matrix[tmpi + 1][tmpj], make_pair(tmpi + 1,tmpj)));
                matrix[tmpi + 1][tmpj] = matrix[0][0] - 1;
            }
            if(tmpj + 1 < r){
                if(matrix[tmpi][tmpj + 1] != matrix[0][0] - 1)
                min_heap.push(make_pair(matrix[tmpi][tmpj + 1], make_pair(tmpi,tmpj + 1)));
                matrix[tmpi][tmpj + 1] = matrix[0][0] - 1;
            }
            k--;
        }
        return min_heap.top().first;
    }
};
