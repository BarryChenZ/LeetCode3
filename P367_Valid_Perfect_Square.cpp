class Solution {
public:
    bool isPerfectSquare(int num) {
        long long front = 0, end = num;
        while(front <= end){
            long long mid = (front + end) / 2;
            if(mid * mid == num) return true;
            else if(mid * mid > num){
                end = mid - 1;
            }
            else{
                front = mid + 1;
            }
        }
        return false;
    }
};
