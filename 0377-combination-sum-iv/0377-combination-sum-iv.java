class Solution {
    public int return_Sum(int[] nums, int target,ArrayList<Integer> dp ){
        if(target==0) return 1;
        if(target<0) return 0;

        if(dp.get(target)!=-1) return dp.get(target);
        int ans = 0;
        for(int num : nums){
            ans+= return_Sum(nums,target-num,dp);
        }
        dp.set(target, ans);
        return ans;
    }


    public int combinationSum4(int[] nums, int target) {
        ArrayList<Integer> dp = new ArrayList <> ();
        for(int i =0;i<=target;i++) dp.add(-1);
        return return_Sum(nums,target,dp);
    }
}