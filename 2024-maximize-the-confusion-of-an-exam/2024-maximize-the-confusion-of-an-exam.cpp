class Solution {
public:

    int solve(string &s, char target, int k) {

        int i = 0;
        int cnt = 0;
        int maxi = 0;

        for(int j = 0; j < s.size(); j++) {

            if(s[j] != target) {
                cnt++;
            }

            while(cnt > k) {

                if(s[i] != target) {
                    cnt--;
                }

                i++;
            }

            maxi = max(maxi, j - i + 1);
        }

        return maxi;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {

        int makeT = solve(answerKey, 'T', k);
        int makeF = solve(answerKey, 'F', k);

        return max(makeT, makeF);
    }
};