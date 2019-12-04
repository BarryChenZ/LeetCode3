class Solution {
public:
    // ax + by = z;  d = gcd(x,y) && (z & d == 0)
    bool canMeasureWater(int x, int y, int z) {
        return (z == 0 || (x + y >= z && z % gcd(x,y) == 0));
    }
    int gcd(int x, int y){
        return y == 0 ? x : gcd(y, x%y);
    }
};
