class Solution {
public:
    int getSum(int a, int b) {
        int sum = 0;
        int carry = 0;
        for(int i = 0; i < 32; i++)
        {
            //check if ith bit is set for both a and b;
            int x = (a >> i) & 1;
            int y = (b >> i) & 1;
            
            // get the sum, then add the carry
            int bit = x^y;
            bit ^= carry;
            
            // set the bit for the ith position
            sum |= (bit << i);
            
            // carry is set if both x and y are 1 or 
            // one of then is 1 and carry is also 1;
            carry = ((x&y) | (x^y)&carry);
        }
        return sum;
    }
};
