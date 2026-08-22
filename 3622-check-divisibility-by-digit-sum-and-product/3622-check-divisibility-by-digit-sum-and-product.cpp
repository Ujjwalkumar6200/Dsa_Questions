class Solution {
public:
    bool checkDivisibility(int n) {
        int orignaln = n;
        int tempn=n;
        long long sum = 0, product = 1;
        while(tempn>0){
            int last_digit = tempn % 10;
            sum+=last_digit;
            product *= last_digit;
            tempn/= 10;
        } long long divisor = sum + product;
        if(orignaln % divisor == 0) return true;
        else {
            return false;
        }
    }
};