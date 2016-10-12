public class Solution {
    public int lengthOfLIS(int[] nums) {
	if (nums.length <= 1) {
	    return nums.length;
    }
    int[] sub = new int[nums.length];
    Arrays.fill(sub, 1);
    int maxSequence = 0;
	   
	for (int i = 1; i < nums.length; i++) {
		for (int j = 0; j < i; j++) {
			if ( nums[i] > nums[j] ) {
				sub[i] = Math.max(sub[i], sub[j] + 1);
			}
        }
        maxSequence  = Math.max(maxSequence, sub[i]);
    }
    return maxSequence;
    }
}