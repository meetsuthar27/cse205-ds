import java.util.ArrayList;

class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> subsets = new ArrayList<>();
        genSubsets(1, n, new ArrayList<>(), subsets, k);
        return subsets;
    }

    void genSubsets(int current, int n, List<Integer> currentList, List<List<Integer>> subsets, int k) {
        if (currentList.size() == k) {
            subsets.add(new ArrayList<>(currentList));
            return;
        }

        if (current > n) {
            return;
        }

        // Include
        currentList.add(current);
        genSubsets(current + 1, n, currentList, subsets, k);
        currentList.remove(currentList.size() - 1);

        // Exclude
        genSubsets(current + 1, n, currentList, subsets, k);
    }
}
