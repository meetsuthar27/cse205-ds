class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        helper(nums, 0, new ArrayList<>(), result);
        return result;
    }
    
    void helper(int[] nums, int index, List<Integer> subset, List<List<Integer>> result) {
        if (index == nums.length) {
            result.add(new ArrayList<>(subset));
            return;
        }
        
        // Exclude
        helper(nums, index + 1, subset, result);
        
        // Include 
        subset.add(nums[index]);
        helper(nums, index + 1, subset, result);
        subset.remove(subset.size() - 1);
    }
}
