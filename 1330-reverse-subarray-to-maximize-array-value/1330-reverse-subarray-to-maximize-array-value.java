class Solution {
       public int maxValueAfterReverse(int[] A) {
        int total = 0, res = 0, min2 = 123456, max2 = -123456, n = A.length;
        for (int i = 0; i < n - 1; ++i) {
            int a = A[i], b = A[i + 1];
            total += Math.abs(a - b);
            res = Math.max(res, Math.abs(A[0] - b) - Math.abs(a - b));
            res = Math.max(res, Math.abs(A[n - 1] - a) - Math.abs(a - b));
            min2 = Math.min(min2, Math.max(a, b));
            max2 = Math.max(max2, Math.min(a, b));
        }
        return total + Math.max(res, (max2 - min2) * 2);
       }
    };