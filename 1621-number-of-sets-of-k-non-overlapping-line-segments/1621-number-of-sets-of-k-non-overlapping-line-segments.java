import java.util.*;

class Solution {

    int MOD = 1_000_000_007;

    public int numberOfSets(int n, int k) {

        ArrayList<ArrayList<Integer>> dp = new ArrayList<>();

        // Create n rows
        for (int i = 0; i < n; i++) {
            dp.add(new ArrayList<>());

            // Create k + 1 columns
            for (int j = 0; j <= k; j++) {
                dp.get(i).add(0);
            }
        }

        // Base case
        for (int i = 0; i < n; i++) {
            dp.get(i).set(0, 1);
        }

        // DP
        for (int j = 1; j <= k; j++) {

            int sum = 0;

            for (int i = 1; i < n; i++) {

                sum = (sum + dp.get(i - 1).get(j - 1)) % MOD;

                dp.get(i).set(
                    j,
                    (dp.get(i - 1).get(j) + sum) % MOD
                );
            }
        }

        return dp.get(n - 1).get(k);
    }
}