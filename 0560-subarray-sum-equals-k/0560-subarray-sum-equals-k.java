class Solution {
    public int subarraySum(int[] nums, int k) {
        int prefix_sum =0;
        HashMap<Integer,Integer> freq = new HashMap<>();
        int maxi =0;
        freq.put(0,1);

        for(int num : nums){
            prefix_sum+=num;
            int rem  = prefix_sum -k;
            if(freq.containsKey(rem)){
                maxi+= freq.get(rem);
            }
            freq.put(prefix_sum,freq.getOrDefault(prefix_sum,0)+1);
        } return maxi;
    }
}