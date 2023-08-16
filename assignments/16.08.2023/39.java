import java.util.ArrayList;

class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> combinations = new ArrayList<>();
        findCombinations(candidates, target, 0, new ArrayList<>(), combinations);
        return combinations;
    }

    void findCombinations(int[] candidates, int target, int i, List<Integer> currentCombination,
            List<List<Integer>> combinations) {
        if (target == 0) {
            combinations.add(new ArrayList<>(currentCombination));
            return;
        }

        if (target < 0 || i >= candidates.length) {
            return;
        }

        // Include
        currentCombination.add(candidates[i]);
        findCombinations(candidates, target - candidates[i], i, currentCombination, combinations);
        currentCombination.remove(currentCombination.size() - 1);

        findCombinations(candidates, target, i + 1, currentCombination, combinations);
    }
}
