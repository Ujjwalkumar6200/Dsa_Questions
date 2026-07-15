class Solution {
public:

    int findSum(int n,int& evenSum,int& oddSum){
        if(n==0) return 0;
        if(n%2==0) evenSum++;
        else  oddSum++;
        return findSum(n-1,oddSum,evenSum);

    }


    int gcdOfOddEvenSums(int n) {
        int evenSum = 0;
        int oddSum =0;

        findSum(n,evenSum,oddSum);
        return gcd(evenSum,oddSum);
    }
};